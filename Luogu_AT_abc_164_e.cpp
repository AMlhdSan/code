#include <bits/stdc++.h>

#define N 210
#define M 1500

using namespace std;
#define int long long

int n, m, s;
int uu[M], vv[M], ss[M], tt[M];
int c[N], d[N];
long long dis[N][2455];
bool vis[N][2455];
struct edge {
    int x, p, t;
};
vector<edge> g[N][2455];
struct node {
    int x, p;
    long long t;
    bool operator<(const node &a) const {
        return t > a.t;
    }
};
priority_queue<node> pq;
inline void init() {
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 2455; ++j) {
            g[i][j].clear();
        }
    }
}
inline void add_edge(int u, int v, int p, int t) {
    for (int j = p; j <= 2450; ++j) {
        g[u][j].push_back(edge{v, j - p, t});
        g[v][j].push_back(edge{u, j - p, t});
    }
}
inline void add_coin_edge(int i, int c, int d) {
    for (int j = c; j <= 2450; ++j) {
        g[i][j - c].push_back(edge{i, j, d});
    }
}


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

signed main() {

    init();
    n = read();
    m = read();
    s = read();
    s = min(s, 2450LL);
    for (int i = 1; i <= m; ++i) {
        uu[i] = read();
        vv[i] = read();
        ss[i] = read();
        tt[i] = read();
        add_edge(uu[i], vv[i], ss[i], tt[i]);
    }
    for (int i = 1; i <= n; ++i) {
        c[i] = read();
        d[i] = read();
        add_coin_edge(i, c[i], d[i]);
    }
    dis[1][s] = 0;
    pq.push(node{1, s, 0});
    while (!pq.empty()) {
        node k = pq.top();
        pq.pop();
        int a = k.x, b = k.p;
        long long c = k.t;
        if (vis[a][b]) {
            continue;
        }
        vis[a][b] = true;
        for (const auto &f : g[a][b]) {
            int x = f.x, y = f.p, z = f.t;
            if (c + z < dis[x][y]) {
                dis[x][y] = c + z;
                pq.push(node{x, y, c + z});
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        long long ans = 0x3f3f3f3f3f3f3f3f;
        for (int j = 0; j <= 2450; ++j) {
            ans = min(ans, dis[i][j]);
        }
        writeln(ans);
    } 

    return 0;
}