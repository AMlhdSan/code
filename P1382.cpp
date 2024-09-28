#include <bits/stdc++.h>
using namespace std;

#define N 1000001
#define ls (p << 1)
#define rs (p << 1 | 1)

struct treee {
    int l;
    int r;
    int maxh;
}tree[N << 2];

int n;
int a[N << 2];
int x[N << 2];
int y[N << 2];
int h[N << 2];

void build(int p, int l, int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].maxh = 0;
    if(l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
}

void pushd(int p) {
    tree[ls].maxh = max(tree[ls].maxh, tree[p].maxh);
    tree[rs].maxh = max(tree[rs].maxh, tree[p].maxh);
}

void upload(int p, int l, int r, int he) {
    if(tree[p].l == l && tree[p].r == r) {
        tree[p].maxh = max(tree[p].maxh, he);
        return ;
    }
    pushd(p);
    if(tree[ls].r >= r) {
        upload(ls, l, r, he);
    }
    else if(tree[rs].l <= l) {
        upload(rs, l, r, he);
    }
    else {
        upload(ls, l, tree[ls].r, he);
        upload(rs, tree[rs].l, r, he);
    }
}

int qry(int p, int index) {
    if(tree[p].l == tree[p].r) {
        return tree[p].maxh;
    }
    pushd(p);
    if(tree[ls].r >= index) {
        return qry(ls, index);
    }
    else {
        return qry(rs, index);
    }
}

int main() {

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> h[i] >> x[i] >> y[i];

        a[i * 2 - 1] = x[i];
        a[i * 2] = y[i];
    }

    sort(a + 1, a + n * 2 + 1);

    int maxx = unique(a + 1, a + n * 2 + 1) - a - 1;

    build(1, 1, maxx);

    for(int i = 1; i <= n; ++i) {
        x[i] = lower_bound(a + 1, a + maxx + 1, x[i]) - a;
        y[i] = lower_bound(a + 1, a + maxx + 1, y[i]) - a;
        upload(1, x[i], y[i] - 1, h[i]);
    }

    int sum = 1;
    int last = 0;
    x[sum] = a[1];
    y[sum] = 0;

    for(int i = 1; i < maxx; ++i) {
        int now = qry(1, i);
        if(now != last) {
            ++sum;
            x[sum] = a[i];
            y[sum] = now;
            ++sum;
            x[sum] = a[i + 1];
            y[sum] = now;
        }
        else {
            x[sum] = a[i + 1];
        }
        last = now;
    }

    cout << sum + 1 << endl;

    for(int i = 1; i <= sum; ++i) {
        cout << x[i] << " " << y[i] << endl;
    }
    cout << a[maxx] << " " << 0 << endl;

    return 0;
}