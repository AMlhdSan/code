#include <bits/stdc++.h>

#define N 100001
#define ll long long
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

int n, q;
double a[N], sum[N << 2], add[N << 2], sumaf[N << 2];

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

double sqr(double x) { return x * x; }

void pushdown(int p, int l, int r) {
    if (add[p] != 0) {
        int m = mid;
        sum[ls] += add[p] * (m - l + 1);
        sum[rs] += add[p] * (r - m);
        sumaf[ls] += 2 * sum[ls] * add[p] + (m - l + 1) * sqr(add[p]);
        sumaf[rs] += 2 * sum[rs] * add[p] + (r - m) * sqr(add[p]);
        add[ls] += add[p];
        add[rs] += add[p];
        add[p] = 0;
    }
}

void build(int p, int l, int r) {
    add[p] = 0;
    if (l == r) {
        sum[p] = a[l];
        sumaf[p] = sqr(a[l]);
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    sum[p] = sum[ls] + sum[rs];
    sumaf[p] = sumaf[ls] + sumaf[rs];
}

void modify(int p, int l, int r, int ql, int qr, double x) {
    if (ql <= l && r <= qr) {
        sumaf[p] += 2 * sum[p] * x + (r - l + 1) * sqr(x);
        sum[p] += (r - l + 1) * x;
        add[p] += x;
        return;
    }
    pushdown(p, l, r);
    if (ql <= mid) modify(ls, l, mid, ql, qr, x);
    if (qr > mid) modify(rs, mid + 1, r, ql, qr, x);
    sum[p] = sum[ls] + sum[rs];
    sumaf[p] = sumaf[ls] + sumaf[rs];
}

double query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return sum[p];
    pushdown(p, l, r);
    double res = 0;
    if (ql <= mid) res += query(ls, l, mid, ql, qr);
    if (qr > mid) res += query(rs, mid + 1, r, ql, qr);
    return res;
}

double queryVar(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        double mean = sum[p] / (r - l + 1);
        return sumaf[p] / (r - l + 1) - sqr(mean);
    }
    pushdown(p, l, r);
    double res = 0, total = 0;
    if (ql <= mid) {
        double temp = queryVar(ls, l, mid, ql, qr);
        total += query(ls, l, mid, ql, qr);
        res += temp;
    }
    if (qr > mid) {
        double temp = queryVar(rs, mid + 1, r, ql, qr);
        total += query(rs, mid + 1, r, ql, qr);
        res += temp;
    }
    double mean = total / (qr - ql + 1);
    return res / (qr - ql + 1) - sqr(mean);
}

int main() {
    n = read(), q = read();
    for (int i = 1; i <= n; ++i) scanf("%lf", &a[i]);
    build(1, 1, n);
    while (q--) {
        int op = read(), x = read(), y = read();
        if (op == 1) {
            double k;
            scanf("%lf", &k);
            modify(1, 1, n, x, y, k);
        } else if (op == 2) {
            printf("%.4lf\n", query(1, 1, n, x, y) / (y - x + 1));
        } else if (op == 3) {
            printf("%.4lf\n", queryVar(1, 1, n, x, y));
        }
    }
    return 0;
}
