#include <bits/stdc++.h>

#define N 101

using namespace std;

int n, s;
int a[N];
int c[N];
int dp[N][N][2];
int sum[N];

int cal(int i, int j, int l, int r) {
    return (a[j] - a[i]) * (sum[l] + sum[n] - sum[r - 1]);
}

int main() {

    ios::sync_with_stdio(false);

    memset(dp, 0x3f, sizeof(dp));

    cin >> n >> s;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i] >> c[i];
    }

    for(int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + c[i];
    }

    dp[s][s][0] = 0;
    dp[s][s][1] = 1;

    for(int j = s; j <= n; ++j) {
        for(int i = j - 1; i > 0; --i) {
            dp[i][j][0] = min(dp[i + 1][j][0] + cal(i, i + 1, i, j + 1), dp[i + 1][j][1] + cal(i, j, i, j + 1));
            dp[i][j][1] = min(dp[i][j - 1][1] + cal(j - 1, j, i - 1, j), dp[i][j - 1][0] + cal(i, j, i - 1, j)); 
        }
    }
    cout << min(dp[1][n][0], dp[1][n][1]) << endl;
    
    return 0;
}