#include <bits/stdc++.h>
#define N 20
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

int n;
ll x[N], y[N], z[N], d[N][N], dp[1 << 17][N];

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

inline void write(ll x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(ll x) {
    write(x);
    putchar('\n');
}

int main() {
    n = read();
    for(int i = 0; i < n; i++) {
        x[i] = read();
        y[i] = read();
        z[i] = read();
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            d[i][j] = abs(x[j] - x[i]) + abs(y[j] - y[i]) + max(0ll, z[j] - z[i]);
        }
    }
    for(int i = 0; i < (1 << n); i++) {
        for(int j = 0; j < n; j++) {
            dp[i][j] = INF;
        }
    }
    dp[1][0] = 0;
    
    for(int S = 0; S < (1 << n); S++) {
        if(!(S & 1)) continue;
        for(int i = 0; i < n; i++) {
            if(!(S >> i & 1)) continue;
            for(int j = 0; j < n; j++) {
                if(S >> j & 1) continue;
                dp[S | (1 << j)][j] = min(dp[S | (1 << j)][j], dp[S][i] + d[i][j]);
            }
        }
    }
    
    ll ans = INF;
    for(int i = 1; i < n; i++) {
        ans = min(ans, dp[(1 << n) - 1][i] + d[i][0]);
    }
    writeln(ans);
    return 0;
}