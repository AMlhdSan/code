#include<bits/stdc++.h>
using namespace std;

bitset<1001> dp, lst;
int n, x, V;

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
inline void write(int x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(int x) {
    write(x);
    putchar('\n');
}

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    n = read(), x = read(), V = read();
    dp[x] = 1;
    while (n--) {
        lst = dp;
        dp.reset();
        int x = read();
        for (int i = 0; i <= V; i++) if (lst[i]) {
            if (i >= x) dp[i - x] = lst[i];
            if (i + x <= V) dp[i + x] = lst[i];
        }
    }
    for (int i = V; ~i; i--) if (dp[i]) return writeln(i), 0;
    writeln(-1);
    return 0;
}
