#include <bits/stdc++.h>

#define N 1000010
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

int T;
int n, m, k;
int head[N], nxt[N], to[N], w[N], e;
int a[20][N];
int dis[N], col[N];
bool vis[N];
int s[N];
int ans;

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

inline void init() {
    memset(head, 0, (n + 5) << 2);
    e = 0;
    ans = INF;
}

inline void add_edge(int u, int v, int c) {
    nxt[++e] = head[u];
    head[u] = e;
    to[e] = v;
    w[e] = c;
}

inline void dijkstra(int bit) {
    memset(dis, 63, (n + 5) << 3);
    memset(vis, 0, (n + 5));
    memset(col, 0, (n + 5) << 2);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    for (int i = 0; i < k; ++i) {
        if (((i >> bit) & 1) == 0) {
            dis[s[i]] = 0;
            col[s[i]] = i + 1;
            q.push({0, s[i]});
        }
    }
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = nxt[i]) {
            int v = to[i];
            if (dis[v] > dis[u] + w[i]) {
                dis[v] = dis[u] + w[i];
                col[v] = col[u];
                q.push({dis[v], v});
            }
        }
    }
    for (int i = 0; i < k; ++i) {
        if ((i >> bit) & 1) {
            int u = s[i];
            if (dis[u] < INF && col[u] && col[u] != i + 1) {
                ans = min(ans, (int)dis[u]);
            }
        }
    }
}

inline void solve() {
    n = read();
    m = read();
    k = read();
    init();
    for (int i = 1; i <= m; ++i) {
        int x = read(), y = read(), z = read();
        add_edge(x, y, z);
    }
    for (int i = 0; i < k; ++i) s[i] = read();
    for (int b = 0; b < 17; ++b) dijkstra(b);
    writeln(ans == INF ? -1 : ans);
}

int main() {
    T = read();
    while (T--) solve();
    return 0;
}
