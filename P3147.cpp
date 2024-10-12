#include <bits/stdc++.h>

#define N 262145

using namespace std;

int n;
int t;
int dp[60][N];

int main() {

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> t;
        dp[t][i] = i + 1;
    }

    int maxx = 0;

    for(int i = 2; i <= 58; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(!dp[i][j]) {
                dp[i][j] = dp[i - 1][dp[i - 1][j]];
            }
            if(dp[i][j]) {
                maxx = i;
            }
        }
    }

    cout << maxx << endl;

    return 0;
}