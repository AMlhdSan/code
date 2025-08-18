#include <bits/stdc++.h>

#define N 200010
#define PI acos(-1.0)
#define ls (p << 1)
#define rs (p << 1 | 1)

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

inline void build(int p, int l, int r) {
    lazyA[p] = 0;

    if(l == r) {
        sgt[p] = sin(a[l]);
        cgt[p] = cos(a[l]);
        return;
    }
}

int main() {



    return 0;
}