#include <bits/stdc++.h>

using namespace std;

int n, m, s;
int u, v, w;

struct node {
    int v;
    int c;
};

vector<node> edges[100001];
priority_queue<pair<int, int>, vector<int>, greater<int> > q;
int dis[100001];
bool vis[100001];

void dijkstra() {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, false, sizeof(vis));
    dis[s] = 0;
    q.push({0, s});
}

int main() {

    cin >> n >> m >> s;

    for(int i = 1; i <= m; ++i) {
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
    }
    
    dijkstra();


    return 0;
}