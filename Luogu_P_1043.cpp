#include <bits/stdc++.h>

#define N 51
#define M 10

using namespace std;

int n, m;
int a[N << 1];
int big[N << 1][N << 1][M];
int small[N << 1][N << 1][M];
int sum[N << 1];

int upd(int x) {
    x %= 10;
    if(x < 0) {
        x += 10;
    }
    return x;
}

int main() {

    cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[n + i] = a[i];
    }

    for(int i = 1; i <= (n << 1); ++i) {
        sum[i] = sum[i - 1] + a[i];
    }

    for(int i = 1; i <= (n << 1); ++i) {
        for(int j = i; j <= (n << 1); ++j) {
            for(int k = 1; k <= m; ++k) {
                big[i][j][k] = -0x7fffffff;
                small[i][j][k] = 0x7fffffff;
            }
        }
    }

    for(int i = 1; i <= (n << 1); ++i) {
        for(int j = i; j <= (n << 1); ++j) {
            big[i][j][1] = upd(sum[j] - sum[i - 1]);
            small[i][j][1] = upd(sum[j] - sum[i - 1]);
        }
    }

    for(int l = 2; l <= m; ++l) {
        for(int i = 1; i <= (n << 1); ++i) {
            for(int j = i + l - 1; j <= (n << 1); ++j) {
                for(int k = i + l - 2; k < j; ++k) {
                    big[i][j][l] = max(big[i][j][l], big[i][k][l - 1] * upd(sum[j] - sum[k]));
                    small[i][j][l] = min(small[i][j][l], small[i][k][l - 1] * upd(sum[j] - sum[k]));
                }
            }
        }
    }

    int maxx = -0x7fffffff, minn = 0x7fffffff;

    for(int i = 1; i <= n; ++i) {
        maxx = max(maxx, big[i][i + n - 1][m]);
        minn = min(minn, small[i][i + n - 1][m]);
    }

    cout << minn << endl << maxx;

    return 0;
}