#include <bits/stdc++.h>
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

int n, x, V, a[105];

bitset<10005> f, g;

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    n = read(), x = read(), V = read();
    for (int i = 0; i < n; i++) a[i] = read();
    if (x > V) return puts("-1"), 0;
    f[x] = 1;
    for (int i = 0; i < n; i++) {
        g.reset();
        for (int j = 0; j <= V; j++) if (f[j]) {
            if (j + a[i] <= V) g[j + a[i]] = 1;
            if (j - a[i] >= 0) g[j - a[i]] = 1;
        }
        f = g;
    }
    for (int i = V; i >= 0; i--) 
        if (f[i]) 
            return writeln(i), 0;
    puts("-1");
}
