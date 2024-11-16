#include <bits/stdc++.h>

#define N 100001
#define ll long long
#define MOD 10007
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

int n, m;
int a[N];
ll tree[N << 2];
int siz[N << 2];
int lazy[N << 2];

struct robot {
    int o, x, y;
}ro[N];

void upd(int p) {
    tree[p] = tree[ls] + tree[rs];
}

void upds(int p) {
    siz[p] = siz[ls] + siz[rs];
}

void pushd(int p) {
    tree[ls] += lazy[p] * siz[ls];
    tree[rs] += lazy[p] * siz[rs];

    lazy[ls] += lazy[p];
    lazy[rs] += lazy[p];

    lazy[p] = 0;
}

void mdf(int p, int l, int r, int ql, int qr, int k) {
    if(ql <= l && r <= qr) {
        tree[p] += 1ll * siz[p] * k;
        lazy[p] += k;
        return;
    }
    pushd(p);
    if(ql <= mid) {
        mdf(ls, l, mid, ql, qr, k);
    }
    if(qr > mid) {
        mdf(rs, mid + 1, r, ql, qr, k);
    }
    upd(p);
}

ll qry(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return tree[p];
        pushd(p);
    }
    pushd(p);
    if(p == push) {
        else {
            for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= n; ++j) {

                }
            }
        }
    }

    ll sum = 0;

    if(ql <= mid) {
        sum += qry(ls, l, mid, ql, qr);
    }
    if(qr > mid) {
        sum += qry(rs, mid + 1, r, ql, qr);
    }

    return sum;
}

int main() {

    cin >> n >> m >> k;
    for(int i = 1; i <= k; ++i) {
        cin >> c[i];
        ++cnt[i];
        cnt[i] %= MOD;
    }

    for(int i = 1; i <= m; ++i) {
        cin >> ro[i].o >> ro[i].x >> ro[i].y;
    }

    for(int i = m; i >= 1; --i) {
        if(ro[i].o == 1) {
            a[ro[i].x] += ro[i].y * cnt[i] % MOD;
        }
        else {
            upd(1, 1, n, ro[i].x, ro[i].y, cnt[i]);
        }
    }

    for(int i = 1; i <= n; ++i) {
        cout << tree[i] << ' ';
    }

    return 0;
}
