#include <bits/stdc++.h>

#define N 100005

using namespace std;

int n;
int a[N];
int dp[N];
int t[N];
int maxx = 0;
int cnt = 0;

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

    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }

    for(int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[i] < a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxx = max(maxx, dp[i]);
    }

    write(maxx);
    putchar(' ');

    for(int i = 1; i <= n; ++i) {
        if(dp[i] == 1) {
            t[i] = 1;
        }
        for(int j = 1; j < i; ++j) {
            if(a[i] < a[j] && dp[j] + 1 == dp[i]) {
                t[i] += t[j];
            }
            else if(dp[i] == dp[j] && a[j] == a[i]) {
                t[i] = 0;
            }
        }
    }

    for(int i = 1; i <= n; ++i) {
        if(dp[i] == maxx) {
            cnt += t[i];
        }
    }

    writeln(cnt);

    return 0;
}