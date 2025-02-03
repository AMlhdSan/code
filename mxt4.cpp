#include <bits/stdc++.h>

#define N 5010
#define int long long

using namespace std;

int T;
int n;
int a[N];
int lcp[N][N];
int f[N][N];
int g[N][N];
int sum;

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

inline void init() {
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    memset(lcp, 0, sizeof(lcp));
}

inline void input() {
    n = 0;
    char ch = getchar();
    while(ch == '\n')
        ch = getchar();
    while(ch <= '9' && ch >= '0' && ch != '\n') {
        a[++n] = ch - '0';
        ch = getchar();
    }
    // for(int i = 1; i <= n; ++i) {
    //     cout << a[i] << ' ';
    // }
    // cout << endl;
}

inline void output() {
    writeln(sum);
}

inline void getlcp() {
    for(int i = n; i >= 1; --i) {
        for(int j = i; j <= n; ++j) {
            if(a[i] == a[j])
                lcp[i][j] = lcp[i + 1][j + 1] + 1;
        }
    }
}

inline void getf() {
    for(int i = 2; i <= n; ++i) {
        for(int j = i + 3; j < n; ++j) {
            int len = min(j - i - 1, lcp[i][j]);
            if(len >= 2)
                ++f[i][len];
        }
    }
    for(int i = 2; i <= n; ++i) {
        for(int j = n - 1; j > 1; --j) {
            f[i][j] += f[i][j + 1];
        }
    }
}

inline void getg() {
    for(int i = 2; i <= n; ++i)
        for(int j = 1; j <= min(i - 1, n - i + 1); ++j)
            if(lcp[i - j][i] >= j)
                ++g[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) 
            g[i][j] += g[i][j - 1];
}

inline void getsum() {
    sum = 0;
    for(int i = 2; i <= n; ++i) {
        for(int j = 2; j <= n; ++j) {
            sum += f[i][j] * g[i][j - 1];
        }
    }
}

inline void solve() {
    init();
    input();
    getlcp();
    getf();
    getg();
    getsum();
    output();
}

signed main() {

    // freopen("Code.in", "r", stdin);
    // freopen("Code.out", "w", stdout);

    T = read();

    while(T--) {
        solve();
    }

    return 0;
}