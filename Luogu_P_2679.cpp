#include <bits/stdc++.h>

#define MOD 1000000007
#define N 1001
#define M 201
#define K 201

using namespace std;

int n, m, k;
string s, t;
int dp[N][N][K][2];

int main() {

    cin >> n >> m >> k;

    cin >> s >> t;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            for(int t = 1; t <= k; ++t) {
                if(s[i - 1] == t[j - 1]) {
                    dp[i][j][t][0] = dp[i - 1][j - 1][t - 1][0] + 1;
                    dp[i][j][t][1] = dp[i - 1][j - 1][t][1];
                }
                else {
                    dp[i][j][t][0] = dp[i - 1][j][t - 1][0];
                    dp[i][j][t][1] = dp[i - 1][j][t][1];
                }
            }
        }
    }

    return 0;
}