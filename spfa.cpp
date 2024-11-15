#include <bits/stdc++.h>

#define M 200010

using namespace std;

int n, m, s;
int nxt[M], head[M], to[M], w[M];
int cnt = 0;
int dis[M];
bool vis[M];

void add(int u, int v, int c) {
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
    w[cnt] = c;
}

void spfa() {
    queue<int> q;
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    q.push(s);
    vis[s] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i = head[u]; i; i = nxt[i]) {
            int v = to[i];
            if(dis[v] > dis[u] + w[i]) {
                dis[v] = dis[u] + w[i];
                if(!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
}

int main() {

    ios::sync_with_stdio(false);

    cin >> n >> m >> s;
    while(m--) {
        int u, v, c;
        cin >> u >> v >> c;
        add(u, v, c);
    }

    spfa();

    for(int i = 1; i <= n; ++i)
		cout << (dis[i] == 0x3f3f3f3f ? 2147483647 : dis[i]) << ' ';
    cout << endl;

    return 0;
}