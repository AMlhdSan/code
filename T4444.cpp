#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(n), c(n);
    vector<vector<int>> neighbors(n);  // 邻居列表，用于存储每个点的邻居

    // 输入图的边关系
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        neighbors[i].push_back(i);    // 自己是邻居
        neighbors[a[i]].push_back(i); // 双向连接
        neighbors[i].push_back(a[i]);
    }

    // 输入点的权值b
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    // 计算所有点的权值c
    auto compute_weights = [&]() {
        c.assign(n, 0);  // 重置权值
        for (int x = 0; x < n; ++x) {
            int d = neighbors[x].size();  // 点x的邻居数
            int base = b[x] / d;  // 分配给每个邻居的基础权值
            int remainder = b[x] - base * (d - 1); // 剩余的权值分配给自己

            // 给邻居分配权值
            for (int y : neighbors[x]) {
                if(y != x) {
                    c[y] += base;  // 给其他邻居分配基础权值
                }
            }
        }
    };

    // 初始计算权值
    compute_weights();

    // 处理操作
    for (int i = 0; i < m; ++i) {
        int op;
        cin >> op;

        if (op == 1) {
            // 操作类型 1: 修改边
            int x, y;
            cin >> x >> y;
            x--; y--;  // 转换为0-based索引

            // 删除旧的边
            for (auto it = neighbors[x].begin(); it != neighbors[x].end(); ++it) {
                if (*it == a[x]) {
                    neighbors[x].erase(it);
                    break;
                }
            }
            for (auto it = neighbors[a[x]].begin(); it != neighbors[a[x]].end(); ++it) {
                if (*it == x) {
                    neighbors[a[x]].erase(it);
                    break;
                }
            }

            // 添加新的边
            a[x] = y;
            neighbors[x].push_back(y);
            neighbors[y].push_back(x);

            // 更新所有点的权值
            compute_weights();

        } else if (op == 2) {
            // 操作类型 2: 查询某点的权值
            int x;
            cin >> x;
            x--;  // 转换为0-based索引
            cout << c[x] << endl;

        } else if (op == 3) {
            // 操作类型 3: 查询最小值和最大值
            int min_val = INT_MAX, max_val = INT_MIN;
            for (int val : c) {
                min_val = min(min_val, val);
                max_val = max(max_val, val);
            }
            cout << min_val << " " << max_val << endl;
        }
    }

    return 0;
}
