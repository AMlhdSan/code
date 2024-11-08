#include <bits/stdc++.h>

#define N 100001
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid((l + r) >> 1)

using namespace std;

int n, m;
int c, a, b;
int tree[N << 2];
int siz[N << 2];
int lazy[N << 2];

void upds(int p) {
    siz[p] = siz[ls] + siz[rs];
}

void pushd(int p) {
    
}

void build(int p, int l, int r) {
    if(l == r) {
        siz[p] = 1;
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    upds(p);
}

void mdf(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        tree[p] = siz[p] - tree[p];
        lazy[p] = (lazy[p] + 1) % 2;
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

    build(1, 1, n);

    while(m--) {
        cin >> c >> a >> b;
        if(c == 0) {

        }
        else {

        }
    }


    return 0;
}