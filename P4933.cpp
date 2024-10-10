#include <bits/stdc++.h>

#define MOD 998244353
#define N 1001
#define M 20001

using namespace std;

int dp[N][N]; // 以 j 为结尾的，i 为前继的最长等差数列长度
int n;
int h[N];

int main() {

    memset(dp, 0, sizeof(dp));

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> h[i];
    }

    long long ans = n;

    for(int i = 1; i < n; ++i) {
        for(int j = i + 1; j <= n; ++j) {
            dp[i][j] = 1;
            for(int k = 1; k <= i - 1; ++k) {
                if(h[i] - h[k] == h[j] - h[i]) {
                    dp[i][j] += dp[k][i];
                    dp[i][j] %= MOD;
                }
            }
            ans += dp[i][j];
            ans %= MOD;
        }
    }

    cout << ans << endl;

    return 0;
}