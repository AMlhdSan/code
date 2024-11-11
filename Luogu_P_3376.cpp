#include <bits/stdc++.h>
#define MAXX 0x7fffffff
using namespace std;

struct Edge {
    int to;
    long long val;
};

int n, m, s, t;
long long ans;
vector<vector<Edge> > adj;
vector<int> dis, now;

void add(int u, int v, long long w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, 0});
}

bool bfs() {
    fill(dis.begin(), dis.end(), MAXX);
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    now[s] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (const auto& edge : adj[x]) {
            int v = edge.to;
            if (edge.val > 0 && dis[v] == MAXX) {
                q.push(v);
                dis[v] = dis[x] + 1;
                now[v] = 0;
                if (v == t) return true;
            }
        }
    }
    return false;
}

long long dfs(int x, long long flow) {
    if (x == t) return flow;
    long long res = 0;
    for (int& i = now[x]; i < adj[x].size() && flow; ++i) {
        Edge& edge = adj[x][i];
        int v = edge.to;
        if (edge.val > 0 && dis[v] == dis[x] + 1) {
            long long k = dfs(v, min(flow, edge.val));
            if (k == 0) dis[v] = MAXX; // 剪枝
            edge.val -= k;             // 更新正向边容量
            for (auto& rev_edge : adj[v]) { 
                if (rev_edge.to == x) { 
                    rev_edge.val += k; // 更新反向边容量
                    break;
                }
            }
            res += k;
            flow -= k;
        }
    }
    return res;
}

int main() {
    cin >> n >> m >> s >> t;
    adj.resize(n + 1);
    dis.resize(n + 1);
    now.resize(n + 1);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    while (bfs()) {
        ans += dfs(s, MAXX);
    }
    cout << ans << endl;
    return 0;
}
