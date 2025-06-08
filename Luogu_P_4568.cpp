#include <bits/stdc++.h>

#define N 100010

using namespace std;

int n, m, k;
int s, t;
int head[N], to[N], w[N], nxt[N], e = 0;

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

inline void add_edge(int u, int v, int c) {
    to[++e] = v;
    w[e] = c;
    nxt[e] = head[u];
    head[u] = e;

    to[++e] = u;
    w[e] = c;
    nxt[e] = head[v];
    head[v] = e;
}

int main() {

    n = read();
    m = read();
    k = read();

    s = read();
    t = read();

    for(int i = 1; i <= m; ++i) {
        int a, b, c;
        a = read();
        b = read();
        c = read();
    }

    

    return 0;
}