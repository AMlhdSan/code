#include <bits/stdc++.h>

#define N 1001
#define MOD 19650827

using namespace std;

int a[N];
int n;
int dp[N][N][3]; // i - j的方案总数

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        dp[i][i][1] = 1;
    }
    
    for(int l = 1; l <= n; ++l) {
        for(int i = 1; i + l <= n; ++i) {
            int j = i + l;
            if(a[i] < a[i + 1]) {
                dp[i][j][1] += dp[i + 1][j][1];
            }
            if(a[i] < a[j]) {
                dp[i][j][1] += dp[i + 1][j][2];
            }
            if(a[j] > a[j - 1]) {
                dp[i][j][2] += dp[i][j - 1][2];
            }
            if(a[j] > a[i]) {
                dp[i][j][2] += dp[i][j - 1][1];
            }
            dp[i][j][1] %= MOD;
            dp[i][j][2] %= MOD;
        }
    }

    cout << (dp[1][n][1] + dp[1][n][2]) % MOD << endl;

    return 0;
}