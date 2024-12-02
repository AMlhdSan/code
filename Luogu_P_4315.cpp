#include <bits/stdc++.h>

#define N    100010
#define ENDL putchar('\n')
#define pc   putchar
#define il   inline
#define ls   (p << 1)
#define rs   (p << 1 | 1)
#define mid  ((l + r) >> 1)

using namespace std;

int n;
int nxt[N << 2], head[N << 2], ww[N << 2], to[N << 2], w[N << 2];
int top[N << 2], son[N << 2], id[N << 2], wt[N << 2];
int e = 0, cnt = 0;
int dep[N << 2], fa[N << 2], si[N << 2];
int tree[N << 2], lazy1[N << 2], lazy2[N << 2];
string str;

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

il void add_edge(int u, int v, int c) {
    nxt[++e] = head[u];
    head[u] = e;
    to[e] = v;
    ww[e] = c;
}

il void dfs1(int p, int pre, int depth) {
    fa[p] = pre;
    dep[p] = depth;
    si[p] = 1;

    int maxx = -1;

    for(int i = head[p]; i; i = nxt[i]) {
        int v = to[i];
        if(v != pre) {
            dfs1(v, p, depth + 1);
            w[v] = ww[i];
            si[p] += si[v];
            if(si[v] > maxx) {
                maxx = si[v];
                son[p] = v;
            }
        }
    }
}

il void dfs2(int p, int topp) {
    id[p] = ++cnt;
    wt[cnt] = w[p];
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

il void upd(int p) {
    tree[p] = max(tree[ls], tree[rs]);
}

il void pushd(int p) {
    if(lazy2[p] != -1) {
        tree[ls] = lazy2[p];
        tree[rs] = lazy2[p];
        lazy2[ls] = lazy2[p];
        lazy2[rs] = lazy2[p];
        lazy1[ls] = lazy1[rs] = 0;
        lazy2[p] = -1;
    }
    if(lazy1[p]) {
        tree[ls] += lazy1[p];
        tree[rs] += lazy1[p];
        lazy1[ls] += lazy1[p];
        lazy1[rs] += lazy1[p];
        lazy1[p] = 0;
    }
}

il void build(int p, int l, int r) {
    lazy1[p] = 0;
    lazy2[p] = -1;
    if(l == r) {
        tree[p] = wt[l];
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    upd(p);
}

il int qry(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return tree[p];
    }
    pushd(p);
    int maxx = -0x7fffffff;
    if(ql <= mid) {
        maxx = max(maxx, qry(ls, l, mid, ql, qr));
    }
    if(qr > mid) {
        maxx = max(maxx, qry(rs, mid + 1, r, ql, qr));
    }
    return maxx;
}

il void mdf(int p, int l, int r, int ql, int qr, int x) {
    if(ql <= l && r <= qr) {
        tree[p] += x;
        lazy1[p] += x;
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

il void chg(int p, int l, int r, int ql, int qr, int x) {
    if(ql <= l && r <= qr) {
        tree[p] = x;
        lazy1[p] = 0;
        lazy2[p] = x;
        return;
    }
    pushd(p);
    if(ql <= mid) {
        chg(ls, l, mid, ql, qr, x);
    }
    if(qr > mid) {
        chg(rs, mid + 1, r, ql, qr, x);
    }
    upd(p);
}

il void cover(int l, int r, int x) {
    while(top[l] != top[r]) {
        if(dep[top[l]] < dep[top[r]]) {
            swap(l, r);
        }
        chg(1, 1, n, id[top[l]], id[l], x);
        l = fa[top[l]];
    }
    if(dep[l] > dep[r]) {
        swap(l, r);
    }
    if (id[l] != id[r]) chg(1, 1, n, id[l] + 1, id[r], x);
}

il void add(int l, int r, int x) {
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
    if (id[l] != id[r]) mdf(1, 1, n, id[l] + 1, id[r], x);
}

il int query(int l, int r) {
    int maxx = -0x7fffffff;
    while(top[l] != top[r]) {
        if(dep[top[l]] < dep[top[r]]) {
            swap(l, r);
        }
        maxx = max(maxx, qry(1, 1, n, id[top[l]], id[l]));
        l = fa[top[l]];
    }
    if(dep[l] > dep[r]) {
        swap(l, r);
    }
    if (id[l] != id[r]) maxx = max(maxx, qry(1, 1, n, id[l] + 1, id[r]));
    return maxx;
}


int main() {
    n = read();

    for(int i = 1; i <= n - 1; ++i) {
        int u, v, c;
        u = read();
        v = read();
        c = read();
        add_edge(u, v, c); // i * 2 - 1
        add_edge(v, u, c); // i * 2
    }

    dfs1(1, 0, 1);
    dfs2(1, 1);
    build(1, 1, n);

    cin >> str;
    while(str[0] != 'S') {
        if(str[0] == 'C' && str[1] == 'h') {
            int p, x;
            p = read();
            x = read();
            cover(to[2 * p - 1], to[2 * p], x);
        }
        else if(str[0] == 'C' && str[1] == 'o') {
            int l, r, x;
            l = read();
            r = read();
            x = read();
            cover(l, r, x);
        }
        else if(str[0] == 'A') {
            int l, r, x;
            l = read();
            r = read();
            x = read();
            add(l, r, x);
        }
        else if(str[0] == 'M') {
            int l, r;
            l = read();
            r = read();
            write(query(l, r));
            ENDL;
        }
        cin >> str;
    }

    return 0;
}