#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

ll tree[N << 2], lazy[N << 2];
ll a[N];
int size[N << 2];
int n, m;
int op, x, y;
ll k;

void build(int p, ll l, ll r) {
    if(l == r) {
        tree[p] = a[l];
        size[p] = 1;
        return;
    }
    ll mid = (l + r) >> 1;
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);
    size[p] = size[2 * p] + size[2 * p + 1];
    tree[p] = tree[2 * p] + tree[2 * p + 1];
}

void pushd(int p) {
    tree[p * 2] += lazy[p] * size[p * 2];
    tree[p * 2 + 1] += lazy[p] * size[p * 2 + 1];
    lazy[p * 2] += lazy[p];
    lazy[p * 2 + 1] += lazy[p];
    lazy[p] = 0;
    return;
}

void mdf(int p, int l, int r, int ql, int qr, int k) {
    if(ql <= l && qr >= r) {
        lazy[p] += k;
        tree[p] += 1ll * size[p] * k;
        return;
    }
    pushd(p);
    int mid = (l + r) >> 1;
    if(ql <= mid)
        mdf(p * 2, l, mid, ql, qr, k);
    if(qr > mid)
        mdf(p * 2 + 1, mid + 1, r, ql, qr, k);
    tree[p] = tree[p * 2] + tree[p * 2 + 1];
}

ll qry(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return tree[p];
    }
    int mid = (l + r) >> 1;
    ll ans = 0;
    pushd(p);
    if(ql <= mid)
        ans += qry(2 * p, l, mid, ql, qr);
    if(qr > mid)
        ans += qry(2 * p + 1, mid + 1, r, ql, qr);
    tree[p] = tree[p * 2] + tree[p * 2 + 1];
    return ans;
}

int main() {

    cin >> n >> m;

    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    build(1, 1, n);

    while(m--) {
        cin >> op;
        if(op == 1) {
            cin >> x >> y >> k;
            mdf(1, 1, n, x, y, k);
        }
        else if(op == 2) {
            cin >> x >> y;
            cout << qry(1, 1, n, x, y) << endl;
        }
    }
    return 0;
}