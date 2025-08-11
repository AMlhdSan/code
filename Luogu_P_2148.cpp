#include <bits/stdc++.h>
using namespace std;

int T;
int n;
int a, b;

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

inline int f(int x, int y) {
    if(x % 2 && y % 2) {
        return 0;
    }
    else if(x % 2 == 0) {
        return f(x / 2, (y - 1) / 2 + 1) + 1;
    }
    else {
        return f(y, x);
    }
}

int main() {

    T = read();
    while(T--) {
        int n = read();
        int tmp = 0;

        for(int i = 1; i <= n / 2; ++i) {
            a = read();
            b = read();
            tmp ^= f(a, b);
        }

        puts(tmp == 0 ? "NO" : "YES");
    }

    return 0;
}