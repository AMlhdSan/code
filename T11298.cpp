#include <bits/stdc++.h>

#define N 100010

using namespace std;

int n;
int degree[N];
int u, v;

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

    freopen("map.in", "r", stdin);
    freopen("map.out", "w", stdout);

    n = read();
    for(int i = 1; i <= n - 1; ++i) {
        u = read();
        v = read();
        ++degree[u];
        ++degree[v];
    }

    for(int i = 1; i <= n; ++i) {
        if(degree[i] == n - 1) {
            write(n - 2);
            putchar('\n');
            return 0;
        }
    }
    write(n - 1);
    putchar('\n');

    return 0;
}