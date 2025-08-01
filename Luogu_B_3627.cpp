#include <bits/stdc++.h>

#define int long long
using namespace std;

long long n;

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

signed main() {
    n = read();

    for(int i = 1; i <= 100010; ++i) {
        if(i * i * i <= n) {
            continue;
        }
        else {
            writeln(i - 1);
            break;
        }
    }
    return 0;
}