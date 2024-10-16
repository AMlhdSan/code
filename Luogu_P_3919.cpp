#include <bits/stdc++.h>

#define N 1000001
#define mid ((l + r) >> 1)

using namespace std;

int n, m;
int a[N];
int top = 0;
int x, y, z, w;
int root[N];

struct node {
    int ls, rs;
    int in;
}tree[N << 5];

int build(int p, int l, int r) {
    p = ++top;
    if(l == r) {
        tree[p].in = a[l];
        return top;
    }
    tree[p].ls = build(tree[p].ls, l, mid);
    tree[p].rs = build(tree[p].rs, mid + 1, r);
    return p;
}

int clone(int p) {
    ++top;
    tree[top] = tree[p];
    return top;
}

int upd(int p, int l, int r, int lo, int num) {
    p = clone(p);
    if(l == r) {
        tree[p].in = num;
    }
    else {
        if(lo <= mid) {
            tree[p].ls = upd(tree[p].ls, l, mid, lo, num);
        }
        else {
            tree[p].rs = upd(tree[p].rs, mid + 1, r, lo, num);
        }
    }
    return p;
}

int qry(int p, int l, int r, int lo) {
    if(l == r) {
        return tree[p].in;
    }
    else {
        if(lo <= mid) {
            return qry(tree[p].ls, l, mid, lo);
        }
        else {
            return qry(tree[p].rs, mid + 1, r, lo);
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    root[0] = build(0, 1, n);

    for(int i = 1; i <= m; ++i) {
        cin >> x >> y >> z;
        if(y == 1) {
            cin >> w;
            root[i] = upd(root[x], 1, n, z, w);
        }
        else {
            cout << qry(root[x], 1, n, z) << endl;
            root[i] = root[x];
        }
    }


    return 0;
}