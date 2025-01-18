#include <bits/stdc++.h>

#define N 100010

using namespace std;

int n, m, k;
int nxt[N], head[N], to[N];
int e = 0;

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-')
            f = -1;
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

inline void add_edge(int u, int v) {
    nxt[++e] = head[u];
    head[u] = e;
    to[e] = v;
}

int main() {

    n = read();
    m = read();
    k = read();

    if(m == 0) {
        for(int i = 1; i <= n; ++i) {
            write(i);
            putchar(' ');
        }
    }

    else if(k == 0) {
        write(1);
        putchar(' ');
        for(int i = 1; i <= m; ++i) {
            int u, v;
            u = read();
            v = read();

        }
    }

    return 0;
}