// 電影發明以後，人類的生命，比以前至少延長了三倍。
// amlhdsan
#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int n, q;
long long Y[N][N], T[N][N];
long long maeizize;

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
    for(int i = 1; i <= n; ++i) {
        if
    }
}

inline void write(long long x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(long long x) {
    write(x);
    putchar('\n');
}

int main() {

    n = read();
    q = read();

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            Y[i][j] = read();
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            T[i][j] = read();
        }
    }

    for(int i = 1; i <= q; i++) {
        int u = read();
        int v = read();
        long long res = LLONG_MAX;

        if(Y[u][v] != -1)
            res = Y[u][v];

        for(int w = 1; w <= n; w++) {
            if(w == u || w == v)
                continue;
            if(T[u][w] != -1 && T[w][v] != -1) {
                res = min(res, T[u][w] + T[w][v]);
            }
        }

        if(res == LLONG_MAX)
            writeln(-1);
        else
            writeln(res);
    }

    return 0;
}
