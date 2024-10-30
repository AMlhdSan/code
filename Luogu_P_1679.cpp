#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int min_fourth_powers(int m) {
    // 预计算所有小于等于 m 的四次方数
    vector<int> fourth_powers;
    int i = 1;
    while (i * i * i * i <= m) {
        fourth_powers.push_back(i * i * i * i);
        i++;
    }

    // 动态规划数组，初始化为无穷大，表示尚未找到答案
    vector<int> dp(m + 1, INT_MAX);
    dp[0] = 0;  // 0 的最小和为 0 个数

    // 进行状态转移
    for (int power : fourth_powers) {
        for (int j = power; j <= m; ++j) {
            if (dp[j - power] != INT_MAX) {
                dp[j] = min(dp[j], dp[j - power] + 1);
            }
        }
    }

    return dp[m];
}

int main() {
    int m;
    cin >> m;
    cout << min_fourth_powers(m) << endl;
    return 0;
}
