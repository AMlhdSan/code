#include <bits/stdc++.h>

#define N 3010
#define K 3010
#define M 3010

using namespace std;

int n, m, k[N];
int aa, cc, fee[N];
int dp[N][M];
vector<pair<int, int> > edges[N];

int dfs(int p) {
    if(p <= n && p >= n - m + 1) { // 叶子结点
        dp[p][1] = fee[p];
        return 1;
    }
    int siz = 0;
    for(pair<int, int> v : edges[p]) {
        siz += dfs(v.first);

        for(int i = siz; i >= 0; --i) {
            for(int j = 0; j <= i; ++j) {
                dp[p][i] = max(dp[p][i], dp[p][i - j] + dp[v.first][j] - v.second);
            }
        }
    }
    return siz;
}

int main() {

    memset(dp, ~0x3f, sizeof(dp));

    cin >> n >> m;
    m = min(m, n);

    for(int i = 1; i <= n - m; ++i) {
        cin >> k[i];
        for(int j = 1; j <= k[i]; ++j) {
            cin >> aa >> cc;
            edges[i].push_back(make_pair(aa, cc));
        }
        dp[i][0] = 0;
    }

    for(int i = n - m + 1; i <= n; ++i) {
        cin >> fee[i];
        dp[i][0] = 0;
    }

    dfs(1);

    for(int i = m; i >= 1; --i) {
        if(dp[1][i] >= 0) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}