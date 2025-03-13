#include <bits/stdc++.h>

#define N 505
#define ll long long
#define INF 1e18

using namespace std;

int n, m;
ll k;
ll A[N][N];
ll dp[N][N];
ll pref[N][N];
ll rowCost[N][N];

inline ll read() {
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

inline void write(ll x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }


    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(ll x) {
    write(x);
    putchar('\n');
}

int main() {
    // freopen("escape.in", "r", stdin);
    // freopen("escape.out", "w", stdout);
    n = read();
    m = read();
    k = read();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = read();
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = INF;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int d = 0; d < m; d++) {
            pref[d][0] = 0;
            for (int j = 0; j < m; j++) {
                pref[d][j+1] = pref[d][j] + A[i][(j + d) % m];
            }
        }
        
        for (int c = 0; c < m; c++) {
            for (int j = c; j < m; j++) {
                rowCost[c][j] = INF;
                for (int d = 0; d < m; d++) {
                    ll candidate = k * d + (pref[d][j+1] - pref[d][c]);
                    rowCost[c][j] = min(rowCost[c][j], candidate);
                }
            }
        }
        
        if (i == 0) {
            for (int j = 0; j < m; j++) {
                dp[0][j] = rowCost[0][j];
            }
        } else {
            for (int j = 0; j < m; j++) {
                for (int x = 0; x <= j; x++) {
                    dp[i][j] = min(dp[i][j], dp[i-1][x] + rowCost[x][j]);
                }
            }
        }
    }
    
    writeln(dp[n-1][m-1]);
    
    return 0;
}