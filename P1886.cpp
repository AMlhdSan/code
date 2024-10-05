#include <bits/stdc++.h>
#define N 1000001
#define ls (p << 1)
#define rs (p << 1 | 1 )
#define mid ((l + r) >> 1)
using namespace std;

int n, k;
int a[N];
int tree1[N << 2];
int tree2[N << 2];

void upd2(int p) {
    tree2[p] = max(tree2[ls], tree2[rs]);
}

void build2(int p, int l, int r) {
    if(l == r) {
        tree2[p] = a[l];
        return;
    }
    build2(ls, l, mid);
    build2(rs, mid + 1, r);
    upd2(p);
}

int qry2(int p, int l ,int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return tree2[p];
    }
    int maxx = -0x7fffffff;
    if(ql <= mid) {
        maxx = max(maxx, qry2(ls, l, mid, ql, qr));
    }
    if(qr > mid) {
        maxx = max(maxx, qry2(rs, mid + 1, r, ql, qr));
    }
    return maxx;
}

void upd1(int p) {
    tree1[p] = min(tree1[ls], tree1[rs]);
}

void build1(int p, int l, int r) {
    if(l == r) {
        tree1[p] = a[l];
        return;
    }
    build1(ls, l, mid);
    build1(rs, mid + 1, r);
    upd1(p);
}

int qry1(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return tree1[p];
    }
    int minn = 0x7fffffff;
    if(ql <= mid) {
        minn = min(minn, qry1(ls, l, mid, ql, qr));
    }
    if(qr > mid) {
        minn = min(minn, qry1(rs, mid + 1, r, ql, qr));
    }
    return minn;
}

int main() {

    cin >> n >> k;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    build1(1, 1, n);
    build2(1, 1, n);

    for(int i = 1; i <= n - k + 1; ++i) {
        cout << qry1(1, 1, n, i, i + k - 1) << ' ';
    }
    cout << endl;
    for(int i = 1; i <= n - k + 1; ++i) {
        cout << qry2(1, 1, n, i, i + k - 1) << ' ';
    }

    return 0;
}