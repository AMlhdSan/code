#include <bits/stdc++.h>

#define N 100010
#define K 21

using namespace std;

int n, k;
vector<int> edges[N];
int c[N];
int dp[N][K]; // 第i个节点距离不超过k的所有节点的权值和.

void add(int u, int v) {
    edges[u].push_back(v);
    edges[v].push_back(u);
}

void dfs(int p, int pre) {
    for(int v : edges[p]) {
        if(v != pre) {
            dfs(v, p);
            for(int i = 1; i <= k; ++i) {
                
            }
        }
    }
}

int main() {

    cin >> n >> k;

    for(int i = 1; i <= n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }

    for(int i = 1; i <= n; ++i) {
        cin >> c[i];
    }

    dfs(1, 0);

    return 0;
}