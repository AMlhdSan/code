#include <bits/stdc++.h>
#define ll long long
#define N 100005
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;

int n, q;
ll m = 10007;
int a[N];
ll tree[N << 2];
int siz[N << 2];
ll multy_lazy[N << 2];
ll add_lazy[N << 2];
int op;
int x, y, k;

void pushd(int p) {
    tree[ls] = (tree[ls] * multy_lazy[p] + siz[ls] * add_lazy[p]) % m;
    tree[rs] = (tree[rs] * multy_lazy[p] + siz[rs] * add_lazy[p]) % m;

    multy_lazy[ls] *= multy_lazy[p];
    multy_lazy[ls] %= m;

    multy_lazy[rs] *= multy_lazy[p];
    multy_lazy[rs] %= m;

    add_lazy[ls] *= multy_lazy[p];
    add_lazy[ls] += add_lazy[p];
    add_lazy[ls] %= m;

    add_lazy[rs] *= multy_lazy[p];
    add_lazy[rs] += add_lazy[p];
    add_lazy[rs] %= m;

    multy_lazy[p] = 1;
    add_lazy[p] = 0;
}

void upd(int p) {
    tree[p] = (tree[ls] + tree[rs]) % m;
}

void build(int p, int l, int r) {
    if(l == r) {
        tree[p] = a[l];
        siz[p] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    siz[p] = siz[ls] + siz[rs];
    upd(p);
}

void multy(int p, int l, int r, int ql, int qr, int c) {
    if(ql <= l && r <= qr) {
        add_lazy[p] *= c;
        add_lazy[p] %= m;

        multy_lazy[p] *= c;
        multy_lazy[p] %= m;

        tree[p] *= c;
        tree[p] %= m;

        return;
    }

    pushd(p);

    int mid = (l + r) >> 1;

    if(ql <= mid) {
        multy(ls, l, mid, ql, qr, c);
    }
    if(qr > mid) {
        multy(rs, mid + 1, r, ql, qr, c);
    }

    upd(p);
}

void add(int p, int l, int r, int ql, int qr, int c) {
    if(ql <= l && r <= qr) {
        add_lazy[p] += c;
        add_lazy[p] %= m;

        tree[p] += c * siz[p];
        tree[p] %= m;
        return;
    }

    pushd(p);

    int mid = (l + r) >> 1;

    if(ql <= mid) {
        add(ls, l, mid, ql, qr, c);
    }
    if(qr > mid) {
        add(rs, mid + 1, r, ql, qr, c);
    }

    upd(p);
}

ll qry(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return tree[p];
    }
    pushd(p);

    ll sum = 0;
    int mid = (l + r) >> 1;

    if(ql <= mid) {
        sum += qry(ls, l, mid, ql, qr) % m;
    }
    if(qr > mid) {
        sum += qry(rs, mid + 1, r, ql, qr) % m;
    }

    return sum % m;
}

int main() {

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for(int i = 1; i <= N << 2; ++i) {
        multy_lazy[i] = 1;
        add_lazy[i] = 0;
    }

    build(1, 1, n);

    for(int i = 1; i <= n; ++i) {
        cin >> op >> x >> y >> k;
        if(op == 1) {
            multy(1, 1, n, x, y, k);
        }
        else if(op == 0) {
            add(1, 1, n, x, y, k);
        }
        else if(op == 2) {
            cout << qry(1, 1, n, y, y) << endl;
        }
    }
    return 0;
}