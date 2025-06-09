#include <bits/stdc++.h>

#define N 100010

using namespace std;

int n, m, k;
int s, t;
int head[N], to[N], w[N], nxt[N], e = 0;
int dis[N][20]; // 第 i 个点到起点经过边的最小值，最多 j 条边权值变为 0.
int flg[N][20]; // 标记是否已经访问过

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

inline void add_edge(int u, int v, int c) {
    to[++e] = v;
    w[e] = c;
    nxt[e] = head[u];
    head[u] = e;

    to[++e] = u;
    w[e] = c;
    nxt[e] = head[v];
    head[v] = e;
}

inline void upd(int p) {
    tree[p] = min(tree[p << 1], tree[p << 1 | 1]);
}

inline void pushd(int p) {
    lazy[p << 1] += lazy[p];
    lazy[p << 1 | 1] += lazy[p];
    tree[p << 1] += lazy[p];
    tree[p << 1 | 1] += lazy[p];
    lazy[p] = 0;
    return;
}

inline void build(int p, int l, int r) {
    if(l == r) {
        tree[p] = a[l];
        return;
    }
    build(p << 1, l, (l + r) >> 1);
    build(p << 1 | 1, ((l + r) >> 1) + 1, r);
    upd(p);
    return;
}

inline void mdf(int p, int l, int r, int ql, int qr, int x) {
    if(ql <= l && r <= qr) {
        lazy[p] += x;
        tree[p] += siz[p] * x;
        return;
    }
    pushd(p);
    
    int mid = (l + r) >> 1;
    if(ql <= mid) {
        mdf(p << 1, l, mid, ql, qr, x);
    }
    if(mid < qr){
        mdf(p << 1 | 1, mid + 1, r, ql, qr, x);

    }
    upd(p);
    if(p <= n) {
        siz[p] = siz[p << 1] + siz[p << 1 | 1];
    }
    return;

}

inline void dijsktra() {
    memset(dis, 0x3f, sizeof(dis));

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    dis[s][0] = 0;
    pq.push({0, s, 0});

    while(!pq.empty()) {
        auto [d, u, cnt] = pq.top();
        pq.pop();

        if(flg[u][cnt]) continue;

        flg[u][cnt] = 1;

        for(int i = head[u]; i; i = nxt[i]) {
            int v = to[i];
            int c = w[i];

            if(cnt < k && dis[v][cnt + 1] > d) {
                dis[v][cnt + 1] = d;
                pq.push({d, v, cnt + 1});
            }

            if(dis[v][cnt] > d + c) {
                dis[v][cnt] = d + c;
                pq.push({dis[v][cnt], v, cnt});
            }
        }
    }

    int ans = INT_MAX;
    for(int i = 0; i <= k; ++i) {
        ans = min(ans, dis[t][i]);
    }

    writeln(ans);
}

int main() {

    n = read();
    m = read();
    k = read();

    s = read();
    ++s;
    t = read();
    ++t;

    for(int i = 1; i <= m; ++i) {
        int a, b, c;
        a = read();
        b = read();
        c = read();
        add_edge(a + 1, b + 1, c);
    }

    dijsktra();

    return 0;
}