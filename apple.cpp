#include <bits/stdc++.h>
using namespace std;

#define MAXN 1500010
#define int unsigned long long

typedef unsigned long long ll;

int n;
ll m;
int a[MAXN];
ll A[MAXN], P[MAXN * 2], Q[MAXN * 2];

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

signed main() {

    // freopen("apple.in", "r", stdin);
    // freopen("apple.out", "w", stdout);
    n = read();
    m = read();

    for (int i = 1; i <= n; i++){
        a[i] = read();
    }

    int N = 2 * n;
    for (int i = 1; i <= N; i++){
        A[i] = a[(i - 1) % n + 1];
    }

    for (int i = 1; i <= N; i++){
        P[i] = P[i - 1] + A[i];
        Q[i] = Q[i - 1] + A[i] * (A[i] + 1LL) / 2LL;
    }

    ll ans = 0;
    int L = 1;
    for (int R = 1; R <= N; R++){
        while (L < R && L <= n && (P[R] - P[L - 1] >= m)) {
            ll tot = P[R] - P[L - 1];
            ll extra = tot - m;
            ll removed = extra * (extra + 1LL) / 2LL;
            ll cur = (Q[R] - Q[L - 1]) - removed;
            ans = max(ans, cur);
            L++;
        }
    }

    writeln(ans);
    return 0;
}
