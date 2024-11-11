#include <bits/stdc++.h>

#define MAXX 0x7fffffff
#define ll long long

using namespace std;

struct Edge {
    int to;
    ll val;
};

int n, m, s, t;
ll ans;
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
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(const auto& edge : adj[x]) {
            int v = edge.to;
            if(edge.val > 0 && dis[v] == MAXX) {
                q.push(v);
                dis[v] = dis[x] + 1;
                now[v] = 0;
                if(v == t) 
                    return true;
            }
        }
    }
    return false;
}

ll dfs(int x, ll flow) {
    if(x == t) 
        return flow;
    ll res = 0;
    for(int& i = now[x]; i < adj[x].size() && flow; ++i) {
        Edge& edge = adj[x][i];
        int v = edge.to;
        if(edge.val > 0 && dis[v] == dis[x] + 1) {
            ll k = dfs(v, min(flow, edge.val));
            if(k == 0) 
                dis[v] = MAXX;
            edge.val -= k;
            for(auto& rev_edge : adj[v]) { 
                if (rev_edge.to == x) {
                    rev_edge.val += k;
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
    cin >> n >> m;
    s = 1;
    t = m;
    adj.resize(m + 1);
    dis.resize(m + 1);
    now.resize(m + 1);
    for (int i = 1; i <= n; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    while (bfs()) {
        ans += dfs(s, MAXX);
    }
    cout << ans << endl;
    return 0;
}
