#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 1000000007
#define N 1000000

inline int read() {
    int x = 0, dp = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') dp = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * dp;
}

inline void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(int x) {
    write(x);
    putchar('\n');
}

int poww(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = 1ll * res * x % MOD;
        x = 1ll * x * x % MOD;
        y >>= 1;
    }
    return res;
}

int T, n, a[2], dp[N + 5][2];

inline void solve() {
    memset(dp, 0, sizeof(dp));
    n = read();
    a[0] = read();
    a[1] = read();
    dp[0][0] = dp[0][1] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int k = 0; k < 2; ++k) {
            dp[i][k] = (1ll * dp[i - 1][!k] - (i - a[k] < 0 ? 0 : dp[i - a[k]][!k]) + MOD) % MOD;
            dp[i][k] = (1ll * dp[i][k] + dp[i - 1][k]) % MOD;
        }
    }
    int res = 0;
    for (int k = 0; k < 2; ++k) 
        res = (1ll * res + dp[n][k] - dp[n - 1][k] + MOD) % MOD;
    writeln((1ll * poww(2, n) - res + MOD) % MOD);
}

signed main() {

    // freopen("Number.in", "r", stdin);
    // freopen("Number.out", "w", stdout);

    T = read();
    while (T--) {
        solve();
    }
    return 0;
}
