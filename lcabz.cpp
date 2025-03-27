#include <bits/stdc++.h>

#define N 500005
#define ll long long
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

int n, m, s;
int lg[N];
int xx, yy;
vector<int> edge[N];
int dep[N];
int fa[N][31];

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

void dfs(int p, int pre) {
    fa[p][0] = pre;
    dep[p] = dep[pre] + 1;
    for(int i = 1; i <= lg[dep[p]]; ++i) {
        fa[p][i] = fa[fa[p][i - 1]][i - 1];
    }
    for(int nxt : edge[p]) {
        if(nxt != pre) {
            dfs(nxt, p);
        }
    }
}

int lca(int u, int v) {
    if(dep[u] < dep[v]) {
        swap(u, v);
    }
    while(dep[u] > dep[v]) {
        u = fa[u][lg[dep[u] - dep[v]] - 1];
    }
    if(u == v) {
        return u;
    }
    for(int llg = lg[dep[u]] - 1; llg >= 0; --llg) {
        if(fa[u][llg] != fa[v][llg]) {
            u = fa[u][llg];
            v = fa[v][llg];
        }
    }

    return fa[u][0];
}

int main() {
    n = read();
    m = read();
    s = read();

    for(int i = 1; i <= n - 1; ++i) {
        xx = read();
        yy = read();
        edge[xx].push_back(yy);
        edge[yy].push_back(xx);
    }

    int cntt = 0;

    for(int i = 1; i <= n; ++i) {
        if(i >= (1 << cntt)) {
            ++cntt;
            lg[i] = cntt;
        }
        else {
            lg[i] = cntt;
        }
    }
    
    dfs(s, 0);

    while(m--) {
        xx = read();
        yy = read();
        writeln(lca(xx, yy));
    }

    return 0;
}