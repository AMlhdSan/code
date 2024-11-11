#include <bits/stdc++.h>
#define MAXX 0x7fffffff
#define N 10005  // 根据题目需求设定一个足够大的常数
using namespace std;

struct Edge {
    int to;
    long long val;
};

int n, m, s, t;
long long ans;
vector<Edge> adj[N];  // 使用数组形式来存储邻接表
int dis[N];           // 距离数组
int now[N];           // 当前弧数组

void add(int u, int v, long long w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, 0});
}

bool bfs() {
    fill(dis, dis + n + 1, MAXX);
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    now[s] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < adj[x].size(); ++i) {
            int v = adj[x][i].to;
            if (adj[x][i].val > 0 && dis[v] == MAXX) {
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
    for (int i = now[x]; i < adj[x].size() && flow; ++i, ++now[x]) {
        int v = adj[x][i].to;
        if (adj[x][i].val > 0 && dis[v] == dis[x] + 1) {
            long long k = dfs(v, min(flow, adj[x][i].val));
            if (k == 0) dis[v] = MAXX;
            adj[x][i].val -= k;
            
            // 找到相应的反向边更新其容量
            for (int j = 0; j < adj[v].size(); ++j) {
                if (adj[v][j].to == x) {
                    adj[v][j].val += k;
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
