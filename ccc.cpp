#include <bits/stdc++.h>

#define N 3010
#define ll long long

using namespace std;

int n;
ll k[N];
ll a = 0, b = 0;
ll sum = 0;
ll dp[N][N];

inline ll read() {
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

int main() {

    // freopen("express.in", "r", stdin);
    // freopen("express.out", "w", stdout);

    memset(dp, 0x3f, sizeof(dp));

    n = read();

    for(int i = 1; i <= n; ++i) {
        k[i] = read();
    }
    dp[1][0] = k[1];

    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < i; ++j) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + abs(k[i] - k[i - 1]));
            dp[i][i - 1] = min(dp[i][i - 1], dp[i - 1][j] + abs(k[i] - k[j]));
        }
    }

    ll minn = 1e18;

    for (int i = 0; i < n; ++i) {
        minn = min(minn, dp[n][i]);
        cout << dp[n][i] << ' ';
    }

    // cout << minn << endl;

    return 0;
}
