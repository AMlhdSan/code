#include <bits/stdc++.h>

#define N 1000007
#define ll long long
#define inf 1000000000

using namespace std;

int n, m, dp[N], ans;

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

int main() {
    // freopen("game.in", "r", stdin);
    // freopen("game.out", "w", stdout);

    n = read();
    m = read();
    dp[1] = -inf;
    
    for (int i = 1, a, c = 0; i <= n; i++) {
        a = read();
        if (a == 0) {
            for (int j = 1; j <= m; j++) dp[j] += dp[j - 1];
            for (int j = m; j >= 1; j--) dp[j] = max(dp[j], dp[j - 1]);
            for (int j = m; j >= 1; j--) dp[j] -= dp[j - 1];
            c++;
        } else if (a > 0) {
            dp[a]++;
        } else {
            if (-a <= c) {
                dp[0]++;
                dp[c + a + 1]--;
            }
        }
    }
    
    for (int j = 1; j <= m; j++) dp[j] += dp[j - 1];
    for (int j = 0; j <= m; j++) ans = max(ans, dp[j]);
    
    writeln(ans);
    
    return 0;
}