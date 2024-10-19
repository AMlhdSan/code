#include <bits/stdc++.h>

#define N 10001
#define M 101

using namespace std;

int n, m;
int a[M << 1], b[N << 1];
int dp[N << 1];
int maxx = -0x7fffffff;

int main() {

    cin >> n >> m;

    fill(dp + 1, dp + n + 1, -0x7fffffff);

    for(int i = 1; i <= m; ++i) {
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }

    for(int i = 1; i <= n; ++i) {
        cin >> b[i];
    }

    dp[1] = b[1];

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(i - a[j] >= 1)
                dp[i] = max(dp[i], dp[i - a[j]] + b[i]);
        }
    }

    int ans = -0x7fffffff;

    for(int i = n; i >= n - maxx + 1; --i) {
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;

    return 0;
}