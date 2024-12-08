#include <bits/stdc++.h>

#define N 300010
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
#define ENDL putchar('\n')

using namespace std;

int tree[N << 2], lazy[N << 2], siz[N << 2];
int nxt[N << 1], head[N << 1], to[N << 1], e = 0;
int top[N << 1], cnt = 0, dep[N << 1], id[N << 1], son[N << 1], fa[N << 1], si[N << 1], wt[N << 1];

int n;
int a[N];

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
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

inline void dfs1(int p, int pre, int depth) {
    dep[p] = depth;
    si[p] = 1;
    fa[p] = pre;

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
    wt[cnt] = 0;
    top[p] = topp;

    if(!son[p]) {
        return;
    }

    dfs2(son[p], topp);

    for(int i = head[p]; i; i = nxt[i]) {
        int v = to[i];
        if(v != fa[p] && v != son[p]) {
            dfs2(v, v);
        }
    }
}

inline void upd(int p) {
    tree[p] = tree[ls] + tree[rs];
}

inline void upds(int p) {
    siz[p] = siz[ls] + siz[rs];
}

inline void pushd(int p) {
    tree[ls] += lazy[p] * siz[ls];
    tree[rs] += lazy[p] * siz[rs];

    lazy[ls] += lazy[p];
    lazy[rs] += lazy[p];

    lazy[p] = 0;
}

inline void build(int p, int l, int r) {
    if(l == r) {
        tree[p] = wt[l];
        lazy[p] = 0;
        siz[p] = 1;
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    upd(p);
    upds(p);
}

inline void mdf(int p, int l, int r, int ql, int qr, int x) {
    if(ql <= l && r <= qr) {
        tree[p] += x * siz[p];
        lazy[p] += x;
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

inline int qry(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return tree[p];
    }
    pushd(p);

    int sum = 0;

    if(ql <= mid) {
        sum += qry(ls, l, mid, ql, qr);
    }
    if(qr > mid) {
        sum += qry(rs, mid + 1, r, ql, qr);
    }
    return sum;
}

inline void modify(int l, int r, int x) {
    while(top[l] != top[r]) {
        if(dep[top[l]] < dep[top[r]]) {
            swap(l, r);
        }
        mdf(1, 1, n, id[top[l]], id[l], x);
        l = fa[top[l]];
    }
    if(dep[l] > dep[r]) {
        swap(l, r);
    }
    mdf(1, 1, n, id[l], id[r], x);
}

inline int query(int l, int r) {
    int sum = 0;
    while(top[l] != top[r]) {
        if(dep[top[l]] < dep[top[r]]) {
            swap(l, r);
        }
        sum += qry(1, 1, n, id[top[l]], id[l]);
        l = fa[top[l]];
    }
    if(dep[l] > dep[r]) {
        swap(l, r);
    }
    sum += qry(1, 1, n, id[l], id[r]);
    return sum;
}

int main() {

    n = read();

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    for(int i = 1; i <= n - 1; ++i) {
        int u, v;
        u = read();
        v = read();
        add_edge(u, v);
        add_edge(v, u);
    }

    dfs1(1, 0, 1);
    dfs2(1, 1);
    build(1, 1, n);

    for(int i = 1; i <= n - 1; ++i) {
        modify(a[i], a[i + 1], 1);
        modify(a[i + 1], a[i + 1], -1);
    }

    for(int i = 1; i <= n; ++i) {
        write(query(i, i));
        ENDL;
    }

    return 0;
}