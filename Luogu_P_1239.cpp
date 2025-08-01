#include <bits/stdc++.h>
using namespace std;

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

int a[10];

void solve(int n) {
    int len = log10(n) + 1;
    for (int i = 0, p = 1; i < len; ++i, p *= 10) {
        int l = n / (p * 10), r = n % p, d = (n / p) % 10;
        for (int j = 0; j < 10; ++j) {
            a[j] += l * p;
            if (j == 0 && l == 0) a[j] -= p;
        }
        if (d > 0) a[0] -= p;
        for (int j = 0; j < d; ++j) a[j] += p;
        a[d] += r + 1;
    }
}

int main() {
    int n = read();
    solve(n);
    for (int i = 0; i < 10; ++i) writeln(a[i]);
    return 0;
}
