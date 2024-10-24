#include <bits/stdc++.h>

#define N 1001
#define M 100001
#define MOD 100003

using namespace std;

int dp[N][N];
bool flag[N][N];
int n, m;
int x, y;

int main() {

    cin >> n >> m;

    memset(dp, 0, sizeof(dp));

    memset(flag, false, sizeof(flag));

    for(int i = 1; i <= m; ++i) {
        cin >> x >> y;
        flag[x][y] = 1;
    }

    dp[1][1] = 1;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
            if(flag[i][j]) {
                dp[i][j] = 0;
            }
            dp[i][j] %= MOD;
        }
    }

    cout << dp[n][n] % MOD << endl;

    return 0;
}