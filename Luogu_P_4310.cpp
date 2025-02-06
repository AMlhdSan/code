#include <bits/stdc++.h>

#define N 100010

using namespace std;

int n;
int a[N];
int dp[N]; // dp[i] 表示以 a[i] 为结尾的最长的子序列长度。
int maxx = 1;

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

int main() {

    n = read();

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    for(int i = 1; i <= n; ++i) {
        int k = 1;
        for(int t = 0; t <= 30; ++t) {
            if((1 << t) & a[i])
                k = max(dp[t] + 1, k);
        }
        for(int t = 0; t <= 30; ++t) {
            if((1 << t) & a[i])
                dp[t] = max(dp[t], k);
        }
        maxx = max(maxx, k);
    }
    
    writeln(maxx);

    return 0;
}