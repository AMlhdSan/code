#include <bits/stdc++.h>

#define N 100001
#define M 16

using namespace std;

int n;
vector<int> edges[N];
int dp[N][M];

void add_edge(int u, int v) {
    edges[u].push_back(v);
    edges[v].push_back(u);
}

void dfs(int p, int pre) {
    for(int i = 1; i <= M; ++i) {
		dp[p][i] = i;
	}
    for(int v : edges[p]) {
        if(v != pre) {
            dfs(v, p);
            for(int i = 1; i <= M; ++i) {
                int minn = 0x7fffffff;
                for(int j = 1; j <= M; ++j) {
                    if(i != j) {
                        minn = min(minn, dp[v][j]);
                    }
                }
                dp[p][i] += minn;
            }
        }
    }
}

int main() {

    cin >> n;

    for(int i = 1; i <= n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }

    dfs(1, 0);

    int minn = 0x7fffffff;

    for(int i = 1; i <= M; ++i) {
        minn = min(minn, dp[1][i]);
    }

    cout << minn << endl;
    return 0;
}