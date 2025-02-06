#include <bits/stdc++.h>

#define N 3010
#define int long long
#define T 0x7fffffff

using namespace std;

int n, m;
int a, b;
int dp[N][N][4];
int s[N], t[N], d[N][N];
char t1[N], t2[N];

inline void undefined() {
    int ttttt;
    for(int i = 1; i <= 100000010; ++i)
        ttttt = ttttt;
    for(int i = 1; i <= 100000010; ++i)
        ttttt = ttttt + 1 - 1; 
}

inline int read() {
    int x = 0, f = 1;
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

inline void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(int x) {
    write(x);
    putchar('\n');
}

inline int MAX(int x, int y, int z) {
    return max(x, max(y, z));
}

inline int ret(char ch) {
    switch(ch) {
        case 'A': return 0; break;
        case 'T': return 1; break;
        case 'G': return 2; break;
        case 'C': return 3; break;
        default : return -1; break;
    }
}

inline void input() {
    cin >> t1 + 1;
    cin >> t2 + 1;
}

inline void work() {

    undefined();

    n = strlen(t1 + 1);
    m = strlen(t2 + 1);

    for(int i = 1; i <= n; ++i) {
        s[i] = ret(t1[i]);
    }

    for(int i = 1; i <= m; ++i) {
        t[i] = ret(t2[i]);
    }

    for(int i = 0; i <= 3; ++i) {
        for(int j = 0; j <= 3; ++j) {
            d[i][j] = read();
        }
    }

    a = read();
    b = read();

    for(int i = max(m, n); i >= 1; --i) {
        dp[0][i][0] = -T;
        dp[i][0][0] = -T;
        dp[0][i][2] = -T;
        dp[i][0][1] = -T;
        dp[0][i][1] = - a - b * (i - 1);
        dp[i][0][2] = - a - b * (i - 1);
    }

    dp[0][0][1] = -T;
    dp[0][0][2] = -T;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            dp[i][j][0] = max(max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]), dp[i - 1][j - 1][2]) + d[s[i]][t[j]];
			dp[i][j][1] = max(max(dp[i][j - 1][0] - a, dp[i][j - 1][1] - b), dp[i][j - 1][2] - a);
			dp[i][j][2] = max(max(dp[i - 1][j][0] - a, dp[i - 1][j][2] - b), dp[i - 1][j][1] - a);
        }
    }
}

inline void output() {
    writeln(MAX(dp[n][m][0], dp[n][m][1], dp[n][m][2]));
}

inline void solve() {
    input();
    work();
    output();
}

signed main() {

    solve();

    return 0;
}