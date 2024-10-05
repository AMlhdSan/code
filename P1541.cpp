#include <bits/stdc++.h>

#define N 351
#define M 121
#define DP 41

using namespace std;

int n, m;
int a[N];
int b[M];
int dp[DP][DP][DP][DP];
int x, y, z, w;

int main() {

    cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for(int i = 1; i <= m; ++i) {
        cin >> b[i];
        if(b[i] == 1) {
            ++x;
        }
        else if(b[i] == 2) {
            ++y;
        }
        else if(b[i] == 3) {
            ++z;
        }
        else if(b[i] == 4) {
            ++w;
        }
    }

    dp[0][0][0][0] = a[1];

    for(int i = 0; i <= x; ++i) {
        for(int j = 0; j <= y; ++j) {
            for(int k = 0; k <= z; ++k) {
                for(int l = 0; l <= w; ++l) {
                    int now = 1 + i * 1 + j * 2 + k * 3 + l * 4;
                    if(i != 0)
                        dp[i][j][k][l] = max(dp[i - 1][j][k][l] + a[now], dp[i][j][k][l]);
                    if(j != 0) 
                        dp[i][j][k][l] = max(dp[i][j - 1][k][l] + a[now], dp[i][j][k][l]);
                    if(k != 0)
                        dp[i][j][k][l] = max(dp[i][j][k - 1][l] + a[now], dp[i][j][k][l]);
                    if(l != 0)
                        dp[i][j][k][l] = max(dp[i][j][k][l - 1] + a[now], dp[i][j][k][l]);
                }
            }
        }
    }

    cout << dp[x][y][z][w] << endl;

    return 0;
}