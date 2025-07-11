#include <bits/stdc++.h>

#define N 1010

using namespace std;

int n, m;
int a[N], b[N];
int c[N];

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

inline void 

int main() {

    n = read();
    m = read();

    for(int i = 1; i <= m; ++i) {
        a[i] = read();
        b[i] = read();
        c[2 * i - 1] = a[i];
        c[2 * i] = b[i];
    }

    sort(c + 1, c + 2 * m + 1);

    int cnt = unique(c + 1, c + 2 * m + 1) - (c + 1);
    for(int i = 1; i <= m; ++i) {
        a[i] = lower_bound(c + 1, c + cnt + 1, a[i]) - c;
        b[i] = lower_bound(c + 1, c + cnt + 1, b[i]) - c;
    } // 离散化



    return 0;
}