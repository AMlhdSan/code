#include <bits/stdc++.h>
using namespace std;

int n, m;

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

int main() {

    return 0;
}

/*
#include <bits/stdc++.h>

#define N 1000010
#define ENDL putchar('\n')

#define mid ((l + r) >> 1)
#define ls (p << 1)
#define rs (p << 1 | 1)

using namespace std;

int n, m, r, MOD;
int nxt[N], head[N], to[N], w[N];
int top[N];
int si[N], fa[N], id[N], son[N], wt[N], dep[N];
int cnt = 0, e = 0;
int tree[N << 2], siz[N << 2], lazy[N << 2];

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

inline int qry(int p, int l, int r, int ql, int qr) {
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
            si[p] +=  si[v];
            if(si[v] > maxx) {
                maxx = si[v];
                son[p] = v;
            }
        }
    }
}

inline void dfs2(int p, int topp) {
    id[p] = ++cnt;
    wt[cnt] = w[p];
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

inline void modify2(int p, int x) {
    mdf(1, 1, n, id[p], id[p] + si[p] - 1, x);
}

inline int query2(int p) {
    return qry(1, 1, n, id[p], id[p] + si[p] - 1) % MOD;
}

int main() {

    n = read();
    m = read();
    r = read();
    MOD = read();

    for(int i = 1; i <= n; ++i) {
        w[i] = read();
    }

    for(int i = 1; i <= n - 1; ++i) {
        int u, v;
        u = read();
        v = read();
        add_edge(u, v);
        add_edge(v, u);
    }

    dfs1(r, 0, 1);
    dfs2(r, r);

    build(1, 1, n);

    while(m--) {
        int op;
        op = read();
        if(op == 1) {
            int x, y, z;
            x = read();
            y = read();
            z = read();
            modify1(x, y, z);
        }
        else if(op == 2) {
            int x, y;
            x = read();
            y = read();
            write(query1(x, y));
            ENDL;
        }
        else if(op == 3) {
            int x, z;
            x = read();
            z = read();
            modify2(x, z);
        }
        else {
            int x;
            x = read();
            write(query2(x));
            ENDL;
        }
    }

    return 0;
}
*/