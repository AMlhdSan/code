#include <bits/stdc++.h>
using namespace std;

#define N 1000010
#define int long long
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

// Fast I/O buffer
char buf[1 << 20], *p1, *p2;
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<20, stdin), p1 == p2) ? EOF : *p1++)

int n, m, r;
int w[N];                   // Node weights
int tin[N], tout[N], sz[N]; // DFS order and subtree size
int euler[N];               // Euler tour array
int timer;                  // DFS timer

// Graph storage using static arrays
int head[N], nxt[N<<1], to[N<<1], e;
inline void addEdge(int u, int v) {
    nxt[++e] = head[u]; head[u] = e; to[e] = v;
}

// Segment tree arrays
int seg[N<<2], lazy[N<<2];

// Fast I/O functions
inline int read() {
    int x = 0, f = 1; char ch = gc();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = gc();}
    while (ch >= '0' && ch <= '9') {x = (x<<3)+(x<<1)+(ch^48); ch = gc();}
    return x * f;
}

inline void write(int x) {
    if(x < 0) {putchar('-'); x = -x;}
    if(x > 9) write(x/10);
    putchar(x%10+'0');
}

// DFS to calculate Euler tour and subtree sizes
void dfs(int u, int p) {
    tin[u] = ++timer;
    euler[timer] = w[u];
    sz[u] = 1;
    for(int i = head[u]; i; i = nxt[i]) {
        int v = to[i];
        if(v != p) {
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
    tout[u] = timer;
}

// Segment tree operations
inline void pushDown(int p, int l, int r) {
    if(!lazy[p]) return;
    seg[ls] += lazy[p] * (mid - l + 1);
    seg[rs] += lazy[p] * (r - mid);
    lazy[ls] += lazy[p];
    lazy[rs] += lazy[p];
    lazy[p] = 0;
}

void build(int p, int l, int r) {
    if(l == r) {
        seg[p] = euler[l];
        return;
    }
    build(ls, l, mid);
    build(rs, mid+1, r);
    seg[p] = seg[ls] + seg[rs];
}

void update(int p, int l, int r, int ql, int qr, int val) {
    if(ql <= l && r <= qr) {
        seg[p] += val * (r - l + 1);
        lazy[p] += val;
        return;
    }
    pushDown(p, l, r);
    if(ql <= mid) update(ls, l, mid, ql, qr, val);
    if(qr > mid) update(rs, mid+1, r, ql, qr, val);
    seg[p] = seg[ls] + seg[rs];
}

int query(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) return seg[p];
    pushDown(p, l, r);
    int sum = 0;
    if(ql <= mid) sum += query(ls, l, mid, ql, qr);
    if(qr > mid) sum += query(rs, mid+1, r, ql, qr);
    return sum;
}

signed main() {
    n = read(); m = read(); r = read();
    for(int i = 1; i <= n; i++) w[i] = read();
    
    for(int i = 1; i < n; i++) {
        int u = read(), v = read();
        addEdge(u, v); addEdge(v, u);
    }
    
    dfs(r, 0);
    build(1, 1, n);
    
    while(m--) {
        int op = read();
        if(op == 1) {
            int a = read(), b = read(), x = read();
            update(1, 1, n, tin[a], tin[a], x);
            if(b != a) update(1, 1, n, tin[b], tin[b], x);
        } else if(op == 2) {
            int a = read();
            write(query(1, 1, n, tin[a], tin[a]));
            putchar('\n');
        } else {
            int a = read();
            write(query(1, 1, n, tin[a], tin[a] + sz[a] - 1));
            putchar('\n');
        }
    }
    return 0;
}