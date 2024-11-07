#include <bits/stdc++.h>

#define N 1000001
#define ll long long
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

int n, m;
int a[N];
int tree[N << 2];
int lazy[N << 2];
int d, s, t;
bool flag = 0;

void upd(int p) {
    tree[p] = min(tree[ls], tree[rs]);
}

void pushd(int p) {
    tree[ls] += lazy[p];
    tree[rs] += lazy[p];

    lazy[ls] += lazy[p];
    lazy[rs] += lazy[p];

    lazy[p] = 0;
}

void build(int p, int l, int r) {
    if(l == r) {
        tree[p] = a[l];
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    upd(p);
}

void mdf(int p, int l, int r, int ql, int qr, int k) {
    if(ql <= l && r <= qr) {
        tree[p] += k;
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

    ll ret = 0x7fffffff;

    if(ql <= mid) {
        ret = min(ret, qry(ls, l, mid, ql, qr));
    }
    if(qr > mid) {
        ret = min(ret, qry(rs, mid + 1, r, ql, qr));
    }

    return ret;
}

int main() {

    cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    build(1, 1, n);

    for(int i = 1; i <= m; ++i) {
        cin >> d >> s >> t;
        if(qry(1, 1, n, s, t) < d) {
            if(!flag) {
                flag = 1;
                cout << -1 << endl;
                cout << i << ' ';
            }
        }
        else {
            mdf(1, 1, n, s, t, -d);
        }
    }
    if(!flag) {
        cout << 0 << endl;
    }

    return 0;
}