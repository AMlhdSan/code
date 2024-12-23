#include <bits/stdc++.h>

#define N 1000010
#define ENDL putchar('\n')

#define mid ((l + r) >> 1)
#define ls (p << 1)
#define rs (p << 1 | 1)

#define gc() getchar()
using namespace std;

int n, r, MOD;
int nxt[N], head[N], to[N], w[N];
int top[N];
int si[N], fa[N], id[N], son[N], wt[N], dep[N];
int cnt = 0, e = 0;
int tree[N << 2], siz[N << 2], lazy[N << 2];

struct node {
    int val, id;
}a[N];

inline int read() {
    int x = 0, f = 1;
    char ch = gc();
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = gc();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = gc();
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


inline void add(int &a, int b) {
    a = (a + b) % MOD;
}


inline void upd(int p) {
    tree[p] = (tree[ls] + tree[rs]) % MOD;
}

inline void upds(int p) {
    siz[p] = siz[ls] + siz[rs];
}

inline void pushd(int p) {
    if(!lazy[p])
        return;

    add(tree[ls], siz[ls] * lazy[p] % MOD);
    add(tree[rs], siz[rs] * lazy[p] % MOD);

    add(lazy[ls], lazy[p]);
    add(lazy[rs], lazy[p]);

    lazy[p] = 0;
}

inline void build(int p, int l, int r) {
    if(l == r) {
        tree[p] = wt[l];
        siz[p] = 1;
        lazy[p] = 0;
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    upd(p);
    upds(p);
}

inline void mdf(int p, int l, int r, int ql, int qr, int x) {
    if(ql <= l && r <= qr) {
        add(tree[p], siz[p] * x % MOD);
        add(lazy[p], x);
        return;
    }
    pushd(p);
    if(ql <= mid) {
        mdf(ls, l, mid, ql, qr, x);
    }
    if(qr > mid) {
        mdf(rs, mid + 1, r, ql, qr, x);
    }
    upd(p);
}

inline long long qry(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return tree[p];
    }
    pushd(p);
    int sum = 0;
    if(ql <= mid) {
        add(sum, qry(ls, l, mid, ql, qr));
    }
    if(qr > mid) {
        add(sum, qry(rs, mid + 1, r, ql, qr));
    }
    return sum;
}

inline void add_edge(int u, int v) {
    nxt[++e] = head[u];
    head[u] = e;
    to[e] = v;
}

inline void dfs1(int p, int pre, int depth) {
    dep[p] = depth;
    fa[p] = pre;
    si[p] = 1;
    int maxx = -1;

    for(int i = head[p]; i; i = nxt[i]) {
        int v = to[i];
        if(v != pre) {
            dfs1(v, p, depth + 1);
            si[p] += si[v];
            if(si[v] > maxx) {
                maxx = si[v];
                son[p] = v;
            }
        }
    }
}

inline void dfs2(int p, int topp) {
    id[p] = ++cnt;
    wt[id[p]] = si[p];
    top[p] = topp;
    if(!son[p])
        return;
    dfs2(son[p], topp);
    for(int i = head[p]; i; i = nxt[i]) {
        int v = to[i];
        if(v != son[p] && v != fa[p]) {
            dfs2(v, v);
        }
    }
}


inline void modify1(int l, int r, int x) {
    x %= MOD;
    while(top[l] != top[r]) {
        if(dep[top[l]] < dep[top[r]]) {
            swap(l, r);
        }
        mdf(1, 1, n, id[top[l]], id[l], x);
        l = fa[top[l]];
    }
    if(dep[l] > dep[r])
        swap(l, r);
    mdf(1, 1, n, id[l], id[r], x);
}

inline int query1(int l, int r) {
    int sum = 0;
    while(top[l] != top[r]) {
        if(dep[top[l]] < dep[top[r]]) {
            swap(l, r);
        }
        add(sum, qry(1, 1, n, id[top[l]], id[l]));
        l = fa[top[l]];
    }
    if(dep[l] > dep[r])
        swap(l, r);
    add(sum, qry(1, 1, n, id[l], id[r]));
    return sum;
}

inline bool cmp(node x, node y) {
    return x.val > y.val;
}

signed main() {

    n = read();
    r = 1;
    MOD = 1e9 + 7;
    int u, v;
    
    for(int i = 1; i <= n - 1; ++i) {
        u = read();
        v = read();
        add_edge(u, v);
        add_edge(v, u);
    }

    for(int i = 1; i <= n; ++i) {
        a[i].val = read();
        a[i].id = i;
    }

    sort(a + 1, a + n + 1, cmp);

    dfs1(r, 0, 1);
    dfs2(r, r);

    build(1, 1, n);

    long long ans = 0;

    for(int i = 1; i <= n; ++i) {
        ans += 1ll * a[i].val * query1(1, a[i].id) % MOD;
        ans %= MOD;
        modify1(1, a[i].id, -1);
    }

    write(ans);
    ENDL;

    return 0;
}