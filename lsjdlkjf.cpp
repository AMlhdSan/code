#include <bits/stdc++.h>

#define N 200005
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

int T, n, m;
int a[N], cnt[N * 2], lst[N * 2];
int x, y;

void solve() {
    n = read();
    m = read();
    
    for (int i = 1; i <= n + m; i++) {
        cnt[i] = 0;
        lst[i] = -1;
    }
    
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        lst[a[i]] = 0;
    }
    
    for (int i = 1; i <= m; i++) {
        x = read();
        y = read();
        
        if (a[x] != y) {
            cnt[a[x]] += i - lst[a[x]];
            lst[a[x]] = -1;
            lst[y] = i;
            a[x] = y;
        }
    }
    
    for (int i = 1; i <= n + m; i++) {
        if (lst[i] != -1) {
            cnt[i] += m - lst[i] + 1;
        }
    }
    
    ll ans = 0;
    
    for (int i = 1; i <= n + m; i++) {
        ans += cnt[i] * (m + 1 - cnt[i]);
        ans += cnt[i] * (cnt[i] - 1) / 2;
    }
    
    writeln(ans);
}

int main() {
    // freopen("array.in", "r", stdin);
    // freopen("array.out", "w", stdout);
    solve();
    return 0;
}