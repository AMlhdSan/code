#include <bits/stdc++.h>

#define N 100001
#define MOD 1000000007
#define ll long long
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

ll n, m, k;
ll a[N];
ll tree[N << 2];
ll siz[N << 2];
ll lazy[N << 2];

inline ll wk(ll x) {
    int sum = 0;
    while(x > 0) {  
        sum += pow((x % 10), k);
        x /= 10;
    }
    return sum;
}

inline ll read() {
    ll x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

inline void write(ll t) {
    if(t < 0) {
        putchar('-');
        t = -t;
    }
    if(t > 9) {
        write(t / 10);
    }
    putchar(t % 10 + '0');
}

void upd(ll p) {
    tree[p] = tree[ls] + tree[rs];
    tree[p] %= MOD;
}

void build(ll p, ll l, ll r) {

    if(l == r)  {
        tree[p] = a[l];
        return ;
    }

    build(ls, l, mid);
    build(rs, mid + 1, r);

    upd(p);
}

void mdf(ll p, ll l, ll r, ll ql, ll qr) {
    if(l == r) {
        tree[p] = wk(tree[p]);
        return;
    }
    if(ql <= mid)
        mdf(ls, l, mid, ql, qr);
    if(qr > mid)
        mdf(rs, mid + 1, r, ql, qr);
    upd(p);
}

ll qry(ll p, ll l, ll r, ll ql, ll qr) {
    if(ql <= l && r <= qr) {
        return tree[p];
    }

    ll sum = 0;

    if(ql <= mid) {
        sum += qry(ls, l, mid, ql, qr);
    }
    if(qr > mid) {
        sum += qry(rs, mid + 1, r, ql, qr);
    }

    return sum %= MOD;;
}

int main() {
    
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);

    n = read();
    m = read();
    k = read();

    for(ll i = 1; i <= n; ++i) {
        a[i] = read();
    }

    build(1, 1, n);

    while(m--) {
        ll op, x, y;

        cin >> op >> x >> y;

        if(op == 2) {
            write(qry(1, 1, n, x, y));
            putchar('\n');
        }
        else {
            mdf(1, 1, n, x, y);
        }
    }

    return 0;
}