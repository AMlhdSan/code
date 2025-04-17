#include <bits/stdc++.h>

#define N 1000010
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

int n, m;
int a[N];
int tree[N << 2];


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

inline void upd(int p) {
    tree[p] = tree[ls] + tree[rs];
}

inline void build(int p, int l, int r) {
    if(l == r) {
        tree[p] = a[l];
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    upd(p);
}

int main() {

    n = read();
    m = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }

    build(1, 1, n);
    
    while(m--) {

    }

    return 0;
}