#include <bits/stdc++.h>

#define int long long
#define N 1000100
#define LM 1000000000000000000

#define ls p << 1
#define rs p << 1 | 1
#define mid ((l + r) >> 1)

using namespace std;

int n, t;
int p[N], d[N];
int dp[N];
int maxx = LM;

int tree[N << 2];

inline int read() {
    int x = 0, f = 1;
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

inline void upd(int p) {
    tree[p] = min(tree[ls], tree[rs]);
}

inline void mdf(int p, int l, int r, int x, int v) {
    if(l == r) {
        tree[p] = v;
        return;
    }
    if(x <= mid) {
        mdf(ls, l, mid, x, v);
    }
    else {
        mdf(rs, mid + 1, r, x, v);
    }
    upd(p);
}

inline int qry(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return tree[p];
    }
    int res = LM;
    if(ql <= mid) {
        res = min(res, qry(ls, l, mid, ql, qr));
    }
    if(qr > mid) {
        res = min(res, qry(rs, mid + 1, r, ql, qr));
    }
    return res;
}

inline bool check(int k) {
	for(int i = 2; i <= n; ++i) {
		dp[i] = qry(1, 1, n, max(1ll, i - k), i - 1) + d[i];
		mdf(1, 1, n, i, dp[i]);
	}
	return (dp[n] <= t);
}

signed main() {

    // freopen("journey.in", "r", stdin);
    // freopen("journey.out", "w", stdout);

	n = read();
    t = read();

	t -= n - 1;

	for(int i = 1; i <= n - 1; ++i) 
        p[i] = read();
	for(int i = 2; i <= n - 1; ++i) 
        d[i] = read();
	int l = 1, r = n - 1;
	while(l < r) {
		if(check(mid)) 
            r = mid;
		else 
            l = mid + 1;
	}
	for(int i = l; i < n; ++i) 
        maxx = min(maxx, p[i]);
	cout << maxx << endl;
    return 0;
}