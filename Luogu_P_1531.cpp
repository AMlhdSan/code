#include <bits/stdc++.h>

#define N 200001
#define ll long long
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

int n, m;
int a[N];
ll tree[N << 2];

void upd(int p) {
    tree[p] = max(tree[ls], tree[rs]);
}

void build(int p, int l, int r) {

    if(l == r)  {
        tree[p] = a[l];
        return ;
    }

    build(ls, l, mid);
    build(rs, mid + 1, r);

    upd(p);
}

void mdf(int p, int l, int r, int ql, int qr, int k) {
    if(ql <= l && r <= qr) {
        tree[p] = k;
        return;
    }
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

    ll maxx = 0;

    if(ql <= mid) {
        maxx = max(maxx, qry(ls, l, mid, ql, qr));
    }
    if(qr > mid) {
        maxx = max(maxx, qry(rs, mid + 1, r, ql, qr));
    }

    return maxx;
}

int main() {

    cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    build(1, 1, n);

    while(m--) {
        char op;
        int x, y, k;

        cin >> op >> x >> y;

        if(op == 'U') {
            if(qry(1, 1, n, x, x) < y)
                mdf(1, 1, n, x, x, y);
        }
        else {
            cout << qry(1, 1, n, x, y) << endl;
        }
    }

    return 0;
}