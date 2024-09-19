#include <bits/stdc++.h>
using namespace std;

int n, m, s;
struct Edge {
    int v, c;
}tmp;
vector<Edge> edges[100005];
int dis[100005];
bool vis[100005];
priority_queue<pair<int, int> , vector<pair<int, int> >, greater<pair<int, int> > > pq;

void dijkstra() {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, false, sizeof(vis));
    dis[s] = 0;
    pq.push(make_pair(0, s));
    
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if(vis[u])
            continue;
        vis[u] = true;

        for(Edge e : edges[u]) {
            if(dis[e.v] > dis[u] + e.c) {
                dis[e.v] = dis[u] + e.c;
                pq.push(make_pair(dis[e.v], e.v));
            }
        }
    }
}

int main() {

    cin >> n >> m >> s;

    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        tmp.c = w;
        tmp.v = v;
        edges[u].push_back(tmp);
    }

    dijkstra();

    for(int i = 1; i <= n; ++i)
        cout << (dis[i] == 0x3f3f3f3f ? 2147483647 : dis[i]) << ' ';
    return 0;
}