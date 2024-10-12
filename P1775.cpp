#include <bits/stdc++.h>

#define N 301

using namespace std;

int dp[N][N];
int a[N];
int f[N];
int n;
int sum[N];

int main() {

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        f[i] = a[i];
    }

    for(int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + f[i];
    }

    memset(dp, 0, sizeof(dp));

    for(int l = 2; l <= n; ++l) {
        for(int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            dp[i][j] = 0x7fffffff;
            for(int k = i; k <= j - 1; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
            }
        }
    }

    cout << dp[1][n] << endl;

    return 0;
}