#include <bits/stdc++.h>

#define N 500010
// #define int long long

char buf[1 << 21], *p1 = buf, *p2 = buf;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)

using namespace std;

int n, m, s;
int nxt[N * 2], head[N * 2], to[N * 2];
int e = 0;
int lca[N * 2][31];
int dep[N * 2];
int lg[N * 2];

inline void add_edge(int u, int v) {
    nxt[++e] = head[u];
    head[u] = e;
    to[e] = v;
}

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

inline void dfs(int p, int pre) {
    dep[p] = dep[pre] + 1;
    lca[p][0] = pre;
    for(int i = 1; i <= lg[dep[p]]; ++i) {
        lca[p][i] = lca[lca[p][i - 1]][i - 1];
    }
    for(int i = head[p]; i; i = nxt[i]) {
        if(to[i] != pre) {
            dfs(to[i], p);
        }
    }
}

inline int find_lca(int u, int v) {
    if(dep[u] < dep[v]) {
        swap(u, v);
    }
    while(dep[u] > dep[v]) {
        u = lca[u][lg[dep[u] - dep[v]] - 1];
    }
    if(u == v) {
        return u;
    }
    for(int i = lg[dep[u]] - 1; i >= 0; --i) {
        if(lca[u][i] != lca[v][i]) {
            u = lca[u][i];
            v = lca[v][i];
        }
    }
    return lca[u][0];
}

int main() {

    n = read();
    m = read();
    s = read();

    for(int i = 1; i < n; ++i) {
        int u = read();
        int v = read();
        add_edge(u, v);
        add_edge(v, u);
    }

    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
        if(i >= (1 << cnt)) {
            ++cnt;
            lg[i] = cnt;
        }
        else
            lg[i] = cnt;
    }

    dfs(s, 0);

    while(m--) {
        int u = read();
        int v = read();
        writeln(find_lca(u, v));
    }

    return 0;
}