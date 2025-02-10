#include <bits/stdc++.h>

#define N 1010
#define K 1010
#define MOD 10000

using namespace std;

int n, k;
int dp[N][K];

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

inline void mod(int &x) {
    while(x < 0) {
        x += MOD;
    }
    x %= MOD;
}

int main() {

    n = read();
    k = read();

    dp[1][0] = 1;

    for(int i = 2; i <= n; ++i) {
        int sum = 0;
        for(int j = 0; j <= k; ++j) {
            sum += dp[i - 1][j];
            mod(sum);
            dp[i][j] = sum;
            if(j >= i - 1) {
                sum -= dp[i - 1][j - i + 1];
                mod(sum);
            }
        }
    }

    writeln(dp[n][k]);

    return 0;
}