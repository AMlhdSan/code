#include <bits/stdc++.h>

#define N 600010

using namespace std;

struct node {
    int a, b;
    int c;
}d[N];

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

inline bool cmp(node x, node y) {
    return x.c < y.c;
}

int n, q;
int head[N], nxt[N], to[N], w[N], e = 0;
int fa[N];
int dp[N][20], dep[N];

inline void add_edge(int u, int v, int c) {
    nxt[++e] = head[u];
    head[u] = e;
    to[e] = v;
    w[e] = c;

    nxt[++e] = head[v];
    head[v] = e;
    to[e] = u;
    w[e] = c; // Assuming undirected graph
}

inline int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

inline void kruskal() {
    int cnt = n;
    for(int i = 1; i <= n - 1; ++i) {
        d[i].a = find(d[i].a);
        d[i].b = find(d[i].b);
        if(d[i].a == d[i].b) continue;
        fa[d[i].a] = fa[d[i].b] = ++cnt;
        add_edge(d[i].a, cnt, d[i].c);
        add_edge(d[i].b, cnt, d[i].c);
    }
}

int main() {

    n = read();
    q = read();

    for(int i = 1; i <= n - 1; ++i) {
        d[i].a = read();
        d[i].b = read();
        d[i].c = read();
    }

    sort(d + 1, d + n, cmp);
    
    kruskal();

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j < 20; ++j) {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }

    while(q--) {

    }

    return 0;
}