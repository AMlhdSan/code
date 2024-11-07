#include <bits/stdc++.h>

#define N 100001
#define ll long long
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

int n, m;
int a[N];
ll tree[N << 2];
int siz[N << 2];
int lazy[N << 2];

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

void build(int p, int l, int r) {

    lazy[p] = 0;

    if(l == r)  {
        siz[p] = 1;
        tree[p] = a[l];
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

    cin >> n >> m;

    build(1, 1, n);

    while(m--) {
        char op;
        int x, y;

        cin >> op >> x >> y;

        if(op == 'x') {
            mdf(1, 1, n, x, x, y);
        }
        else {
            cout << qry(1, 1, n, x, y) << endl;
        }
    }

    return 0;
}