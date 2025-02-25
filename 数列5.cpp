#include <bits/stdc++.h>

#define N 200010
#define int long long
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

int n;
int a[N];
int tree[N << 2];
int tag[N << 2];

inline int check(int x) {
    return (x == 0 || x == 1);
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

inline void upd(int p) {
    tree[p] = tree[ls] + tree[rs];
    tag[p] = tag[ls] & tag[rs];
}

inline void build(int p, int l, int r) {
    if(l == r) {
        tree[p] = a[l];
        tag[p] = check(tree[p]);
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    upd(p);
}

inline void mdf(int p, int l, int r, int ql, int qr) {
    if(tag[p])
        return;
    if(l == r) {
        tree[p] = sqrt(tree[p]);
        tag[p] = max(tag[p], check(tree[p]));
        return;
    }
    if(ql <= mid)
        mdf(ls, l, mid, ql, qr);
    if(qr > mid)
        mdf(rs, mid + 1, r, ql, qr);
    upd(p);
}

inline int qry(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return tree[p];
    }
    int sum = 0;
    if(ql <= mid)
        sum += qry(ls, l, mid, ql, qr);
    if(qr > mid)
        sum += qry(rs, mid + 1, r, ql, qr);
    return sum;
}

signed main() {

    n = read();

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    build(1, 1, n);

    for(int i = 1; i <= n; ++i) {
        int op, x, y, c;
        op = read();
        x = read();
        y = read();
        c = read();
        // if(x > y) {
        //     swap(x, y);
        // }
        if(op == 0) {
            mdf(1, 1, n, x, y);
        }
        else {
            writeln(qry(1, 1, n, x, y));
        }
    }

    return 0;
}