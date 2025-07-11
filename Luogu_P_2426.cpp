#include <bits/stdc++.h>

#define N 110

using namespace std;

int n;
int a[N];
int dp[N];

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

    memset(dp, 0, sizeof(dp));

    n = read();
    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    dp[1] = a[1];

    for(int i = 2; i <= n; ++i) {
        for(int j = 0; j < i - 1; ++j) {
            dp[i] = max(dp[i], dp[j] + (abs(a[i] - a[j + 1])) * (i - j));
        }
        dp[i] = max(dp[i], dp[i - 1] + a[i]);
    }

    writeln(dp[n]);

    return 0;
}