#include <bits/stdc++.h>

#define N 10010
#define M 1010

using namespace std;

int n, m, k;
int px[N], py[N];
int dp[N][M];
bool flag[N][M];

struct node {
    int l, r, p;
}t[N];

inline int read() {
    int x = 0, f = 1; 
    char ch = getchar();
    while(ch < '0' || ch > '9') { 
        if (ch == '-') 
        f = -1; 
        ch = getchar(); 
    }
    while(ch >= '0' && ch <= '9') { 
        x = (x << 3) + (x << 1) + (ch ^ 48); 
        ch = getchar(); 
    }
    return x * f;
}

int main() {

    n = read();
    m = read();
    k = read();

    for(int i = 1; i <= n; ++i) {
        px[i] = read();
        py[i] = read();
    }

    for(int i = 1; i <= k; ++i) {
        t[i].p = read();
        t[i].l = read();
        t[i].r = read();
        for(int j = t[i].l; j <= t[i].r; ++j) {
            flag[t[i].p][j] = true;
        }
    }

    

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            dp[i][j] = 0x7fffffff;
        }
    }

    for(int i = 1; i <= m; ++i) {
        dp[1][i] = 0;
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(flag[i][j]) {
                continue;
            }
            if(j + px[i] <= m && !flag[i][j + px[i]]) {
                dp[i + 1][j + px[i]] = min(dp[i + 1][j + px[i]], dp[i][j] + 1);
            }
            if(j - py[i] >= 1 && !flag[i][j - py[i]]) {
                dp[i + 1][j - py[i]] = min(dp[i + 1][j - py[i]], dp[i][j]);
            }
        }
    }

    int minn = 0x7fffffff;
    for(int i = 1; i <= m; ++i) {
        minn = min(minn, dp[n][i]);
    }
    for(int )
    if(minn == 0x7fffffff) {
        cout << -1 << endl;
    }
    else {
        cout << minn << endl;
    }

    return 0;
}