#include <bits/stdc++.h>
#define N 200001
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
#define ll long long
using namespace std;

ll n, q, w;
int a[N];
int l, r, d;
ll tree[N << 2];
ll lazy[N << 2];
int siz[N];

void upds(int p) {
    siz[p] = siz[ls] + siz[rs];
}

void upd(int p) {
    tree[p] = tree[ls] + tree[rs];
}

void pushd(int p) {
    tree[ls] += 1ll * lazy[p] * siz[ls];
    tree[rs] += 1ll * lazy[p] * siz[rs];

    lazy[ls] += lazy[p];
    lazy[rs] += lazy[p];

    lazy[p] = 0;
}

void build(int p, int l, int r) {
    if(l == r) {
        tree[p] = a[l];
        siz[p] = 1;
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    upd(p);
    upds(p);
}

void mdf(int p, int l, int r, int ql, int qr, int x) {
    if(ql <= l && r <= qr) {
        tree[p] += 1ll * x * siz[p];
        lazy[p] += x;
        return;
    }
    pushd(p);
    if(ql <= mid) {
        mdf(ls, l, mid, ql, qr, x);
    }
    if(qr > mid) {
        mdf(rs, mid + 1, r, ql, qr, x);
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

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch - '0');
        ch = getchar();
    }
    return x * f;
}

int main() {

    cin >> n >> q >> w;

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    build(1, 1, n);

    while(q--) {
        l = read();
        r = read();
        d = read();
        mdf(1, 1, n, l, r, d);
        
    }

    return 0;
}