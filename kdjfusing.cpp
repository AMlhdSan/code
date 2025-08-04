#include <bits/stdc++.h>

#define N 2005
#define ll long long
#define MOD 998244353

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

int n;
vector<int> ch[N];
int siz[N];
ll f[N][N];
ll fac[N], inv[N];

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init() {
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = fac[i-1] * i % MOD;
    }
    inv[n] = qpow(fac[n], MOD - 2);
    for (int i = n - 1; i >= 0; --i) {
        inv[i] = inv[i+1] * (i+1) % MOD;
    }
}

ll C(int n, int m) {
    if (m < 0 || m > n) return 0;
    return fac[n] * inv[m] % MOD * inv[n-m] % MOD;
}

void dfs(int u) {
    siz[u] = 1;
    f[u][1] = 1;
    
    for (int v : ch[u]) {
        dfs(v);
        
        for (int i = siz[u] + siz[v]; i >= 1; --i) {
            ll sum = 0;
            for (int j = 1; j <= min(i - 1, siz[u]); ++j) {
                if (i - j <= siz[v]) {
                    sum = (sum + f[u][j] * f[v][i - j] % MOD * C(i - 1, j - 1)) % MOD;
                }
            }
            f[u][i] = sum;
        }
        siz[u] += siz[v];
    }
}

int main() {
    n = read();
    
    for (int i = 2; i <= n; ++i) {
        int fa = read();
        ch[fa].push_back(i);
    }
    
    init();
    dfs(1);
    
    for (int i = 1; i <= n; ++i) {
        write(f[1][i]);
        if (i < n) putchar(' ');
    }
    putchar('\n');
    
    return 0;
}