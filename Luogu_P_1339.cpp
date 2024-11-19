#include <bits/stdc++.h>

#define M 62100

using namespace std;

int n, m;
int s, t;

int nxt[M], head[M], to[M], w[M];
int dis[M];
int cnt = 0;

void add(int u, int v, int c) {
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
    w[cnt] = c;

    nxt[++cnt] = head[v];
    head[v] = cnt;
    to[cnt] = u;
    w[cnt] = c;
}

void dijkstra() {
    priority_queue<pair<int, int> , vector<pair<int, int> >, greater<pair<int, int> > > q;
    q.push(make_pair(0, s));
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    while(!q.empty()) {
        pair<int, int> x = q.top();
        q.pop();
        for(int i = head[x.second]; i; i = nxt[i]) {
            int v = to[i];
            if(dis[v] > dis[x.second] + w[i]) {
                dis[v] = dis[x.second] + w[i];
                q.push(make_pair(dis[v], v));
            }
        }
    }
}

int main() {

    cin >> n >> m >> s >> t;

    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }

    dijkstra();

    cout << dis[t] << endl;

    return 0;
}