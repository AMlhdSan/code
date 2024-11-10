#include <bits/stdc++.h>

#define N 50001
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

int n, m;
int a[N];
int itree[N << 2];
int atree[N << 2];
pair<int, int> tmp, tmp1;

inline int read() {
    int x = 0, f = 1;
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
    itree[p] = min(itree[ls], itree[rs]);
    atree[p] = max(atree[ls], atree[rs]);
}

void build(int p, int l, int r) {
    if(l == r) {
        itree[p] = a[l];
        atree[p] = a[l];
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    upd(p);
}

pair<int, int> qry(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return make_pair(itree[p], atree[p]);
    }
    pair<int, int> ret = make_pair(0x7fffffff, -0x7fffffff);
    if(ql <= mid) {
        tmp1 = qry(ls, l, mid, ql, qr);
        ret.first = min(ret.first, tmp1.first);
        ret.second = max(ret.second, tmp1.second);
    }
    if(qr > mid) {
        tmp1 = qry(rs, mid + 1, r, ql, qr);
        ret.first = min(ret.first, tmp1.first);
        ret.second = max(ret.second, tmp1.second);
    }
    return ret;
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
        tmp = qry(1, 1, n, l, r);
        cout << tmp.second - tmp.first << endl;
    }

    return 0;
}