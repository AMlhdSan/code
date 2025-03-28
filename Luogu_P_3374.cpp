#include <bits/stdc++.h>

#define N 500010
#define lowbit(x) ((x) & (-(x)))

using namespace std;

int n, m;
int a[N];
int tree[N];

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

inline void add(int p, int x) {
    while(p <= n) {
        tree[p] += x;
        p += lowbit(p);
    }
}

inline int qry(int p) {
    int qrys = 0;
    while(p > 0) {
        qrys += tree[p];
        p -= lowbit(p);
    }
    return qrys;
}

int main() {

    n = read();
    m = read();

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
        add(i, a[i]);
    }

    while(m--) {
        int op, x, k;
        op = read();
        x = read();
        k = read();
        if(op == 1) {
            add(x, k);
        }
        else {
            writeln(qry(k) - qry(x - 1));
        }
    }

    return 0;
}