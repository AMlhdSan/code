#include <bits/stdc++.h>

#define N 3010
#define M 4010
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f

using namespace std;

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

int n, m;
ll dis[N][N];
int s1, t1, p1, s2, t2, p2;

// 链式前向星
struct Edge {
    int to, nxt;
} edge[M << 1];
int head[N], cnt;

void add_edge(int u, int v) {
    edge[++cnt].to = v;
    edge[cnt].nxt = head[u];
    head[u] = cnt;
}

void bfs(int s) {
    queue<pair<int, ll>> q;
    int vis[N] = {0};
    q.push({s, 0}); 
    vis[s] = 1; 
    dis[s][s] = 0;
    
    while (!q.empty()) {
        int u = q.front().first;
        ll d = q.front().second;
        q.pop();
        
        for (int i = head[u]; i; i = edge[i].nxt) {
            int v = edge[i].to;
            if (vis[v] == 1) continue;
            dis[s][v] = d + 1;
            q.push({v, d + 1});
            vis[v] = 1;
        }
    }
}

int main() {
    // freopen("buff.in", "r", stdin);
    // freopen("buff.out", "w", stdout);
    
    memset(dis, 0x3f, sizeof(dis));
    memset(head, 0, sizeof(head));
    cnt = 0;
    
    n = read();
    m = read();
    
    for(int i = 1; i <= m; ++i) {
        int x = read();
        int y = read();
        add_edge(x, y);
        add_edge(y, x);
    }
    
    s1 = read();
    t1 = read();
    p1 = read();
    s2 = read();
    t2 = read();
    p2 = read();
    
    for(int i = 1; i <= n; ++i) {
        bfs(i);
    }
    
    if (p1 < dis[s1][t1] || p2 < dis[s2][t2]) {
        writeln(-1);
        return 0;
    }
    
    ll ans = inf;
    
    for(int x = 1; x <= n; ++x) {
        for(int y = 1; y <= n; ++y) {
            if (p1 >= dis[s1][x] + dis[x][y] + dis[y][t1] && p2 >= dis[s2][x] + dis[x][y] + dis[y][t2]) {
                ans = min(ans, dis[s1][x] + dis[s2][x] + dis[x][y] + dis[y][t1] + dis[y][t2]);
            }
            if (p1 >= dis[s1][x] + dis[x][y] + dis[y][t1] && p2 >= dis[t2][x] + dis[x][y] + dis[y][s2]) {
                ans = min(ans, dis[s1][x] + dis[t2][x] + dis[x][y] + dis[y][s2] + dis[y][t1]);
            }
        }
    }
    
    ll aans = dis[s1][t1] + dis[s2][t2];
    writeln(m - min(ans, aans));
    
    return 0;
}