#include <bits/stdc++.h>

#define MOD 1000000007
#define N 110
#define int long long

using namespace std;

int n, l, r, k;
int a[N];
vector<int> edges[N];
int f[N][N][N], sz[N];
int tmp[N][N];

void dfs(int x, int T) {
    for(int i = 0; i <= sz[x]; ++i) {
        for(int j = 0; j <= sz[x]; ++j) {
            f[x][i][j] = 0;
        }
    }
    f[x][0][0] = 1, sz[x] = 0;
    for(int y : edges[x]) {
        dfs(y, T);
        for(int i = 0; i <= sz[x]; ++i) {
            for(int j = 0; j <= sz[x]; ++j) {
                tmp[i][j] = f[x][i][j];
                f[x][i][j] = 0;
            }
        }
        for(int i = 0; i <= sz[x]; ++i) {
            for(int j = 0; j <= sz[y]; ++j) {
                for(int a = 0; a <= sz[x]; ++a) {
                    for(int b = 0; b <= sz[y]; ++b) {
                        f[x][i + j][a + b] += 1ll * tmp[i][a] * f[y][j][b];
                        f[x][i + j][a + b] %= MOD;
                    }
                }
            }
        }
        sz[x] += sz[y];
    }
    if(a[x] == T) {
		for(int i = 0; i <= sz[x]; ++i) 
            for(int j = 0; j <= sz[x]; ++j)
			    tmp[i][j] = f[x][i][j], f[x][i][j] = 0;

		for(int i = 0; i <= sz[x]; ++i) 
            for(int j = 0; j <= sz[x]; ++j)
			    f[x][i][j] += tmp[i][j];

		for(int i = 0;i <= sz[x]; ++i) 
            for(int j = 0; j <= sz[x]; ++j)
			    f[x][i + 1][j + ((i + 1) >= k)] += tmp[i][j];
		sz[x] += 1;
	}
}

int g[N][N];
int tmph[N];
int h[N];

signed main() {

    // freopen("occur.in", "r", stdin);
    // freopen("occur.out", "w", stdout);

    cin >> n >> l >> r >> k;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for(int i = 2; i <= n; ++i) {
        int t;
        cin >> t;
        edges[t].push_back(i);
    }

    h[0] = 1;
    int cnt = 0;

    for(int c = 1; c <= n; ++c) {
        dfs(1, c);
        for(int i = 0; i <= sz[1]; ++i) {
            for(int j = 0; j <= sz[1]; ++j) {
                g[c][j] += f[1][i][j];
            }
        }
        for(int i = 0; i <= cnt; ++i) {
            tmph[i] = h[i];
            h[i] = 0;
        }
        for(int i = 0; i <= cnt; ++i) {
            for(int j = 0; j <= sz[1]; ++j) {
                h[i + j] += 1ll * tmph[i] * g[c][j];
                h[i + j] %= MOD;
            }
        }
        cnt += sz[1];
    }

    int ans = 0;

	for(int i = l; i <= r; ++i) 
        ans += h[i], ans %= MOD;
	cout << ans;

    return 0;
}