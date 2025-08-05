#include <bits/stdc++.h>
using namespace std;

int m, n;
int cnt1[50010];
// int inf1[50010];
int tnxt[50010][2];
bool exi[500100];
int tot = 1;

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

    m = read();
    n = read();

    for(int i = 1; i <= m; ++i) {
        int b, c;
        b = read();
        int u = 1;
        for(int j = 1; j <= b; ++j) {
            c = read();
            if(!tnxt[u][c]) {
                tnxt[u][c] = ++tot;
            }
            u = tnxt[u][c];
        }
        exi[u] = 1;
    }

    return 0;
}