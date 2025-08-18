#include <bits/stdc++.h>

#define N 200010
#define PI acos(-1.0)
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

int m, n;
double sgt[N << 2], cgt[N << 2], lazyA[N << 2];
int a[N];

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

inline double norm(double x) {
    x = fmod(x, 2 * PI);
    if (x < 0) x += 2 * PI;
    return x;
}

inline void ar(int p, double ang) {
    double cv = cos(ang);
    double sv = sin(ang);
    double ns = sgt[p] * cv + cgt[p] * sv;
    double nc = cgt[p] * cv - sgt[p] * sv;
    sgt[p] = ns;
    cgt[p] = nc;
    lazyA[p] = norm(lazyA[p] + ang);
}

inline void upd(int p) {
    sgt[p] = sgt[ls] + sgt[rs];
    cgt[p] = cgt[ls] + cgt[rs];
}

inline void pushup(int p) {
    if(lazyA[p] != 0) {
        ar(ls, lazyA[p]);
        ar(rs, lazyA[p]);
        lazyA[p] = 0;
    }
    return;
}

inline void build(int p, int l, int r) {
    lazyA[p] = 0;

    if(l == r) {
        sgt[p] = sin(a[l]);
        cgt[p] = cos(a[l]);
        return;
    }

    build(ls, l, mid);
    build(rs, mid + 1, r);

    upd(p);
}

inline void mdf(int p, int l, int r, int ql, int qr, double ang) {
    if(ql <= l && r <= qr) {
        ar(p, ang);
        return;
    }

    pushup(p);

    if(ql <= mid) 
    upd(ls, l, mid, ql, qr, ang);
    if(qr > mid) upd(rs, mid + 1, r, ql, qr, ang);

    upd(p);
}

inline double qry(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) 
        return sgt[p];

    pushup(p);

    double res = 0;

    if(ql <= mid) 
        res += qry(ls, l, mid, ql, qr);
    if(qr > mid) 
        res += qry(rs, mid + 1, r, ql, qr);

    return res;
}

int main() {

    n = read();

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    m = read();

    build(1, 1, n);

    while(m--) {
        int t = read();

        if(t == 1) {
            int l, r, v;
            l = read();
            r = read();
            v = read();
            double ang = (double)v;
            ang = norm(ang);
            upd(1, 1, n, l, r, ang);
        }
    }

    return 0;
}