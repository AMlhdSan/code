#include <bits/stdc++.h>

#define N 1001
#define M 1001

using namespace std;

int n, m, x;

int a[N], b[N], c[N];

int dp[N][M]; // 前i能力j钱

int main() {

    cin >> n >> m >> x;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = m; j >= b[i]; --j) {
            for(int k = x; k >= c[i]; --k) {
                dp[j][k] = max(dp[j][k], dp[j - b[i]][k - c[i]] + a[i]);
            }
        }
    }

    cout << dp[m][x];

    return 0;
}