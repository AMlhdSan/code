#include <bits/stdc++.h>

#define N 100100
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
#define ENDL putchar('\n')

using namespace std;

char buf[1 << 20], *p1, *p2;
#define gc()                                                               \
  (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) \
       ? EOF                                                               \
       : *p1++)

int n;
int nxt[N], head[N], to[N], si[N], top[N], son[N], fa[N], id[N], dep[N];
int w[N], wt[N];
int cnt = 0, e = 0;
int q;
int treem[N << 2], trees[N << 2];

inline string stringread() {
	string str = "";
	char ch = gc();
	while(ch == ' ' || ch == '\n' || ch == '\r') {
		ch = gc(); 
	}
	while(ch != ' ' && ch != '\n' && ch != '\r') {
		str += ch;
		ch = gc();
	} 
	return str;
}

inline void stringwrite(string str) {
	for(int i = 0; str[i] != '\0'; ++i) 
        putchar(str[i]);
}

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

inline void add_edge(int u, int v) {
    nxt[++e] = head[u];
    head[u] = e;
    to[e] = v;
}

inline void dfs1(int p, int pre, int depth) {
    si[p] = 1;
    fa[p] = pre;
    dep[p] = depth;

    int maxx = -1;

    for(register int i = head[p]; i; i = nxt[i]) {
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
    top[p] = topp;
    id[p] = ++cnt;
    wt[cnt] = w[p];

    if(!son[p]) {
        return;
    }

    dfs2(son[p], topp);

    for(register int i = head[p]; i; i = nxt[i]) {
        int v = to[i];
        if(v != fa[p] && v != son[p]) {
            dfs2(v, v);
        }
    }
}

inline void updm(int p) {
    treem[p] = max(treem[ls], treem[rs]);
}

inline void upds(int p) {
    trees[p] = trees[ls] + trees[rs];
}

inline void build(int p, int l, int r) {
    if(l == r) {
        treem[p] = wt[l];
        trees[p] = wt[l];
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    updm(p);
    upds(p);
}

inline void mdf(int p, int l, int r, int ql, int qr, int x) {
    if(ql <= l && r <= qr) {
        treem[p] = x;
        trees[p] = x;
        return;
    }
    if(ql <= mid) {
        mdf(ls, l, mid, ql, qr, x);
    }
    if(qr > mid) {
        mdf(rs, mid + 1, r, ql, qr, x);
    }
    updm(p);
    upds(p);
}

inline int qrym(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return treem[p];
    }
    int maxx = -0x7fffffff;
    if(ql <= mid) {
        maxx = max(maxx, qrym(ls, l, mid, ql, qr));
    }
    if(qr > mid) {
        maxx = max(maxx, qrym(rs, mid + 1, r, ql, qr));
    }
    return maxx;
}

inline int qrys(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return trees[p];
    }
    int sum = 0;
    if(ql <= mid) {
        sum += qrys(ls, l, mid, ql, qr);
    }
    if(qr > mid) {
        sum += qrys(rs, mid + 1, r, ql, qr);
    }
    return sum;
}

inline void change(int p, int x) {
    mdf(1, 1, n, p, p, x);
}

inline int querym(int l, int r) {
    int maxx = -0x7fffffff;
    while(top[l] != top[r]) {
        if(dep[top[l]] < dep[top[r]]) {
            swap(l, r);
        }
        maxx = max(maxx, qrym(1, 1, n, id[top[l]], id[l]));
        l = fa[top[l]];
    }
    if(dep[l] > dep[r]) {
        swap(l, r);
    }
    maxx = max(maxx, qrym(1, 1, n, id[l], id[r]));
    return maxx;
}

inline int querys(int l, int r) {
    int sum = 0;
    while(top[l] != top[r]) {
        if(dep[top[l]] < dep[top[r]]) {
            swap(l, r);
        }
        sum += qrys(1, 1, n, id[top[l]], id[l]);
        l = fa[top[l]];
    }
    if(dep[l] > dep[r]) {
        swap(l, r);
    }
    sum += qrys(1, 1, n, id[l], id[r]);
    return sum;
}

int main() {

    n = read();

    for(register int i = 1; i <= n - 1; ++i) {
        int u, v;
        u = read();
        v = read();
        add_edge(u, v);
        add_edge(v, u);
    }

    for(register int i = 1; i <= n; ++i) {
        w[i] = read();
    }

    dfs1(1, 0, 1);
    dfs2(1, 1);

    build(1, 1, n);

    q = read();

    while(q--) {
        string op;
        int x, y;
        op = stringread();
        x = read();
        y = read();
        if(op == "CHANGE") {
            change(id[x], y);
        }
        else if(op == "QMAX") {
            write(querym(x, y));
            ENDL;
        }
        else if(op == "QSUM") {
            write(querys(x, y));
            ENDL;
        }
    }

    return 0;
}