#include <bits/stdc++.h>

#define N 100010

using namespace std;

int n;
int dp[N];
int c[N];
bool vis[N];
int maxx = 0;

vector<int> edges[N];

void add_edge(int u, int v) {
    edges[u].push_back(v);
    edges[v].push_back(u);
}

void dfs(int p, int pre) {
    vis[p] = 1;
    for(int v : edges[p]) {
        if(v != pre) {
            dfs(v, p);
            maxx = max(maxx, dp[v] + dp[p] + 1);
            dp[p] = max(dp[p], dp[v] + 1);
        }
    }
}

int main() {

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> c[i];
    }

    for(int i = 1; i <= n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        if(c[u] == c[v]) {
            continue;
        }
        add_edge(u, v);
    }

    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) {
            dfs(i, i);
        }
    }

    cout << maxx + 1 << endl;

    return 0;
}