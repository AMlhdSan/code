#include <bits/stdc++.h>
#define int long long

using namespace std;
int n;
int ans = 0;

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') 
        f = -1;
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
    if(x >= 10)
        write(x / 10);

    putchar(x % 10 + '0');
    return;
}

inline void writeln(int x) {
    write(x);
    putchar('\n');
}

signed main() {

    freopen("gcdxor.in", "r", stdin);
    freopen("gcdxor.out", "w", stdout);

    n = read();

    for(int i = 1; i <= n / 2; ++i)
        for(int j = 2; j <= n / i; ++j)
            if(((i * j) ^ (i * (j - 1))) == i) 
                ++ans;

    writeln(ans);

    return 0;
}