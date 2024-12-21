#include <bits/stdc++.h>

#define N 200010

using namespace std;

int n, m;
int head[N], to[N], nxt[N], w[N];
int e = 0;
double dp[N];
int de[N];
bool vis[N];

inline void add_edge(int u, int v, int c) {
    nxt[++e] = head[u];
    head[u] = e;
    to[e] = v;
    w[e] = c;
}

inline void dfs(int p, int pre) {
    if(p == n) {
        dp[p] = 0;
        return;
    }
    if(vis[p])
        return;
    vis[p] = 1;
    for(int i = head[p]; i; i = nxt[i]) {
        int v = to[i];
        if(v != pre) {
            dfs(v, p);
            dp[p] += (dp[v] + w[i]) / (1.0 * de[p]);
        }
    }
}

int main() {

    cin >> n >> m;

    for(int i = 1; i <= m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        add_edge(u, v, c);
        ++de[u];
    }

    dfs(1, 0);

    printf("%.2f", dp[1]);

    return 0;
}