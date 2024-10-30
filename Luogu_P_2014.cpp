#include <bits/stdc++.h>

#define N 305
#define M 305
#define INF 0x7fffffff

using namespace std;

int n, m;
int k, s[N];
vector<int> edges[N];
int dp[N][M]; // 以i为根节点的子树中取j个的最大学分
int siz[N];

void dfs(int p) {
    siz[p] = 1;
    dp[p][1] = s[p];
    for(int v : edges[p]) {
        dfs(v);
        siz[p] += siz[v];
    }
    for (int v : edges[p]) {
        for (int i = siz[p]; i >= 2; --i) {
            for (int j = 0; j <= min(i - 1, siz[v]); ++j) {
                dp[p][i] = max(dp[p][i], dp[p][i - j] + dp[v][j]);
            }
        }
    }
}

int main() {

    cin >> n >> m;

    m = min(m, n);

    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        cin >> k >> s[i];
        edges[k].push_back(i);
    }

    dfs(0);

    cout << dp[0][m + 1] << endl;

    return 0;
}
