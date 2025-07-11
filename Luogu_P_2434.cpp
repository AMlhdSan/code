#include <bits/stdc++.h>
using namespace std;

int n;

struct node {
    int l, r;
}a[500010];

bool cmp(node x, node y) {
    return x.l < y.l || (x.l == y.l && x.r < y.r);
}

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
    for (int i = 1; i <= n; i++) {
        a[i].l = read();
        a[i].r = read();
    }

    sort(a + 1, a + n + 1, cmp);

    int ll = a[1].l, rr = a[1].r;

    for(int i = 1; i <= n; i++) {
        if(a[i].l > rr) {
            write(ll);
            putchar(' ');
            writeln(rr);
            ll = a[i].l;
            rr = a[i].r;
        }
        else {
            rr = max(rr, a[i].r);
        }
    }

    write(ll);
    putchar(' ');
    writeln(rr);

    return 0;
}