#include <bits/stdc++.h>

#define N 100001
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

int n, m;
int a[N];
int xx, yy;
int tree[N << 4];

inline int read() {
	int x = 0;
    int f = 1;
    char ch = getchar();
	while(ch < '0' || ch > '9') {
        if(ch == '-') 
            f = -1;
        ch = getchar();
    }
	while(ch >= '0' && ch <= '9') {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
	return x * f;
}

void upd(int p) {
    tree[p] = max(tree[ls], tree[rs]);
}

void build(int p, int l, int r) {
    if(l == r) {
        tree[p] = a[l];
        return ;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    upd(p);
}

int qry(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return tree[p];
    }
    int ans = -0x7fffffff;
    if(ql <= mid) {
        ans = max(ans, qry(ls, l, mid, ql, qr));
    }
    if(qr > mid) {
        ans = max(ans, qry(rs, mid + 1, r, ql, qr));
    }
    return ans;
}


int main() {

    cout.tie(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    build(1, 1, n);

    while(m--) {
        xx = read();
        yy = read();
        printf("%d\n", qry(1, 1, n, xx, yy));
    }

    return 0;
}