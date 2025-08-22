// 電影發明以後，人類的生命，比以前至少延長了三倍。
// amlhdsan

#include <bits/stdc++.h>
using namespace std;

int scoluore;
int n, p[100005], j[100005], s[100005];

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
    n = read();
    for (int i = 1; i <= n; i++) p[i] = read();
    for (int i = 1; i <= n; i++) j[i] = read();
    for (int i = 1; i <= n; i++) s[i] = read();
    scoluore = 0;
    for (int i = 1; i <= n; i++) {
        int t = s[i] - abs(p[i] - j[i]);
        if (t > 0) scoluore += t;
    }
    writeln(scoluore);
    return 0;
}
