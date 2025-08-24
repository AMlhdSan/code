// 電影發明以後，人類的生命，比以前至少延長了三倍。
// amlhdsan
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128_t;

inline i64 read() {
    i64 x = 0, f = 1;
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

inline void write(i64 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(i64 x) {
    write(x);
    putchar('\n');
}

bool check(i64 n,i64 x,i64 y,i64 m,i64 a) {
    if (a < 0 || a > n) return false;
    i64 h = y / 2;
    i128 m2 = (i128)m - (i128)a * y;
    if (m2 < 0) return false;
    i64 maxb = n - a;
    i128 L = m2 - (i128)maxb * h;
    i128 R = m2;
    if (R < 0) return false;
    i64 bl = 0, br = maxb;
    if (L > 0) {
        bl = (L + x - 1) / x;
    }
    br = min((i64)(R / x), maxb);
    return bl <= br;
}

int main() {
    int T = read();
    while (T--) {
        i64 n = read(), x = read(), y = read(), m = read();
        if (m > (i128)n * y) {
            puts("No");
            continue;
        }
        i64 a = m / y;
        bool ok = false;
        if (check(n,x,y,m,a)) ok = true;
        if (check(n,x,y,m,a+1)) ok = true;
        if (ok) puts("Yes");
        else puts("No");
    }
    return 0;
}
