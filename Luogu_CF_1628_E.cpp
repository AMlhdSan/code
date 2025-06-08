#include <bits/stdc++.h>

#define N 200010
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

struct node {
    int a, b;
    int c;
}d[N];

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

inline bool cmp(node x, node y) {
    return x.c < y.c;
}

int n, q;
int r;
int head[N << 2], nxt[N << 2], to[N << 2], e = 0;
int fa[N << 2];
int dp[N << 2][24], dep[N << 2];
int val[N << 2];
int dfn[N << 2], id[N << 2], cntt = 0;

inline void add_edge(int u, int v) {
    nxt[++e] = head[u];
    head[u] = e;
    to[e] = v;

    nxt[++e] = head[v];
    head[v] = e;
    to[e] = u;
}

inline int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

inline void init() {
    for(int i = 1; i <= N - 1; ++i) {
        fa[i] = i;
    }
}

inline void dfs(int p, int pre) {
    dfn[p] = ++cntt;
    id[cntt] = p;
    for(int i = 1; i < 20; ++i) {
        dp[p][i] = dp[dp[p][i - 1]][i - 1];
    }
    for(int i = head[p]; i; i = nxt[i]) {
        int v = to[i];
        if(v == pre) continue;
        dp[v][0] = p; // 记录父节点
        dep[v] = dep[p] + 1; // 记录深度
        dfs(v, p);
    }
}

inline int lca(int x, int y) {
    if(dep[x] < dep[y]) 
        swap(x, y);
    int d = dep[x] - dep[y];
    for(int i = 0; i < 20; ++i) {
        if(d & (1 << i)) {
            x = dp[x][i];
        }
    }
    if(x == y) 
        return x;
    for(int i = 19; i >= 0; --i) {
        if(dp[x][i] != dp[y][i]) {
            x = dp[x][i];
            y = dp[y][i];
        }
    }
    return dp[x][0]; // 返回最近公共祖先的节点编号.
}

inline void kruskal() {
    // init();
    int cnt = n;
    for(int i = 1; i <= n - 1; ++i) {
        int x = find(d[i].a);
        int y = find(d[i].b);
        if(x == y) continue;
        fa[x] = fa[y] = ++cnt;
        add_edge(x, cnt);
        add_edge(y, cnt);
        val[cnt] = d[i].c;
        // dep[cnt] = dep[d[i].a] + 1;
    }
    r = cnt;
}

int tmin[N << 2], tmax[N << 2]; // 整棵树区间上的最小值和最大值
int wmin[N << 2], wmax[N << 2]; // 白点中的最小值和最大值
int tag[N << 2]; // 标记数组，0表示黑色，1表示白色

inline void upd(int p) {
    tmin[p] = min(tmin[ls], tmin[rs]);
    tmax[p] = max(tmax[ls], tmax[rs]);
    wmin[p] = min(wmin[ls], wmin[rs]);
    wmax[p] = max(wmax[ls], wmax[rs]);
}

inline void pushd(int p) {
    if(tag[p] == 0)  {
        // 如果当前节点是黑色，将标记传递给子节点
        tag[ls] = tag[rs] = 0;
        wmin[ls] = wmin[rs] = -0x3f3f3f3f; // 黑色点的值设为无效值
        wmax[ls] = wmax[rs] = 0x3f3f3f3f;
        return;
    }
    // 如果当前节点是白色，将标记传递给子节点
    tag[ls] = tag[rs] = 1;
    wmin[ls] = tmin[ls];
    wmax[ls] = tmax[ls];
    wmin[rs] = tmin[rs];
    wmax[rs] = tmax[rs];
    tag[p] = 0; // 清除当前节点的标记
}

inline void build(int p, int l, int r) {
    tag[p] = 0; // 初始为黑色
    if(l == r) {
        tmin[p] = tmax[p] = dfn[l];
        wmin[p] = wmax[p] = -0x3f3f3f3f; // 白点初始为无效值
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    upd(p);
}

inline void mdf(int p, int l, int r, int L, int R, int color) {
    if(L <= l && r <= R) {
        tag[p] = color; // 更新当前节点的颜色
        if(color == 0) { // 黑色
            tmin[p] = tmax[p];
            wmin[p] = 0x3f3f3f3f; // 黑色点的值设为无效值
            wmax[p] = -0x3f3f3f3f; // 黑色点的值设为无效值
        }
        else { // 白色
            wmax[p] = tmax[p];
            wmin[p] = tmin[p];
        }
        return;
    }
    pushd(p); // 推送标记到子节点
    if(L <= mid) mdf(ls, l, mid, L, R, color);
    if(R > mid) mdf(rs, mid + 1, r, L, R, color);
    upd(p); // 更新当前节点
}

inline int qrymin(int p, int l, int r, int L, int R) {
    if(L <= l && r <= R) {
        return wmin[p]; // 返回当前区间的最小值
    }
    pushd(p); // 推送标记到子节点
    int res = 0x3f3f3f3f; // 初始化为最大值
    if(L <= mid) res = min(res, qrymin(ls, l, mid, L, R));
    if(R > mid) res = min(res, qrymin(rs, mid + 1, r, L, R));
    return res;
}

inline int qrymax(int p, int l, int r, int L, int R) {
    if(L <= l && r <= R) {
        return wmax[p]; // 返回当前区间的最大值
    }
    pushd(p); // 推送标记到子节点
    int res = -0x3f3f3f3f; // 初始化为最小值
    if(L <= mid) res = max(res, qrymax(ls, l, mid, L, R));
    if(R > mid) res = max(res, qrymax(rs, mid + 1, r, L, R));
    return res;
}

int main() {

    n = read();
    q = read();

    init();

    for(int i = 1; i <= n - 1; ++i) {
        d[i].a = read();
        d[i].b = read();
        d[i].c = read();
        // add_edge(d[i].a, d[i].b);
    }

    // dfs(1, 0);

    sort(d + 1, d + n, cmp);

    kruskal();

    dep[r] = 1; // 根节点深度为1

    dfs(r, 0);

    build(1, 1, n);

    while(q--) {
        int op = read();
        if(op == 1) {
            int l = read();
            int r = read();
            mdf(1, 1, n, l, r, 1); // white
        }
        else if(op == 2) {
            int l = read();
            int r = read();
            mdf(1, 1, n, l, r, 0); // black
        }
        else if(op == 3) {
            int t = read();
            // int y = read();
            int x = wmin[1];
            int y = wmax[1];
            writeln(x);
            writeln(y);
            // int lc = lca(id[x], id[y]);
            // writeln(lc);
            // writeln(val[lca(t, lc)]);
        }
    }

    return 0;
}