#include <bits/stdc++.h>

#define ll long long
#define N 100001
#define M 100001
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

int n, m;
int c[N];
int ans = 0;

struct node {
    int l;
    int r;
};

node a[M];

int tree[N << 2];
int lazy[N << 2];

bool cmp(node x, node y) {
    if(x.r == y.r)
        return x.l > y.l;
    return x.r < y.r;
}

void upd(int p) {
    tree[p] = min(tree[ls], tree[rs]);
}

void build(int p, int l, int r) {
    if(l == r) {
        tree[p] = c[l];
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    upd(p);
}

void pushd(int p) {

    tree[ls] -= lazy[p];
    tree[rs] -= lazy[p];

    lazy[ls] += lazy[p];
    lazy[rs] += lazy[p];

    lazy[p] = 0;

    return ;
}

int qry(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return tree[p];
    }

    pushd(p);

    int minn = 0x7fffffff;

    if(ql <= mid) {
        minn = min(minn, qry(ls, l, mid, ql, qr));
    }
    if(qr > mid) {
        minn = min(minn, qry(rs, mid + 1, r, ql, qr));
    }
    return minn;
}

void mdf(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        --tree[p];
        ++lazy[p];
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

int main() {

    cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        cin >> c[i];
    }

    for(int i = 1; i <= m; ++i) {
        cin >> a[i].l >> a[i].r;
    }

    sort(a + 1, a + m + 1, cmp);
    
    build(1, 1, n);

    for(int i = 1; i <= m; ++i) {
        if(qry(1, 1, n, a[i].l, a[i].r) > 0) {
            mdf(1, 1, n, a[i].l, a[i].r);
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}