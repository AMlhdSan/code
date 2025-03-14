#include <bits/stdc++.h>

#define N 1000010
#define ll long long
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

int n, q, root;
int h[N], e[N << 1], ne[N << 1], idx;
ll fw[2][N], a[N];
int fa[N], dep[N], sz[N], son[N];
int timestamp, dfn[N], top[N];

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

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int lowbit(int x) {
    return x & -x;
}

void add_bit(int t, int k, ll x) {
    if (!k) return;
    for (; k <= n; k += lowbit(k))
        fw[t][k] += x;
}

ll sum(int t, int k) {
    ll res = 0;
    for (; k; k -= lowbit(k))
        res += fw[t][k];
    return res;
}

void dfs1(int u, int p) {
    sz[u] = 1;
    fa[u] = p, dep[u] = dep[p] + 1;
    
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        
        if (j == p) continue;
        
        dfs1(j, u);
        sz[u] += sz[j];
        
        if (sz[son[u]] < sz[j])
            son[u] = j;
    }
}

void dfs2(int u, int t) {
    dfn[u] = ++timestamp;
    top[u] = t;
    
    if (!son[u]) return;
    
    dfs2(son[u], t);
    
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        
        if (j == son[u] || j == fa[u]) continue;
        
        dfs2(j, j);
    }
}

int Lca(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        
        u = fa[top[u]];
    }
    
    return dep[u] < dep[v] ? u : v;
}

void update(int u, int v, ll x) {
    int lca = Lca(u, v);
    add_bit(0, dfn[u], x), add_bit(0, dfn[v], x);
    add_bit(0, dfn[lca], -x), add_bit(0, dfn[fa[lca]], -x);
    add_bit(1, dfn[u], x * dep[u]), add_bit(1, dfn[v], x * dep[v]);
    add_bit(1, dfn[lca], -x * dep[lca]), add_bit(1, dfn[fa[lca]], -x * dep[fa[lca]]);
}

ll querynode(int u) {
    return sum(0, dfn[u] + sz[u] - 1) - sum(0, dfn[u] - 1);
}

ll querytree(int u) {
    return sum(1, dfn[u] + sz[u] - 1) - sum(1, dfn[u] - 1) - querynode(u) * (dep[u] - 1);
}

int main() {
    memset(h, -1, sizeof h);
    n = read(), q = read(), root = read();
    
    for (int i = 1; i <= n; i++)
        a[i] = read();
    
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        add(u, v), add(v, u);
    }
    
    dfs1(root, 0);
    dfs2(root, root);
    
    for (int i = 1; i <= n; i++)
        update(i, i, a[i]);
    
    while (q--) {
        int op = read(), u = read();
        
        if (op == 1) {
            int v = read(), x = read();
            update(u, v, x);
        } else if (op == 2) {
            printf("%lld\n", querynode(u));
        } else {
            printf("%lld\n", querytree(u));
        }
    }
    
    return 0;
}