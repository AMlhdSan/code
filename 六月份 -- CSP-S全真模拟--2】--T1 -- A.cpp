#include <bits/stdc++.h>

#define N 30

using namespace std;

int n, m;
int t[N][N];
int sum[N];

int so(int p) {

}

int main() {

    memset(t, 0, sizeof(t));

    cin >> n >> m;

    for(int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        t[x][y] = t[y][x] = 1;
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            sum[i] += t[i][j];
        }
    }

    // for(int i = 1; i <= n; ++i) {
    //     cout << sum[i] << endl;
    // }

    for(int i = 0; i <= m; ++i) {
        cout << so(i) << ' ';
    }

    return 0;
}