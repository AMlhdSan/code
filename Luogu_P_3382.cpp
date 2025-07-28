#include <bits/stdc++.h>
using namespace std;

int n;
double l, r;
double a[15], b[15];

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

int main() {

    cin >> n >> l >> r;
    for(int i = 1; i <= n + 1; ++i) {
        cin >> a[i];// 各项系数
    }

    // 求导

    for(int i = 1; i <= n; ++i) {
        b[i] = a[i] * i;
    }

    b[n + 1] = 0; // 最后一项的导数为0

    // 二分法求极大值

    double mid, f1, f2;
    while (r - l > 1e-6) {
        mid = (l + r) / 2;
        f1 = 0, f2 = 0;
        for(int i = 1; i <= n + 1; ++i) {
            f1 += a[i] * pow(mid, i);
            f2 += b[i] * pow(mid, i - 1);
        }
        if (f2 > 0) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << fixed << setprecision(8) << (l + r) / 2.0 << endl;
    return 0;
}