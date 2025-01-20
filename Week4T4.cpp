#include <bits/stdc++.h>
using namespace std;

int n, m, k;

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
    if(x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

int main() {

    freopen("puzzle.in", "r", stdin);
    freopen("puzzle.out", "w", stdout);

    n = read();
    m = read();
    k = read();

    for(int i = 1; i <= n; ++i) {
        write(i);
        putchar(' ');
    }

    return 0;
}