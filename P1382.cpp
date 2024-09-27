#include <bits/stdc++.h>
using namespace std;

#define N 100001
#define ls (p << 1)
#define rs (p << 1 | 1)

struct treee {
    int l, int r;
    int maxh;
}tree[N];

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
    
}

int main() {

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> h[i] >> x[i] >> y[i];

        a[i * 2 - 1] = x[i];
        a[i * 2] = y[i];
    }

    sort(a + 1, a + 1 + n * 2);

    build(1, 1, n * 2);

    int maxx = unique(a + 1, a + 1 + n * 2) - a - 1;

    for(int i = 1; i <= n; ++i) {
        x[i] = lower_bound(a + 1, a + 1 + maxx, x[i]) - a;
        y[i] = lower_bound(a + 1, a + 1 + maxx, y[i]) - a;
        upload(1, x[i], y[i] - 1, h[i]);
    }

    return 0;
}