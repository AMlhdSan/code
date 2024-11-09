#include <bits/stdc++.h>

#define N 100001
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

int n, m;
int c, a, b;
int tree[N << 2];
int siz[N << 2];
int lazy[N << 2];

void upds(int p) {
    siz[p] = siz[ls] + siz[rs];
}

void upd(int p) {
    tree[p] = tree[ls] + tree[rs];
}

void pushd(int p) {
    if(lazy[p] & 1) { 
        tree[ls] = siz[ls] - tree[ls];
        tree[rs] = siz[rs] - tree[rs];
        lazy[ls] ^= 1;
        lazy[rs] ^= 1;
    }
    lazy[p] = 0;
}

void build(int p, int l, int r) {
    if(l == r) {
        tree[p] = 0;
        siz[p] = 1;
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    upds(p);
    upd(p);
}

void mdf(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        tree[p] = siz[p] - tree[p];
        lazy[p] ^= 1;
        return;
    }
    pushd(p);
    if(ql <= mid) {
        mdf(ls, l, mid, ql, qr);
    }
    if(qr > mid) {
        mdf(rs, mid + 1, r, ql, qr);
    }
    upd(p);
}

int qry(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return tree[p];
    }
    pushd(p);
    int sum = 0;
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
        cin >> c >> a >> b;
        if(c == 0) {
            mdf(1, 1, n, a, b);
        }
        else {
            cout << qry(1, 1, n, a, b) << endl;
        }
    }

    return 0;
}
