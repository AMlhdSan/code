#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 1000000 + 5;

vector<int> adj[MAXN];
int a[MAXN]; 
int flips[MAXN];


int dfs(int nd, int fa, int odd, int even) {
    int cnt = 0;

    int now = (a[nd] + odd) % 2;
    if (now != 0) {
        ++cnt;
        odd ^= 1;
    }

    for (int v : adj[nd]) {
        if (v == fa) continue;
        cnt += dfs(v, nd, even, odd);
    }

    return cnt;
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << dfs(1, -1, 0, 0) << endl;
    return 0;
}
