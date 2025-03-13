#include <bits/stdc++.h>

#define N 1000010
#define ll long long

using namespace std;

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

int n, m;
vector<int> e;
vector<int> dp;
const int INF = -1e18;

int main() {
    // freopen("game.in", "r", stdin);
    // freopen("game.out", "w", stdout);
    n = read();
    m = read();
    
    e.resize(n);
    for (int i = 0; i < n; i++) {
        e[i] = read();
    }
    
    dp.resize(m + 1, INF);
    dp[0] = 0;
    int uc = 0;
    
    for (int i = 0; i < n; i++) {
        if (e[i] == 0) {
            int nuc = uc + 1;
            vector<int> ndp(m + 1, INF);
            for (int x = 0; x <= uc; x++) {
                if (dp[x] == INF) continue;
                ndp[x] = max(ndp[x], dp[x]);
                ndp[x + 1] = max(ndp[x + 1], dp[x]);
            }
            dp = ndp;
            uc = nuc;
        } else {
            vector<int> ndp(m + 1, INF);
            int ev = e[i];
            for (int x = 0; x <= uc; x++) {
                if (dp[x] == INF) continue;
                int s = x;
                int it = uc - x;
                int add = 0;
                
                if (ev > 0) {
                    if (it >= ev) add = 1;
                } else {
                    if (s >= -ev) add = 1;
                }
                
                ndp[x] = max(ndp[x], dp[x] + add);
            }
            dp = ndp;
        }
    }
    
    int ans = 0;
    for (int x = 0; x <= m; x++) {
        ans = max(ans, dp[x]);
    }
    
    writeln(ans);
    return 0;
}