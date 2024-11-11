#include <bits/stdc++.h>

#define INF 0x7fffffff
#define ll long long
#define N 5010

using namespace std;

int n, m;
int s, t;
long long ans;
vector<pair<int, ll> > edges[N];
int dis[N], now[N];

void add(int u, int v, ll w) {
    edges[u].push_back(make_pair(v, w));
    edges[v].push_bakc(make_pair(u, 0));
}

bool bfs() {
    fill(dis, dis + n + 1, MAXX);
}

int main() {

    cin >> n >> m >> s >> t;

    while(m--) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        add(u, v, w);
    }

    while(bfs()) {
        ans += dfs(s, maxx);
    }

    cout << ans << endl;

    return 0;
}