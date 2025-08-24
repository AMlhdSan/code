// 電影發明以後，人類的生命，比以前至少延長了三倍。
// amlhdsan
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

int main() {
    int T = read();
    while (T--) {
        int n = read(), x = read(), y = read(), m = read();
        int half = y / 2;
        bool ok = false;
        for (int a = 0; a <= n && !ok; a++) {
            int left1 = n - a;
            int sum1 = a * y;
            if (sum1 > m) break;
            for (int b = 0; b <= left1 && !ok; b++) {
                int left2 = left1 - b;
                long long cur = 1ll * a * y + 1ll * b * x;
                if (cur > m) continue;
                long long need = m - cur;
                if (0 <= need && need <= 1ll * left2 * half) {
                    ok = true;
                }
            }
        }
        if (ok) puts("Yes");
        else puts("No");
    }
    return 0;
}
