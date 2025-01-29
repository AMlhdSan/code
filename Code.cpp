#include <iostream>
#include <string>
using namespace std;

// 检查子串是否满足条件
bool isGoodNumber(const string& sub) {
    int n = sub.size();
    // 枚举分割点
    for (int len1 = 1; len1 <= n / 3; ++len1) { // 第一段长度
        for (int len3 = 1; len3 <= (n - 3 * len1) / 2; ++len3) { // 第三段长度
            int len2 = len1, len5 = len1, len6 = len3;
            // if (3 * len1 + 2 * len3 != n) continue;
            string part1 = sub.substr(0, len1);
            string part2 = sub.substr(len1, len2);
            string part3 = sub.substr(len1 + len2, len3);
            string part5 = sub.substr(len1 + len2 + len3, len5);
            string part6 = sub.substr(len1 + len2 + len3 + len5, len6);
            if (part1 == part2 && part1 == part5 && part3 == part6) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T; // 读取测试数据组数
    while (T--) {
        string s;
        cin >> s; // 读取当前字符串
        int n = s.size();
        int count = 0;


        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                string sub = s.substr(i, j - i);
                if (isGoodNumber(sub)) {
                    ++count;
                }
            }
        }

        cout << count << endl; // 输出答案
    }

    return 0;
}
