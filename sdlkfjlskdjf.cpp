#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define INF INT_MAX

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    // dp[i][j][k]表示到达(i,j)的最小代价，k是i行的左移次数
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, INF)));
    dp[0][0][0] = grid[0][0];

    // DP计算
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < m; ++k) {
                // 对当前格子进行循环左移
                int new_val = grid[i][(j + k) % m];
                if (i + 1 < n) dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k] + new_val); // 向下
                if (j + 1 < m) dp[i][j + 1][k] = min(dp[i][j + 1][k], dp[i][j][k] + new_val); // 向右
            }
        }
    }

    // 求出最小代价
    int ans = INF;
    for (int k = 0; k < m; ++k) {
        ans = min(ans, dp[n-1][m-1][k] + k * x);
    }
    
    cout << ans << endl;

    return 0;
}
