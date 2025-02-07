#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int T, n, a[maxn], b[maxn];
int id1[maxn], id2[maxn];
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
inline void write(int x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}
inline void writeln(int x) {
    write(x);
    putchar('\n');
}
inline bool check(int x) {
    int now = 1;
    for (int i = 1; i <= n; ++i)
        if (a[id1[i]] < x) {
            while (now <= n && (a[id2[now]] < x || a[id2[now]] + b[id2[now]] - b[id1[i]] < x)) ++now;
            if (now > n)
                return false;
            ++now;
        }
    return true;
}
inline void solve() {
    n = read();
    for (int i = 1; i <= n; ++i) 
        a[i] = read(), b[i] = read();
    for (int i = 1; i <= n; ++i) 
        id1[i] = id2[i] = i;
    sort(id1 + 1, id1 + 1 + n, [&](int x, int y) { return b[x] < b[y]; });
    sort(id2 + 1, id2 + 1 + n, [&](int x, int y) { return a[x] + b[x] < a[y] + b[y]; });
    int l = 1, r = 1e9, ans = 0;
    while (l <= r) {
        int md = (l + r) / 2;
        if (check(md))
            ans = md, l = md + 1;
        else
            r = md - 1;
        // else continue;
    }
    cout << ans << '\n';
}
int main() {
    freopen("CrossCountry.in", "r", stdin);
    freopen("CrossCountry.out", "w", stdout);
    T = read();
    while (T--) 
        solve();
    return 0;
}

    