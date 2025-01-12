#include <bits/stdc++.h>

#define gc getchar
#define ls (p << 1)
#define rs (p << 1 | 1)

#define ll long long
#define mod 998244353
#define maxn 200010

inline ll read() {
    ll x = 0;
    char c = getchar(), f = 1;
    for (; c < '0' || '9' < c; c = getchar()) 
        if (c == '-') f = -1;
    for (; '0' <= c && c <= '9'; c = getchar()) 
        x = x * 10 + c - '0';
    return x * f;
}

inline void write(ll x) {
    static char buf[20], len; len = 0;
    if (x < 0) x = -x, putchar('-');
    for (; x; x /= 10) buf[len++] = x % 10 + '0';
    if (!len) putchar('0');
    else while (len) putchar(buf[--len]);
}

inline void writesp(ll x) { write(x); putchar(' '); }
inline void writeln(ll x) { write(x); putchar('\n'); }

struct Data {
    int x, id;
} num[maxn];

struct Point {
    int x, y, rk;
} a[maxn];

int n;

bool cmp1(Data a, Data b) { return a.x < b.x; }
bool cmp2(Point a, Point b) { return a.x < b.x; }

inline ll power(ll a, ll b) {
    ll ans = 1;
    for (; b; b >>= 1, a = a * a % mod)
        if (b & 1) ans = ans * a % mod;
    return ans;
}

int bit1[maxn], bit2[maxn];

void add1(int x, int k) {
    for (; x <= n; x += x & (-x)) bit1[x] += k;
}

int getsum1(int x) {
    int sum = 0;
    for (; x; x -= x & (-x)) sum += bit1[x];
    return sum;
}

void add2(int x, int k) {
    for (; x <= n; x += x & (-x)) bit2[x] += k;
}

int getsum2(int x) {
    int sum = 0;
    for (; x; x -= x & (-x)) sum += bit2[x];
    return sum;
}

int main() {

    freopen("assign.in", "r", stdin);
    freopen("assign.out", "w", stdout);

    n = read();
    for (int i = 1; i <= n; i++) {
        a[i].x = read();
        a[i].y = read();
        num[i].x = a[i].y; 
        num[i].id = i;
    }
    std::sort(num + 1, num + n + 1, cmp1);
    for (int i = 1; i <= n; i++) a[num[i].id].rk = i;
    std::sort(a + 1, a + n + 1, cmp2);

    for (int i = 1; i <= n; i++) {
        bit1[i] = 0;
        bit2[i] = i & (-i);
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        add2(a[i].rk, -1);
        int A = getsum1(a[i].rk);
        int B = getsum1(n) - getsum1(a[i].rk);
        int C = getsum2(a[i].rk);
        int D = getsum2(n) - getsum2(a[i].rk);

        ll totA = power(2, A);
        ll totB = power(2, B);
        ll totC = power(2, C);
        ll totD = power(2, D);

        ans = (ans + (totA - 1) * totB % mod * totC % mod * (totD - 1)) % mod;
        ans = (ans + totA * (totB - 1) % mod * (totC - 1) % mod * totD) % mod;
        ans = (ans - (totA - 1) * (totB - 1) % mod * (totC - 1) % mod * (totD - 1) % mod + mod) % mod;
        ans = (ans + power(2, n - 1)) % mod;

        add1(a[i].rk, 1);
    }

    writeln(ans);
    return 0;
}
