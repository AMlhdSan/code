#include <bits/stdc++.h>
#define N 100001
#define ll long long
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;

int T;
int q, mod;
ll tree[N << 2];
int op, t;

void upd(int p) {
    tree[p] = (tree[ls] * tree[rs]) % mod;
}

void build(int p, int l, int r) {
    if(l == r) {
        tree[p] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    upd(p);
}

void revice(int p, int l, int r, int ql, int qr, int k) {
    if(ql <= l && r <= qr) {
        tree[p] = k;
        return;
    }
    int mid = (l + r) >> 1;
    if(ql <= mid)
        revice(ls, l, mid, ql, qr, k);
    if(qr > mid)
        revice(rs, mid + 1, r, ql, qr, k);
    upd(p);
}

int main() {

    cin >> T;
    while(T--) {
        cin >> q >> mod;

        build(1, 1, q);

        for(int i = 1; i <= q; ++i) {
            cin >> op >> t;
            if(op == 1) {
                revice(1, 1, q, i, i, t);
            }
            else
                revice(1, 1, q, t, t, 1);
            
            cout << tree[1] % mod << endl;
        }
    }

    return 0;
}