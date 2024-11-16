#include <bits/stdc++.h>

#define N 500010

using namespace std;

int nxt[N], to[N], head[N], w[N], fee[N];
int now[N];
int dis[N], vis[N];
int d[N];
int n, m, s, t;
int cnt = 1;
int sum = 0;

inline void add(int u, int v, int c, int ww) {
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
    w[cnt] = c;
    fee[cnt] = ww;

    nxt[++cnt] = head[v];
    head[v] = cnt;
    to[cnt] = u;
    w[cnt] = 0;
    fee[cnt] = -ww;
}

inline bool spfa() {
    queue<int> q;
    fill(dis, dis + n + 1, 0x7fffffff);
    dis[s] = 0;
    q.push(s);
    vis[s] = 1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i = head[u]; i; i = nxt[i]) {
            int v = to[i];
            if(w[i] > 0 && dis[v] > dis[u] + fee[i]) {
                dis[v] = dis[u] + fee[i];
                if(!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return (dis[t] != 0x7fffffff);
}

inline int dfs(int x, int flow) {
    if(x == t) 
        return flow;
    int k, ans = 0;
    vis[x] = 1;
    for(int i = head[x]; i && ans < flow; i = nxt[i]) {
        now[x] = i;
        int v = to[i];
        if(!vis[v] && w[i] > 0 && dis[v] == dis[x] + fee[i]) {
            k = dfs(v, min(flow - ans, w[i]));
            if(k) {
                w[i] -= k;
                w[i ^ 1] += k;
                sum += fee[i] * k;
                ans += k;
            }
        }
    }
    vis[x] = 0;
    return ans;
}

inline int dinic() {
    int maxx = 0;
    while(spfa()) {
        maxx += dfs(s, 0x7fffffff);
    }
    return maxx;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> s >> t;
    int u, v, c, ww;
    for(int i = 1; i <= m; ++i) {
        
        cin >> u >> v >> c >> ww;
        add(u, v, c, ww);
    }
    cout << dinic() << " " << sum << endl;
    return 0;
}
