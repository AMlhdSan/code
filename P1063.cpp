#include <bits/stdc++.h>

#define N 101

using namespace std;

int n;
int a[N << 1];
int dp[N << 1][N << 1];

int main() {

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    a[(n << 1) + 1] = a[1];

    for(int l = 2; l <= n; ++l) {
        for(int i = 1; i <= (n << 1) - l; ++i) {
            int j = i + l - 1;
            for(int k = i; k <= j - 1; ++k) {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + a[i] * a[j + 1] * a[k + 1]);
            }
        }
    }

    int maxx = -0x7fffffff;

    for(int i = 1; i <= n; ++i) {
        maxx = max(maxx, dp[i][i + n - 1]);
    }

    cout << maxx << endl;

    return 0;
}