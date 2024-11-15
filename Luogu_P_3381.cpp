#include <bits/stdc++.h>
#define N 500010

using namespace std;

long long nxt[N], to[N], head[N], w[N], fee[N];
long long now[N];
long long dis[N], vis[N];
int d[N];
long long n, m, s, t;
long long cnt = 1;
long long sum = 0;

inline void add(int u, int v, long long c, long long ww) {
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

inline long long dfs(int x, long long flow) {
    if(x == t) 
        return flow;
    long long k, ans = 0;
    for(int &i = now[x]; i && ans < flow; i = nxt[i]) {
        now[x] = i;
        int v = to[i];
        if(dis[v] != dis[x] + fee[i] || w[i] <= 0) 
            continue;
        k = dfs(v, min(flow - ans, w[i]));
        if(k) {
            w[i] -= k;
            w[i ^ 1] += k;
            sum += fee[i] * k;
            ans += k;
        }
    }
    return ans;
}

inline long long dinic() {
    long long maxx = 0;
    while(spfa()) {
        maxx += dfs(s, 0x7fffffff);
    }
    return maxx;
}

int main() {
    cin >> n >> m >> s >> t;
    for(int i = 1; i <= m; ++i) {
        long long u, v, c, ww;
        cin >> u >> v >> c >> ww;
        add(u, v, c, ww);
    }
    cout << dinic() << " " << sum << endl;
    return 0;
}
