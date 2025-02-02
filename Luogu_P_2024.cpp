#include <bits/stdc++.h>

#define N 100010

using namespace std;

int n, k;
int fa[N * 3];
int ans = 0;

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-')
            f = -1;
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

inline int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

inline void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
        fa[x] = y;
    }
}

inline void init() {
    for(int i = 1; i <= n * 3; ++i)
        fa[i] = i;
}

int main() {
	n = read();
    k = read();

    init();

	while(k--) {
        int op, x, y;
        op = read();
        x = read();
        y = read();
        if(x > n || y > n) {
            ++ans;
            continue;
        }
        if(op == 1) {
            if(find(x + n) == find(y) || find(x + 2 * n) == find(y)) {
                ++ans;
            }
            else {
                merge(x, y);
                merge(x + n, y + n);
                merge(x + 2 * n, y + 2 * n);
            }
        }
        else {
            if(x == y) {
                ++ans;
                continue;
            }
            if(find(x) == find(y) || find(x) == find(y + 2 * n)) {
                ++ans;
            }
            else {
                merge(x, y + n);
                merge(x + n, y + 2 * n);
                merge(x + 2 * n, y);
            }
        }
    }
	write(ans);
    putchar('\n');
	return 0;
}