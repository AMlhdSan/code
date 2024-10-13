#include <bits/stdc++.h>

#define N 501

using namespace std;

int dp[N][N];
int a[N];
int n;

int main() {

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    memset(dp, 0x3f, sizeof(dp));

    for(int i = 1; i <= n; ++i) {
        dp[i][i] = 1;
    }

    for(int i = 1; i <= n; ++i) {
        dp[i][i - 1] = 1;
    }

    for(int l = 1; l <= n; ++l) {
        for(int i = 1; i + l <= n; ++i) {
            int j = i + l;
            if(a[i] == a[j]) {
                dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
            }
            for(int k = i; k <= j - 1; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
    }
    cout << dp[1][n] << endl;

    return 0;
}