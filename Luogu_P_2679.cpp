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
                if(s[i] == s[j]) {
                    dp[i][j][k][t][0] = 
                }
            }
        }
    }

    return 0;
}