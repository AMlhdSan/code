#include <bits/stdc++.h>
using namespace std;

#define N 1000010
#define int long long
#define lowbit(x) ((x)&(-x))

char buf[1 << 20], *p1, *p2;
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<20, stdin), p1 == p2) ? EOF : *p1++)

int n, m, root;
int head[N], nxt[N<<1], to[N<<1], idx;
int fa[N], dep[N], sz[N], son[N];
int timestamp, dfn[N], top[N];
int fw[2][N], w[N];

inline int read() {
    int x = 0, f = 1; char ch = gc();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = gc();}
    while(ch >= '0' && ch <= '9') {x = (x<<3)+(x<<1)+(ch^48); ch = gc();}
    return x * f;
}

inline void write(int x) {
    if(x < 0) {putchar('-'); x = -x;}
    if(x > 9) write(x/10);
    putchar(x%10+'0');
}

inline void addEdge(int a, int b) {
    nxt[++idx] = head[a];
    head[a] = idx;
    to[idx] = b;
}

inline void add(int t, int k, int x) {
    for(; k <= n; k += lowbit(k)) fw[t][k] += x;
}

inline int sum(int t, int k) {
    int res = 0;
    for(; k; k -= lowbit(k)) res += fw[t][k];
    return res;
}

inline void dfs1(int u, int p) {
    sz[u] = 1;
    fa[u] = p;
    dep[u] = dep[p] + 1;
    
    for(int i = head[u]; i; i = nxt[i]) {
        int j = to[i];
        if(j == p) continue;
        dfs1(j, u);
        sz[u] += sz[j];
        if(sz[son[u]] < sz[j]) son[u] = j;
    }
}

inline void dfs2(int u, int t) {
    dfn[u] = ++timestamp;
    top[u] = t;
    if(!son[u]) return;
    dfs2(son[u], t);
    for(int i = head[u]; i; i = nxt[i]) {
        int j = to[i];
        if(j == son[u] || j == fa[u]) continue;
        dfs2(j, j);
    }
}

inline int getLCA(int u, int v) {
    while(top[u] != top[v]) {
        if(dep[top[u]] < dep[top[v]]) swap(u, v);
        u = fa[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
}

inline void update(int u, int v, int val) {
    int lca = getLCA(u, v);
    add(0, dfn[u], val);
    add(0, dfn[v], val);
    add(0, dfn[lca], -val);
    add(0, dfn[fa[lca]], -val);
    add(1, dfn[u], val * dep[u]);
    add(1, dfn[v], val * dep[v]);
    add(1, dfn[lca], -val * dep[lca]);
    add(1, dfn[fa[lca]], -val * dep[fa[lca]]);
}

inline int queryNode(int u) {
    return sum(0, dfn[u] + sz[u] - 1) - sum(0, dfn[u] - 1);
}

inline int queryTree(int u) {
    return sum(1, dfn[u] + sz[u] - 1) - sum(1, dfn[u] - 1) - queryNode(u) * (dep[u] - 1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    n = read(); m = read(); root = read();
    
    for(int i = 1; i <= n; i++) w[i] = read();
    
    for(int i = 1; i < n; i++) {
        int u = read(), v = read();
        addEdge(u, v); addEdge(v, u);
    }
    
    dfs1(root, 0);
    dfs2(root, root);
    
    for(int i = 1; i <= n; i++) update(i, i, w[i]);
    
    while(m--) {
        int op = read(), a = read();
        if(op == 1) {
            int b = read(), x = read();
            update(a, b, x);
        } else if(op == 2) {
            write(queryNode(a));
            putchar('\n');
        } else {
            write(queryTree(a));
            putchar('\n');
        }
    }
    return 0;
}