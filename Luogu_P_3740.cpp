#include <bits/stdc++.h>

#define N 2010
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

int n, m;
int a[N], b[N];
int c[N];

int tree[N << 2];
int lazy[N << 2];
int siz[N << 2];

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
    siz[p] = siz[ls] + siz[rs];
}

inline void pushd(int p) {
    if(lazy[p]) {
        tree[ls] += lazy[p] * siz[ls];
        tree[rs] += lazy[p] * siz[rs];
        lazy[ls] += lazy[p];
        lazy[rs] += lazy[p];
        lazy[p] = 0;
    }
}

inline void build(int p, int l, int r) {
    if (l == r) {
        tree[p] = 0;
        lazy[p] = 0;
        siz[p] = 1;
        return;
    }

    build(ls, l, mid);
    build(rs, mid + 1, r);

    upd(p);
}

inline void mdf(int p, int l, int r, int ql, int qr, int x) {
    if (ql <= l && r <= qr) {
        tree[p] += x * siz[p];
        lazy[p] += x;
        return;
    }

    pushd(p);

    if (ql <= mid) mdf(ls, l, mid, ql, qr, x);
    if (qr > mid) mdf(rs, mid + 1, r, ql, qr, x);

    upd(p);
}

inline bool qry(int p, int l, int r, int ql, int qr, int x) {
    if (ql <= l && r <= qr) {
        return tree[p] >= x * siz[p];
    }

    pushd(p);

    bool res = false;
    if (ql <= mid) res |= qry(ls, l, mid, ql, qr, x);
    if (qr > mid) res |= qry(rs, mid + 1, r, ql, qr, x);

    return res;
}

int main() {

    n = read();
    m = read();

    for(int i = 1; i <= m; ++i) {
        a[i] = read();
        b[i] = read();
        c[2 * i - 1] = a[i];
        c[2 * i] = b[i];
    }

    sort(c + 1, c + 2 * m + 1);

    int cnt = unique(c + 1, c + 2 * m + 1) - (c + 1);
    for(int i = 1; i <= m; ++i) {
        a[i] = lower_bound(c + 1, c + cnt + 1, a[i]) - c;
        b[i] = lower_bound(c + 1, c + cnt + 1, b[i]) - c;
    } // 离散化

    build(1, 1, cnt);

    
    

    return 0;
}