#include <bits/stdc++.h>

#define N 100010
#define int long long
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

struct node {
    int op;
    int l, r;
};

int n, m;
int a[N];
int tree[N << 2];
int siz[N << 2];
int lazy[N << 2];
node q[N];
int pos;

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
    return;
}

inline void pushd(int p) {
    if(lazy[p] == -1)
        return;

    tree[ls] = siz[ls] * lazy[p];
    tree[rs] = siz[rs] * lazy[p];

    lazy[ls] = lazy[rs] = lazy[p];

    lazy[p] = -1;
}

inline void build(int p, int l, int r, int x) {
    lazy[p] = -1;
    siz[p] = 1;
    if(l == r) {
        siz[p] = 1;
        lazy[p] = -1;
        tree[p] = (a[l] >= x);
        return;
    }
    build(ls, l, mid, x);
    build(rs, mid + 1, r, x);
    upd(p);
}

inline void mdf(int p, int l, int r, int ql, int qr, int x) {
    if(ql <= l && r <= qr) {
        lazy[p] = x;
        tree[p] = siz[p] * x;
        return;
    }
    pushd(p);
    if(ql <= mid) 
        mdf(ls, l, mid, ql, qr, x);
    if(qr > mid)
        mdf(rs, mid + 1, r, ql, qr, x);
    upd(p);
}

inline int qry(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return tree[p];
    }
    pushd(p);
    int sum = 0;
    if(ql <= mid)
        sum += qry(ls, l, mid, ql, qr);
    if(qr > mid)
        sum += qry(rs, mid + 1, r, ql, qr);
    return sum;
}

inline int check(int x) {
    build(1, 1, n, x);
    for(int i = 1; i <= m; ++i) {
        int sum = qry(1, 1, n, q[i].l, q[i].r);
        int num = q[i].r - q[i].l + 1;
        int num0 = num - sum;
        int num1 = sum;
        if(q[i].op == 0) { // 升序
            if (num0 > 0) {
                mdf(1, 1, n, q[i].l, q[i].l + num0 - 1, 0);
            }
            if (num1 > 0) {
                mdf(1, 1, n, q[i].l + num0, q[i].r, 1);
            }
            
        }
        else { // 降序
            if (num1 > 0) {
                mdf(1, 1, n, q[i].l, q[i].l + num1 - 1, 1);
            }
            if (num0 > 0) {
                mdf(1, 1, n, q[i].l + num1, q[i].r, 0);
            }
            
        }
    }
    return qry(1, 1, n, pos, pos);
}

signed main() {

    n = read();
    m = read();

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    for(int i = 1; i <= m; ++i) {
        q[i].op = read();
        q[i].l = read();
        q[i].r = read();
        if(q[i].l > q[i].r)
            swap(q[i].l, q[i].r);
    }

    pos = read();

    int l = 1, r = n;
    int ans;

    while(l <= r) {
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    writeln(ans);

    return 0;
}