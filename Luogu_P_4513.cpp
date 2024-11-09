#include <bits/stdc++.h>

#define N 500005
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

int n, m;
int a[N];
int tree[N << 2];
int maxl[N << 2];
int maxr[N << 2];
int maxx[N << 2];

inline int read() {
    int f = 1, x = 0;
    char ch = 0;
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch - '0');
        ch = getchar();
    }
    return x * f;
}

void upd(int p) {
    tree[p] = tree[ls] + tree[rs];
    maxx[p] = max(max(maxx[ls], maxx[rs]), maxl[rs] + maxr[ls]);
    maxl[p] = max(maxl[ls], tree[ls] + maxl[rs]);
    maxr[p] = max(maxr[rs], tree[rs] + maxr[ls]);
}

void build(int p, int l, int r) {
    if(l == r) {
        tree[p] = a[l];
        maxl[p] = a[l];
        maxr[p] = a[l];
        maxx[p] = a[l];
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    upd(p);
}

void mdf(int p, int l, int r, int q, int x) {
    if(q <= l && q >= r) {
        tree[p] = x;
        maxl[p] = x;
        maxr[p] = x;
        maxx[p] = x;
        return;
    }
    if(q <= mid) {
        mdf(ls, l, mid, q, x);
    }
    if(q > mid) {
        mdf(rs, mid + 1, r, q, x);
    }
    upd(p);
}

pair<pair<int, int>, pair<int, int> > qry(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return (make_pair(make_pair(tree[p], maxl[p]), make_pair(maxr[p], maxx[p])));
    }
    else if(ql > mid) {
        return qry(ls, l, mid, ql, qr);
    }
    else if(qr < mid) {
        return qry(rs, mid + 1, r, ql, qr);
    }
    else {
        pair<pair<int, int>, pair<int, int> > ll = qry(ls, l, mid, ql, qr);
        pair<pair<int, int>, pair<int, int> > rr = qry(rs, mid + 1, r, ql, qr);
        pair<pair<int, int>, pair<int, int> > ans;
        ans.first.first = ll.first.first + rr.first.first;
        ans.first.second = max()

    }
}

int main() {

    cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    build(1, 1, n);

    return 0;
}