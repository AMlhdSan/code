#include <bits/stdc++.h>
#define N 2001
using namespace std;

int T;
int n, m;
int grid[2][N];
int dp[N][N][2];  // dp[i][j][0]: 不交换第i列时最大黑白差, dp[i][j][1]: 交换第i列时的最大黑白差

int main() {
    cin >> T;

    while (T--) {
        cin >> n >> m;

        // 读取两行的网格颜色
        for (int i = 1; i <= n; ++i) {
            char ch;
            cin >> ch;
            grid[0][i] = ch - '0';  // 第一行
        }
        for (int i = 1; i <= n; ++i) {
            char ch;
            cin >> ch;
            grid[1][i] = ch - '0';  // 第二行
        }

        // 初始化dp数组
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN));  // 最多可以交换m次
        dp[0][0][0] = 0;  // 初始状态

        for (int i = 1; i <= n; ++i) {
            int noSwapDiff = (grid[0][i] + grid[1][i]) - (2 - (grid[0][i] + grid[1][i]));  // 不交换时的黑白差
            int swapDiff = (2 - (grid[0][i] + grid[1][i])) - noSwapDiff;  // 交换后的黑白差

            // 逐步计算在前 i 列的基础上，最多交换 j 次的情况
            for (int j = 0; j <= m; ++j) {
                // 不交换第 i 列
                dp[i][j] = max(dp[i][j], dp[i-1][j] + noSwapDiff);

                // 交换第 i 列（前提是 j > 0，即至少有一次交换机会）
                if (j > 0) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + swapDiff);
                }
            }
        }

        // 找出最多可以交换 m 次后的最大黑白差值
        int maxBlackWhiteDiff = INT_MIN;
        for (int j = 0; j <= m; ++j) {
            maxBlackWhiteDiff = max(maxBlackWhiteDiff, dp[n][j]);
        }

        // 输出结果
        cout << maxBlackWhiteDiff << endl;
    }

    return 0;
}
