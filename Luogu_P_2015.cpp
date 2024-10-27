#include <bits/stdc++.h>

#define N 110
#define M 110

using namespace std;

int n, q;
int w[N];
vector<int> edges[N];
int dp[N][M];
int siz[N];

void dfs(int p, int pre) {
    siz[p] = 1;
    for(int v : edge[p]) {
        if(v != pre) {
            
        }
    }
}

int main() {

    cin >> n >> q;

    for(int i = 1; i <= n - 1; ++i) {
        int u, v;
        cin >> u >> v >> w[i];
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    dfs(1, 0);

    return 0;
}