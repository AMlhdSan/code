#include <bits/stdc++.h>

#define N 200010
#define int long long
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("-feliminate-unused-debug-types")

using namespace std;

int n;
int a[N];
int tree[N << 2];
int tag[N << 2];

inline int check(int x) {
    return (x == 0 || x == 1);
}

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

inline void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(int x) {
    write(x);
    putchar('\n');
}

inline void upd(int p) {
    tree[p] = tree[ls] + tree[rs];
    tag[p] = tag[ls] & tag[rs];
}

inline void build(int p, int l, int r) {
    if(l == r) {
        tree[p] = a[l];
        tag[p] = check(tree[p]);
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    upd(p);
}

inline void mdf(int p, int l, int r, int ql, int qr) {
    if(tag[p])
        return;
    if(l == r) {
        tree[p] = sqrt(tree[p]);
        tag[p] = max(tag[p], check(tree[p]));
        return;
    }
    if(ql <= mid)
        mdf(ls, l, mid, ql, qr);
    if(qr > mid)
        mdf(rs, mid + 1, r, ql, qr);
    upd(p);
}

inline void faster() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


}

inline int qry(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return tree[p];
    }
    int sum = 0;
    if(ql <= mid)
        sum += qry(ls, l, mid, ql, qr);
    if(qr > mid)
        sum += qry(rs, mid + 1, r, ql, qr);
    return sum;
}

signed main() {

    faster();

    n = read();

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    build(1, 1, n);

    for(int i = 1; i <= n; ++i) {
        int op, x, y, c;
        op = read();
        x = read();
        y = read();
        c = read();
        // if(x > y) {
        //     swap(x, y);
        // }
        if(op == 0) {
            mdf(1, 1, n, x, y);
        }
        else {
            writeln(qry(1, 1, n, x, y));
        }
    }

    return 0;
}