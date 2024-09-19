#include <bits/stdc++.h>
using namespace std;

int n, m, s = 1;
int ans = 0;

struct Edge {
    int v;
    int c;
}tmp;

vector<Edge> edges[5001];
priority_queue<pair<int, int> > pq;
bool vis[5001];
int dis[5001];

bool prim() {
    int cnt = 0;

    memset(dis, 0x3f, sizeof(dis));
    memset(vis, false, sizeof(vis));

    dis[1] = 0;

    pq.push(make_pair(0, 1));

    while(!pq.empty()) {
        if(cnt >= n)
            break;
        int u = pq.top().second;
        int cc = pq.top().first;
        pq.pop();
        if(vis[u])
            continue;
        vis[u] = true;
        ++cnt;
        ans -= cc;
        for(Edge e : edges[u]) {
            int v = e.v;
            int c = e.c;
            if(dis[v] > c) {
                dis[v] = c;
                pq.push(make_pair(- c, v));
            }
        }
    }
    if(cnt == n) {
        return true;
    }
    else {
        return false;
    }
}

int main() {

    cin >> n >> m;

    for(int i = 1; i <= m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        tmp.c = c;
        tmp.v = v;
        edges[u].push_back(tmp);
        tmp.v = u;
        edges[v].push_back(tmp);
    }

    if(prim()) {
        cout << ans << endl;
    }
    else {
        cout << "orz" << endl;
    }
    return 0;
}