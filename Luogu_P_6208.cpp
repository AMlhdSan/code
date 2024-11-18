#include <bits/stdc++.h>

#define N 1001

using namespace std;

int r, c;
int dp[N][N];
int a[N][N];

int main() {

    cin >> r >> c;

    for(int i = 1; i <= r; ++i) {
        for(int j = 1; j <= c; ++j) {
            cin >> a[i][j];
        }
    }

    for(int j = 1; j <= c; ++j) {
        dp[1][j] = a[1][j];
    }

    for(int j = 2; j <= c; ++j) {
        for(int i = 1; i <= r && i <= j; ++i) {
            dp[i][j] = max(dp[i - 1][j - 1], max(dp[i][j - 1], dp[i + 1][j - 1])) + a[i][j];
        }
    }

    cout << dp[r][c] << endl;

    return 0;
}