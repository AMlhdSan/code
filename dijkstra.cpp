#include <bits/stdc++.h>

using namespace std;

int n, m, s;
int u, v, w;

struct node {
    int v;
    int c;
};

vector<node> edges[100001];
priority_queue<pair<int, int> > q;
int dis[100001];
bool vis[100001];

void dijkstra() {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, false, sizeof(vis));
    dis[s] = 0;
    q.push(make_pair(0, s));
    while(1) {
        if(q.empty()) 
            return;
        int u = q.top().second;
        q.pop();
        if(vis[u])
            continue;
        vis[u] = true;
        for (node e : edges[u]) {
			int v = e.v;
			if (dis[v] > dis[u] + e.c) {
				dis[v] = dis[u] + e.c;
				q.push(make_pair(-dis[v], v));
			}
		}
    }
}

int main() {

    cin >> n >> m >> s;

    for(int i = 1; i <= m; ++i) {
        cin >> u >> v >> w;
        node tmp;
        tmp.v = v;
        tmp.c = w;
        edges[u].push_back(tmp);
    }
    
    dijkstra();

    for (int i = 1; i <= n; ++i)
		cout << (dis[i] == 0x3f3f3f3f ? 2147483647 : dis[i]) << ' ';
	cout << endl;
    return 0;
}