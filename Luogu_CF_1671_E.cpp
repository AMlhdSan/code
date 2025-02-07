#include <bits/stdc++.h>

#define MOD 998244353
#define N 1000010
#define ls (p << 1)
#define rs (p << 1 | 1)

using namespace std;

int n, m;
string str;
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

inline void dfs(int p) {
    if(s[i] >= n) {

    }
}

int main() {

    cin >> n;
    m = (1 << n) - 1;
    cin >> str;

    str = " " + str;

    dfs(1);

    return 0;
}