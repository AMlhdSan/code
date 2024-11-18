#include <bits/stdc++.h>

#define M 6210

using namespace std;

int n, m;
int s, t;

int nxt[M], head[M], to[M], w[M];
bool vis[M];
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
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while(!q.empty()) {
        
    }
}

int main() {

    cin >> n >> m >> s >> t;

    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }

    return 0;
}