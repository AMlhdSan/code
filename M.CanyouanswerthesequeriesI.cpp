#include <bits/stdc++.h>

#define N 500001
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

struct node {
    int sum;
    int maxl; 
    int maxr;  
    int maxx;  
} tree[N << 2];

int n, m;
int a[N];

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
    tree[p].sum = tree[ls].sum + tree[rs].sum;
    tree[p].maxx = max(max(tree[ls].maxx, tree[rs].maxx), tree[ls].maxr + tree[rs].maxl);
    tree[p].maxl = max(tree[ls].maxl, tree[ls].sum + tree[rs].maxl);
    tree[p].maxr = max(tree[rs].maxr, tree[rs].sum + tree[ls].maxr);
}

// 建树操作
void build(int p, int l, int r) {
    if (l == r) {
        tree[p].sum = tree[p].maxl = tree[p].maxr = tree[p].maxx = a[l];
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    upd(p);
}

// 单点修改操作
void mdf(int p, int l, int r, int q, int x) {
    if (l == r && l == q) {
        tree[p].sum = tree[p].maxl = tree[p].maxr = tree[p].maxx = x;
        return;
    }
    if (q <= mid) {
        mdf(ls, l, mid, q, x);
    } else {
        mdf(rs, mid + 1, r, q, x);
    }
    upd(p);
}

// 区间查询操作
node qry(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return tree[p];
    }
    if (qr <= mid) {
        return qry(ls, l, mid, ql, qr);
    }
    if (ql > mid) {
        return qry(rs, mid + 1, r, ql, qr);
    }
    node ll = qry(ls, l, mid, ql, qr);
    node rr = qry(rs, mid + 1, r, ql, qr);
    node ans;
    ans.sum = ll.sum + rr.sum;
    ans.maxl = max(ll.maxl, ll.sum + rr.maxl);
    ans.maxr = max(rr.maxr, rr.sum + ll.maxr);
    ans.maxx = max(max(ll.maxx, rr.maxx), ll.maxr + rr.maxl);
    return ans;
}

int main() {

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    build(1, 1, n);

    cin >> m;

    while(m--) {
        int a, b;
        cin >> a >> b;
        if(a > b) {
            swap(a, b);
        }
        cout << qry(1, 1, n, a, b).maxx << endl;
    }
    return 0;
}
