#include <bits/stdc++.h>

#define N 250

using namespace std;

int n;
int a[N];
int dp[N][N];

int main() {

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> dp[i][i];
    }

    for(int l = 2; l <= n; ++l) {
        for(int i = 1; i <= n - l + 1; ++i) {
            int j = l + i - 1;
            for(int k = i; k <= j - 1; ++k) {
                if(dp[i][k] == dp[k + 1][j] && dp[i][k] > 0) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + 1);
                }
            }
        }
    }

    int maxx = -0x7fffffff;

    for(int i = 1; i <= n; ++i) {
        for(int j = i; j <= n; ++j) {
            maxx = max(maxx, dp[i][j]);
        }
    }

    cout << maxx << endl;

    return 0;
}