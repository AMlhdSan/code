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

void upd(int p) {
    tree[p] = __gcd(tree[ls], tree[rs]);
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

ll qry(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return tree[p];
    }

    ll sum = 0;

    if(ql <= mid) {
        sum = __gcd(sum, qry(ls, l, mid, ql, qr));
    }
    if(qr > mid) {
        sum = __gcd(sum, qry(rs, mid + 1, r, ql, qr));
    }

    return sum;
}

int main() {

    cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    build(1, 1, n);

    while(m--) {
        int l, r;

        cin >> l >> r;

        cout << qry(1, 1, n, l, r) << endl;
    }

    return 0;
}