#include <bits/stdc++.h>

#define N 2001
#define MOD 100000000

using namespace std;

int dp[N][N]; // 前 i 头奶牛,余数为 j 的种数
int n, f;
int a[N];

int main() {

    cin >> n >> f;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] %= f;
        dp[i][a[i]] = 1;
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < f; ++j) {
            dp[i][j] =((dp[i][j] + dp[i - 1][j]) % MOD + dp[i - 1][(j - a[i] + f) % f]) % MOD;
        }
    }

    cout << dp[n][0] << endl;

    return 0;
}