#include <bits/stdc++.h>
using namespace std;

int a[2000][2000];
int id;
int k;
int n;
int x, y;

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

void dfs(int x, int y, int r, int sx, int sy) {
    if (r == 1) return;
    int m = r / 2, t = ++id;

    if (sx < x + m && sy < y + m) {
        dfs(x, y, m, sx, sy);
    } 
    else {
        a[x + m - 1][y + m - 1] = t;
        dfs(x, y, m, x + m - 1, y + m - 1);
    }

    if (sx < x + m && sy >= y + m) {
        dfs(x, y + m, m, sx, sy);
    } 
    else {
        a[x + m - 1][y + m] = t;
        dfs(x, y + m, m, x + m - 1, y + m);
    }

    if (sx >= x + m && sy < y + m) {
        dfs(x + m, y, m, sx, sy);
    } 
    else {
        a[x + m][y + m - 1] = t;
        dfs(x + m, y, m, x + m, y + m - 1);
    }

    if (sx >= x + m && sy >= y + m) {
        dfs(x + m, y + m, m, sx, sy);
    } 
    else {
        a[x + m][y + m] = t;
        dfs(x + m, y + m, m, x + m, y + m);
    }
}

int main() {

    k = read();
    n = 1 << k;
    x = read();
    y = read();
    
    a[x - 1][y - 1] = 0;
    dfs(0, 0, n, x - 1, y - 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            write(a[i][j]);
            putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}
