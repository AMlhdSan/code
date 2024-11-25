#include <bits/stdc++.h>

#define N 110

using namespace std;

int n;
int dp[N][N];
int maxx = 1;

int main() {

    // freopen("ice.in", "r", stdin);
    // freopen("ice.out", "w", stdout);

    cin >> n;

    // if(n == 1) {
    //     cout << 1 << endl;
    //     return 0;
    // }

    for(int i = 1; i <= n; ++i) {
        dp[1][i] = dp[i][1] = 1;
    }

    for(int i = 2; i <= n; ++i) {
        for(int j = 2; j <= n; ++i) {
            dp[i][j] = (dp[i - 1][j] * 2 + dp[i][j - 1]) * 2 / 3;
            maxx = max(maxx, dp[i][j]);
        }
    }

    cout << maxx << endl;

    return 0;
}