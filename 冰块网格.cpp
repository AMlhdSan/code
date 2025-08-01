#include <bits/stdc++.h>

#define N 110

using namespace std;

int n;
int dp[N][N];
int maxx = 1;
int maxy = 1;

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    return x * f;
}

int main() {

    // freopen("ice.in", "r", stdin);
    // freopen("ice.out", "w", stdout);

    cin >> n;

    // if(n == 1) {
    //     cout << 1 << endl;
    //     return 0;
    // }

    for(int i = 1; i <= n; ++i) {
        dp[1][i] = dp[i][1] = 1;
    }

    for(int i = 2; i <= n; ++i) {
        for(int j = 2; j <= n; ++j) {
            dp[i][j] = (dp[i - 1][j] * 2 + dp[i][j - 1]) * 2 / 3;
            maxx = max(maxx, dp[i][j]);
        }
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << maxx << endl;
    cout << (int)maxx * maxx << endl;


    return 0;
}