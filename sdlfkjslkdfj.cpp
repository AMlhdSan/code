#include <bits/stdc++.h>
#define N 100010
#define int long long
#define MOD 1000000007
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
int n, l, r, a[N];
signed main() {
    // freopen("Mod.in", "r", stdin);
    // freopen("Mod.out", "w", stdout);
    n = read();
    l = read();
    r = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    int P = a[1];
    vector<int> F(P), S(P + 1, 0);
    for (int x = 0; x < P; ++x) {
        int y = x;
        for (int i = 2; i <= n; ++i) {
            y %= a[i];
        }
        F[x] = y % MOD;
    }
    for (int i = 0; i < P; ++i) {
        S[i + 1] = (S[i] + F[i]) % MOD;
    }
    int tot = r - l + 1, cyc = tot / P, rem = tot % P, st = l % P;
    int ans = (cyc % MOD) * (S[P] % MOD) % MOD;
    if (st + rem <= P) ans = (ans + (S[st + rem] - S[st] + MOD) % MOD) % MOD;
    else ans = (ans + ((S[P] - S[st] + S[st + rem - P]) % MOD + MOD) % MOD) % MOD;
    writeln(ans);
    return 0;
}
