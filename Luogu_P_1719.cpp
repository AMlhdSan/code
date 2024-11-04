#include <bits/stdc++.h>

#define N 121

using namespace std;

int n;
int a[N][N];
int sum[N][N];
int maxx = -0x7fffffff;

int main() {

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            for(int k = i; k <= n; ++k) {
                for(int t = j; t <= n; ++t) {
                    maxx = max(maxx, sum[k][t] + sum[i - 1][j - 1] - sum[k][j - 1] - sum[i - 1][t]);
                }
            }
        }
    }

    cout << maxx << endl;

    return 0;
}