#include <bits/stdc++.h>

#define NN 101
#define MM 201
#define TT 201

using namespace std;

int n, M, T;
int m[NN], t[NN];
int dp[MM][TT];

int main() {

    cin >> n >> M >> T;

    for(int i = 1; i <= n; ++i) {
        cin >> m[i] >> t[i];
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = M; j >= m[i]; --j) {
            for(int k = T; k >= t[i]; --k) {
                dp[j][k] = max(dp[j][k], dp[j - m[i]][k - t[i]] + 1);
            }
        }
    }
    cout << dp[M][T] << endl;

    return 0;
}