#include <bits/stdc++.h>

#define N 100010
#define K 21

using namespace std;

int n, k;
int c[N];
int head[N << 1], nxt[N << 1], to[N << 1], w[N << 1];
int e = 0;
int dp[N][K]; // 第i个节点距离不超过k的所有节点的权值和.
int ans[N][K];// 

void add(int u, int v) {
    nxt[++e] = head[u];
    head[u] = e;
    to[e] = v;
}

void dfs(int p, int pre) {
    for(int i = 0; i <= k; ++i) {
        dp[p][i] = c[p];
    }
    for(int i = head[p]; i; i = nxt[i]) {
        int v = to[i];
        if(v != pre) {
            dfs(v, p);
            for(int i = 1; i <= k; ++i) {
                dp[p][i] += dp[v][i - 1];
            }
        }
    }
}

void _dfs_(int p, int pre) {
    for(int i = head[p]; i; i = nxt[i]) {
        int v = to[i];
        if(v != pre) {
            // dfs(v, p);
            ans[v][1] += dp[p][0];
            for(int i = 2; i <= k; ++i) {
                ans[v][i] += ans[p][i - 1] - dp[v][i - 2];
            }
            _dfs_(v, p);
        }
    }
}

int main() {

    cin >> n >> k;

    for(int i = 1; i <= n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }

    for(int i = 1; i <= n; ++i) {
        cin >> c[i];
    }

    dfs(1, 0);

    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= k; ++j) {
            ans[i][j] = dp[i][j];
        }
    }

    _dfs_(1, 0);

    for(int i = 1; i <= n; ++i) {
        cout << ans[i][k] << endl;
    }

    return 0;
}