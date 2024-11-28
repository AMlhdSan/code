// 策略：一条边的权值赋给儿子节点。
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
int nxt[N], head[N], ww[N], to[N], w[N];
int top[N], son[N], id[N], wt[N];
int e = 0, cnt = 0;
int dep[N], fa[N], si[N];
int tree[N], lazy1[N], lazy2[N];

il int read() {
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

il void write(int x) {
    if(x < 0) {
        x = -x;
        pc('-');
    }
    if(x >= 10) {
        write(x / 10);
    }
    pc(x % 10 + '0');
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
    id[++cnt] = p;
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
        
    }
}

il void build(int p, int l, int r) {
    if(l == r) {
        tree[p] = wt[l];
        lazy1[p] = 0;
        lazy2[p] = -1;
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
}


int main() {

    n = read();

    for(int i = 1; i <= n - 1; ++i) {
        int u, v, c;
        u = read();
        v = read();
        add_edge(u, v, c);
        add_edge(v, u, c);
    }

    dfs1(1, 0, 1);
    dfs2(1, 1);
    build(1, 1, n);


    return 0;
}