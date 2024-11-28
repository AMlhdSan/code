#include <bits/stdc++.h>
using namespace std;

int n, m;
int f[101][101];
int u, v, w;

int main() {

    cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            f[i][j] = 0x3f3f3f3f;
            if(i == j) {
                f[i][j] = 0;
            }
        }
    }

    for(int i = 1; i <= m; ++i) {
        cin >> u >> v >> w;
        f[u][v] = min(f[u][v], w);
        f[v][u] = f[u][v];
    }

    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cout << f[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}