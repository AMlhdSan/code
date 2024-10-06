#include <bits/stdc++.h>

#define N 101

using namespace std;

int dp[N << 1][N << 1];
int a[N];
int f[N << 1];
int n;
int sum[N << 1];

int main() {

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        f[i] = f[i + n] = a[i];
    }

    for(int i = 1; i <= n << 1; ++i) {
        sum[i] = sum[i - 1] + f[i];
    }

    memset(dp, 0, sizeof(dp));

    for(int l = 2; l <= n; ++l) {
        for(int i = 1; i <= (n << 1) - l + 1; ++i) {
            int j = i + l - 1;
            dp[i][j] = 0x7fffffff;
            for(int k = i; k <= j - 1; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
            }
        }
    }

    int minn = 0x7fffffff;

    for(int i = 1; i <= n; ++i) {
        minn = min(minn, dp[i][i + n - 1]);
    }

    cout << minn << endl;

    memset(dp, 0, sizeof(dp));

    for(int l = 2; l <= n; ++l) {
        for(int i = 1; i <= (n << 1) - l + 1; ++i) {
            int j = i + l - 1;
            for(int k = i; k <= j - 1; ++k) {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
            }
        }
    }

    int maxx = -0x7fffffff;

    for(int i = 1; i <= n; ++i) {
        maxx = max(maxx, dp[i][i + n - 1]);
    }

    cout << maxx << endl;

    return 0;
}