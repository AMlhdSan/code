#include <bits/stdc++.h>

#define N 500010

using namespace std;
assume
int n, k, q;
int nxt[N], head[N], to[N], w[N], e = 0;
int siz[N]; 
int dis[N]; 
bool kk[N];
bool iff[N]; 
int dep[N];
int lca[N][31];
int lg[N];
int r;
int tot;

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
}

inline void dfs(int p, int pre) {
    dep[p] = dep[pre] + 1;
    lca[p][0] = pre;
    if(kk[p]) {
        siz[p] = 1;
    }
    for(int i = 1; i <= lg[dep[p]]; ++i) {
        lca[p][i] = lca[lca[p][i - 1]][i - 1];
    }
    for(int i = head[p]; i; i = nxt[i]) {
        if(to[i] == pre) {
            continue;
        }
        dis[to[i]] = dis[p] + w[i];
        dfs(to[i], p);
        siz[p] += siz[to[i]];
        if(siz[to[i]] > 0) {
            tot += w[i];
        }
    }
}

inline int f(int p) {
    if(iff[p]) return p;
    for(int i = lg[dep[p]]; i >= 0; --i) {
        if(lca[p][i] && !iff[lca[p][i]])
            p = lca[p][i];
    }
    return lca[p][0];
}


inline int fa(int x, int y) {
    if(dep[x] > dep[y]) {
        swap(x, y);
    }
    for(int i = lg[dep[y]]; i >= 0; --i) {
        if(dep[lca[y][i]] >= dep[x]) {
            y = lca[y][i];
        }
    }
    if(x == y) {
        return x;
    }

    for(int i = lg[dep[x]]; i >= 0; --i) {
        if(lca[x][i] != lca[y][i]) {
            x = lca[x][i];
            y = lca[y][i];
        }
    }
    return lca[x][0];
}

inline int dist(int x, int y) {
    return dis[x] + dis[y] - 2 * dis[fa(x, y)];
}

inline void tag() {
    for(int i = 1; i <= n; ++i) {
        if(siz[i]) {
            iff[i] = 1;
        }
    }
}

int main() {
    n = read();
    q = read();
    k = read();

    for(int i = 1; i <= n; ++i) {
        lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
    }

    for(int i = 1; i <= n - 1; ++i) {
        int u, v, c;
        u = read();
        v = read();
        c = read();
        add_edge(u, v, c);
        add_edge(v, u, c);
    }

    for(int i = 1; i <= k; ++i) {
        int p = read();
        kk[p] = 1;
        r = p;
    }
    
    dep[0] = 0;
    dfs(r, 0);
    tag();

    while(q--) {
        int s, t;
        s = read();
        t = read();
        int x = f(s), y = f(t);
        int ans = dist(s, x) + dist(y, t) + 2 * tot - dist(x, y);
        writeln(ans);
    }

    return 0;
}