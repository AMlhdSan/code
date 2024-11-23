#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2010;
const int MAX_K = 2010;
set<long long> dp[MAX_N];
set<long long> tmp;
int T;

inline int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

inline void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x >= 10) write(x / 10);
    putchar(x % 10 + '0');
}

int solve(int n, int k) {
    dp[0].insert(1);
    tmp = dp[0];
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= i + 1; ++j) {
            dp[i] = tmp;
            for(long long prod : dp[i - (j - 1)]) {
                    dp[i].insert(prod * (j - 1));
                }
        }
        tmp = dp[i];
    }

    return dp[n].size();
}

int main() {
    
    // freopen("myself.in", "r", stdin);
    // freopen("myself.out", "w", stdout);

    T = read();

    while (T--) {
        int n = read(), k = read();
        k = min(n + 1, k);
        write(solve(n, k) + 1);
        putchar('\n');
    }
    
    return 0;
}
