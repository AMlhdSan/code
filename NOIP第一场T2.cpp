#include <bits/stdc++.h>

#define N 500010

#define ll long long
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

int n, m, q;
ll a[N], b[N];
int opt, opl, opr, opx;
ll tree[N << 2];
int siz[N << 2];
ll lazy[N << 2];

inline int read() {
    int w = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        w = (w << 3) + (w << 1) + (ch - '0');
        ch = getchar();
    }
    return w * f;
}

void upd(int p) {
    tree[p] = tree[ls] + tree[rs];
}

void upds(int p) {
    siz[p] = siz[ls] + siz[rs];
}

void pushd(int p) {
    tree[ls] += lazy[p] * siz[ls];
    tree[rs] += lazy[p] * siz[rs];

    lazy[ls] += lazy[p];
    lazy[rs] += lazy[p];

    lazy[p] = 0;
}

void rebuild(int p, int l, int r, int ql, int qr, int x) {

}

void build(int p, int l, int r) {

    lazy[p] = 0;

    if(l == r)  {
        siz[p] = 1;
        tree[p] = 0;
        return ;
    }

    build(ls, l, mid);
    build(rs, mid + 1, r);

    upd(p);
    upds(p);
}

void mdf(int p, int l, int r, int ql, int qr, int k) {
    if(ql <= l && r <= qr) {
        tree[p] += 1ll * siz[p] * k;
        lazy[p] += k;
        return;
    }
    pushd(p);
    if(ql <= mid) {
        mdf(ls, l, mid, ql, qr, k);
    }
    if(qr > mid) {
        mdf(rs, mid + 1, r, ql, qr, k);
    }
    upd(p);
}

ll qry(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return tree[p];
    }
    pushd(p);

    ll sum = 0;

    if(ql <= mid) {
        sum += qry(ls, l, mid, ql, qr);
    }
    if(qr > mid) {
        sum += qry(rs, mid + 1, r, ql, qr);
    }

    return sum;
}

int main() {

    n = read();
    m = read();
    q = read();

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    build(1, 1, m);

    while(q--) {
        opt = read();
        opl = read();
        opr = read();
        opx = read();
        if(opt == 1) {
            rebuild(1, 1, m, opl, opr, opx);
        }
        else {
            mdf(1, 1, m, opl, opr, opx);
        }
    }

    for(int i = 1; i <= n; ++i) {
        if(a[i] != 0) {
            b[a[i]] += qry(1, 1, m, i, i);
        }
    }   
    for(int i = 1; i <= m; ++i) {
        printf("%lld ", b[i]);
    }
    cout << endl;

    return 0;
}