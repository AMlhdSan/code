#include <iostream>
#include <set>
#include <limits>
using namespace std;

// 定义 Item 结构体
struct Item {
    int a, b;

    // 按 max(a, b) 排序，若相等按 a 排序
    bool operator<(const Item& other) const {
        int max_self = max(a, b);
        int max_other = max(other.a, other.b);
        if (max_self == max_other) return a < other.a; // 次级比较规则
        return max_self < max_other;
    }
};

// 全局变量
int T;
multiset<Item> L, C; // 使用 multiset 按 max(a, b) 排序
int current_min = INT_MAX;

// 更新全局最优值
void update_min() {
    if (L.empty() || C.empty()) {
        current_min = -1; // 无法计算最优值
        return;
    }

    // 获取 L 和 C 中 max(a, b) 最小的元素
    const auto& x = *L.begin();
    const auto& y = *C.begin();

    // 计算当前最优值
    current_min = max(x.a + y.a, x.b + y.b);
}

// 主程序
int main() {
    // 优化输入输出
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 读取测试组数
    cin >> T;

    while (T--) {
        int opt, d, a, b;
        cin >> opt >> d >> a >> b;

        // 插入操作
        if (opt == 1) {
            if (d == 0) L.insert({a, b});
            else C.insert({a, b});
        }
        // 删除操作
        else {
            auto& target = (d == 0) ? L : C;
            auto it = target.find({a, b});
            if (it != target.end()) {
                target.erase(it);
            }
        }

        // 更新最优值
        update_min();
        cout << current_min << endl;
    }

    return 0;
}
