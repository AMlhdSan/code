#include <bits/stdc++.h>

#define N 110
#define M 110

using namespace std;

int n, q;
int u, vv, w;
vector<pair<int, int> > edges[N];
int dp[N][M];
int siz[N];

void dfs(int p, int pre) {
    siz[p] = 1;
    for(pair<int, int> v : edges[p]) {
        if(v.first != pre) {
            dfs(v.first, p);
            siz[p] += siz[v.first];
        }
    }
    for(pair<int, int> v : edges[p]) {
        if(v.first != pre) {
            for(int i = siz[p]; i >= 1; --i) {
                for(int j = 0; j < i; ++j) {
                    dp[p][i] = max(dp[p][i], dp[p][i - j - 1] + dp[v.first][j] + v.second);
                }
            }
        }
    }
}

int main() {

    cin >> n >> q;

    for(int i = 1; i <= n - 1; ++i) {
        cin >> u >> vv >> w;
        edges[u].push_back(make_pair(vv, w));
        edges[vv].push_back(make_pair(u, w));
    }

    dfs(1, 0);

    cout << dp[1][q] << endl;

    return 0;
}