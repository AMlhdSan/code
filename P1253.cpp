#include <bits/stdc++.h>
#define ll long long
#define N 1000001
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;

int n;
int q;
int a[N];

ll tree[N << 2];
ll lazy[N << 2];
ll mlazy[N << 2];

void upd(int p) {
    tree[p] = max(tree[ls], tree[rs]);
}

void pushd(int p) {
    if(mlazy[p] != -0x7fffffff) {
        tree[ls] = mlazy[p];
        tree[rs] = mlazy[p];

        lazy[ls] = 0;
        lazy[rs] = 0;

        mlazy[ls] = mlazy[p];
        mlazy[rs] = mlazy[p];
        
        mlazy[p] = -0x7fffffff;
    }
    if(lazy[p] != 0) {
        tree[ls] += lazy[p];
        tree[rs] += lazy[p];

        lazy[ls] += lazy[p];
        lazy[rs] += lazy[p];

        lazy[p] = 0;
    }
}


void build(int p, int l, int r) {
    mlazy[p] = -0x7fffffff;
    lazy[p] = 0;
    if(l == r) {
        tree[p] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    upd(p);
}

void add(int p, int l, int r, int ql, int qr, int x) {
    if(ql <= l && r <= qr) {
        lazy[p] += x;
        tree[p] += 1ll * x;
        return;
    }
    pushd(p);
    int mid = (l + r) >> 1;
    if(ql <= mid) {
        add(ls, l, mid, ql, qr, x);
    }
    if(qr > mid) {
        add(rs, mid + 1, r, ql, qr, x);
    }
    upd(p);
}

void change(int p, int l, int r, int ql, int qr, int x) {
    if(ql <= l && r <= qr) {
        tree[p] = x;
        mlazy[p] = x;
        lazy[p] = 0;
        return;
    }

    pushd(p);

    int mid = (l + r) >> 1;

    if(ql <= mid) {
        change(ls, l, mid, ql, qr, x);
    }
    if(qr > mid) {
        change(rs, mid + 1, r, ql, qr, x);
    }

    upd(p);
}

ll qry(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return tree[p];
    }
    pushd(p);
    int mid = (l + r) >> 1;
    ll maxx = -1e18;
    if(ql <= mid) {
        maxx = max(qry(ls, l, mid, ql, qr), maxx);
    }
    if(qr > mid) {
        maxx = max(qry(rs, mid + 1, r, ql, qr), maxx);
    }
    return maxx;
}

int main() {

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> q;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    build(1, 1, n);

    while(q--) {
        int op, l, r, x;
        cin >> op >> l >> r;
        if(op == 1) {
            cin >> x;
            change(1, 1, n, l, r, x);
        }
        else if(op == 2) {
            cin >> x;
            add(1, 1, n, l, r, x);
        }
        else {
            cout << qry(1, 1, n, l, r) << endl;
        }
    }
    return 0;
}