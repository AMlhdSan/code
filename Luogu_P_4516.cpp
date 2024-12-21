#include <bits/stdc++.h>

#define N 100010
#define K 110

using namespace std;

int n, k;
int dp[N][K][2][2]; // dp[i][j] 表示以 i 为根节点的子树内放了 k 个监听器的最大方案数，[0/1][0/1] 表示是否放了/已覆盖
int e = 0;
int nxt[N * 2], head[N * 2], to[N * 2];

inline void add_edge(int u, int v) {
    nxt[++e] = head[u];
    head[u] = e;
    to[e] = v;
}

inline void dfs(int p, int pre, int t) {
    for(int i = head[p]; i; i = nxt[i]) {
        int v = to[i];
        if(v != pre) {
            for(int i = 1; i <= k; ++i) {
                dfs(v, p, t + 1);
                
            }
        }
    }
}

int main() {

    cin >> n >> k;

    for(int i = 1; i <= n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }

    dfs(1, 0);



    return 0;
}