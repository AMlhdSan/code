#include <bits/stdc++.h>

#define N 1000010

using namespace std;

int n, m;
int fa[N];
int siz[N];

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

inline int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

inline void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y)
        return;
    fa[x] = y;
    siz[y] += siz[x];
}

int main() {

    n = read();
    m = read();

    for(int i = 1; i <= n; ++i) {
        fa[i] = i;
        siz[i] = 1;
    }

    for(int i = 1; i <= m; ++i) {
        int u, v;
        u = read();
        v = read();
        merge(u, v);
    }

    int maxx = 1;

    for(int i = 1; i <= n; ++i) {
        maxx = max(maxx, siz[i]);
    }

    write(maxx);

    return 0;
}