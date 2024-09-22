#include <bits/stdc++.h>
#define ll long long
#define N 100005
#define ls (p << 1)
#define lr (p << 1 | 1)
using namespace std;

int n, q, m;
int a[N];
int tree[N << 2];
int siz[N << 2];
int op;
int x, y, k;

void build(int p, int l, int r) {
    if(l == r) {
        tree[p] = a[l];
        siz[p] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(lr, mid + 1, r);
}

int main() {

    cin >> n >> q >> m;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    build(1, 1, n);

    while(q--) {
        cin >> op >> x >> y;
        if(op == 1) {
            cin >> k;
            multy(1, 1, n, x, y, k);
        }
        else if(op == 2) {
            cin >> k;
            add(1, 1, n, x, y, k);
        }
        else if(op == 3) {
            cout << qry(1, 1, n, x, y) << endl;
        }
    }
    return 0;
}