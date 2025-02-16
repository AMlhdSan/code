#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

ll gcd(ll x, ll y) {
    while (y) x %= y, swap(x, y);
    return x;
}

const int N = 1e5 + 10;
ll a[N], ans, n;
bool vis[N];

inline void bz(int t) {
    cin >> t;
    while(t--) {
        
    }
}

void dfs(int x) {
    if (x == n + 1) {
        ll g1 = 0, g2 = 0, cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) g1 = gcd(g1, a[i]), cnt++;
            else g2 = gcd(g2, a[i]);
        }
        if (g1 > 1 && g2 > 1) ans = min(ans, abs(cnt - (n - cnt)));
        return;
    }
    dfs(x + 1);
    vis[x] = 1, dfs(x + 1), vis[x] = 0;
}

int main() {
    // freopen("GCD.in", "r", stdin);
    // freopen("GCD.out", "w", stdout);

    n = read();
    if (n > 20) return puts("-1"), 0;

    for (int i = 1; i <= n; i++) a[i] = read();

    ans = 1e18;
    dfs(1);
    writeln(ans == 1e18 ? -1 : ans);
}
