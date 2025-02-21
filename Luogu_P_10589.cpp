#include <bits/stdc++.h>

#define N 200010
#define lowbit(x) ((x) & (-(x)))
#define int long long

using namespace std;

int n;
int a[N];
int tree[N];
int lm[N], rm[N], li[N], ri[N];
int sum1, sum2;

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

signed main() {

    n = read();

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
        li[i] = qry(a[i] - 1);
        lm[i] = i - 1 - li[i];
        add(a[i], 1);
    }

    memset(tree, 0, sizeof(tree));

    for(int i = n; i >= 1; --i) {
        ri[i] = qry(a[i] - 1);
        rm[i] = n - i - ri[i];
        add(a[i], 1);
    }

    for(int i = 1; i <= n; ++i) {
        sum1 += lm[i] * rm[i];
        sum2 += li[i] * ri[i];
    }

    write(sum1);
    putchar(' ');
    writeln(sum2);

    return 0;
}