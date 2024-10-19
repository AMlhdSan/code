#include <bits/stdc++.h>

#define N 2001

using namespace std;

int v[N];
int n;
int dp[N][N];

int main() {

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> v[i];
        dp[i][i] = v[i] * n;
    }
    
    for(int l = 1; l <= n; ++l) {
        for(int i = 1; i + l - 1 <= n; ++i) {
            int j = i + l - 1;
            dp[i][j] = max(dp[i][j - 1] + v[j] * (n - l + 1), dp[i + 1][j] + v[i] * (n - l + 1));
        }
    }

    cout << dp[1][n];

    return 0;
}