#include <bits/stdc++.h>

#define N     201000
#define il    inline 
#define ls    (p << 1)
#define rs    (p << 1 | 1)
#define mid   ((l + r) >> 1)
#define ENDL  putchar('\n')
#define gc    getchar
#define pc    putchar

using namespace std;

int n, m;
string opt;
int trmax[N << 2], trmin[N << 2], trsum[N << 2];
int top[N], id[N], son[N], fa[N], si[N], dep[N];
int w[N << 1], wt[N << 1], ww[N << 1];
int nxt[N << 1], head[N << 1], to[N << 1];
int tag[N << 2];
int e = 0, cnt = 0;

il int read() {
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

il void write(int x) {
    if(x < 0) {
        pc('-');
        x = -x;
    }
    if(x > 9) {
        write(x / 10);
    }
    pc(x % 10 + '0');
}

il void op(int &x) {
    x = -x;
}

il void add_edge(int u, int v, int c) {
    nxt[++e] = head[u];
    head[u] = e;
    to[e] = v;
    ww[e] = c;
}

il void upd(int p) {
    trmax[p] = max(trmax[ls], trmax[rs]);
    trmin[p] = min(trmin[ls], trmin[rs]);
    trsum[p] = trsum[ls] + trsum[rs];
}

il void pushd(int p) {
    if(tag[p]) {
        op(trmin[ls]);
        op(trmax[ls]);
        op(trmin[rs]);
        op(trmax[rs]);
        swap(trmin[ls], trmax[ls]);
        swap(trmin[rs], trmax[rs]);
        op(trsum[ls]);
        op(trsum[rs]);
        tag[ls] ^= 1;
        tag[rs] ^= 1;
        tag[p] = 0;
    }
}

il void build(int p, int l, int r) {
    if(l == r) {
        trmax[p] = trmin[p] = trsum[p] = wt[l];
        tag[p] = 0;
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    upd(p);
}

il void oppo(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        swap(trmax[p], trmin[p]);
        op(trmax[p]);
        op(trmin[p]);
        op(trsum[p]);
        tag[p] ^= 1;
        return;
    }
    pushd(p);
    if(ql <= mid) {
        oppo(ls, l, mid, ql, qr);
    }
    if(qr > mid) {
        oppo(rs, mid + 1, r, ql, qr);
    }
    upd(p);
}

il void chg(int p, int l, int r, int ql, int qr, int x) {
    if(l == r) {
        trmax[p] = trmin[p] = trsum[p] = x;
        //tag[p] = 0;
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

il int qrysum(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return trsum[p];
    }
    pushd(p);
    int sum = 0;
    if(ql <= mid) {
        sum += qrysum(ls, l, mid, ql, qr);
    }
    if(qr > mid) {
        sum += qrysum(rs, mid + 1, r, ql, qr);
    }
    return sum;
}

il int qrymax(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return trmax[p];
    }
    pushd(p);
    int maxx = -0x7fffffff;
    if(ql <= mid) {
        maxx = max(maxx, qrymax(ls, l, mid, ql, qr));
    }
    if(qr > mid) {
        maxx = max(maxx, qrymax(rs, mid + 1, r, ql, qr));
    }
    return maxx;
}

il int qrymin(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return trmin[p];
    }
    pushd(p);
    int minn = 0x7fffffff;
    if(ql <= mid) {
        minn = min(minn, qrymin(ls, l, mid, ql, qr));
    }
    if(qr > mid) {
        minn = min(minn, qrymin(rs, mid + 1, r, ql, qr));
    }
    return minn;
}

il void dfs1(int p, int pre, int depth) {
    si[p] = 1;
    fa[p] = pre;
    dep[p] = depth;

    int maxx = -1;
    
    for(int i = head[p]; i; i = nxt[i]) {
        int v = to[i];
        if(v != pre) {
            dfs1(v, p, depth + 1);
            si[p] += si[v];
            w[v] = ww[i];
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

il void change(int p, int x) {
    chg(1, 1, n, max(id[to[p * 2 - 1]], id[to[p * 2]]), max(id[to[p * 2 - 1]], id[to[p * 2]]), x);
}

il void opp(int l, int r) {
    while(top[l] != top[r]) {
        if(dep[top[l]] < dep[top[r]]) {
            swap(l, r);
        }
        oppo(1, 1, n, id[top[l]], id[l]);
        l = fa[top[l]];
    }
    if(dep[l] > dep[r]) {
        swap(l, r);
    }
    if(id[l] != id[r])
        oppo(1, 1, n, id[l] + 1, id[r]);
}

il int querysum(int l, int r) {
    int sum = 0;
    while(top[l] != top[r]) {
        if(dep[top[l]] < dep[top[r]]) {
            swap(l, r);
        }
        sum += qrysum(1, 1, n, id[top[l]], id[l]);
        l = fa[top[l]];
    }
    if(dep[l] > dep[r]) {
        swap(l, r);
    }
    if(id[l] != id[r])
        sum += qrysum(1, 1, n, id[l] + 1, id[r]);
    return sum;
}

il int querymax(int l, int r) {
    int maxx = -0x7fffffff;
    while(top[l] != top[r]) {
        if(dep[top[l]] < dep[top[r]]) {
            swap(l, r);
        }
        maxx = max(maxx, qrymax(1, 1, n, id[top[l]], id[l]));
        l = fa[top[l]];
    }
    if(dep[l] > dep[r]) {
        swap(l, r);
    }
    if(id[l] != id[r]) 
        maxx = max(maxx, qrymax(1, 1, n, id[l] + 1, id[r]));
    return maxx;
}

il int querymin(int l, int r) {
    int minn = 0x7fffffff;
    while(top[l] != top[r]) {
        if(dep[top[l]] < dep[top[r]]) {
            swap(l, r);
        }
        minn = min(minn, qrymin(1, 1, n, id[top[l]], id[l]));
        l = fa[top[l]];
    }
    if(dep[l] > dep[r]) {
        swap(l, r);
    }
    if(id[l] != id[r])
        minn = min(minn, qrymin(1, 1, n, id[l] + 1, id[r]));
    return minn;
}

int main() {

    n = read();

    for(int i = 1; i <= n - 1; ++i) {
        int u, v, c;
        u = read();
        v = read();
        c = read();
        ++u;
        ++v;
        add_edge(u, v, c);
        add_edge(v, u, c);
    }

    dfs1(1, 0, 1);
    dfs2(1, 1);
    build(1, 1, n);

    m = read();

    while(m--) {
        cin >> opt;
        if(opt == "C") {
            int p, x;
            p = read();
            x = read();
            // ++p;
            change(p, x);
        }
        else if(opt == "N") {
            int l, r;
            l = read();
            r = read();
            ++l;
            ++r;
            opp(l, r);
        }
        else if(opt == "SUM") {
            int l, r;
            l = read();
            r = read();
            ++l;
            ++r;
            write(querysum(l, r));
            ENDL;
        }
        else if(opt == "MAX") {
            int l, r;
            l = read();
            r = read();
            ++l;
            ++r;
            write(querymax(l, r));
            ENDL;
        }
        else if(opt == "MIN") {
            int l, r;
            l = read();
            r = read();
            ++l;
            ++r;
            write(querymin(l, r));
            ENDL;
        }
    }

    return 0;
}