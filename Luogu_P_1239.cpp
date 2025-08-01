/*
#include <bits/stdc++.h>
using namespace std;

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

int cnt[10];

void solve(int n) {
    for (long long p = 1; p <= n; p *= 10) {
        int high = n / (p * 10);
        int cur = (n / p) % 10;
        int low = n % p;
        for (int d = 0; d <= 9; ++d) {
            if (d != 0) {
                if (d < cur) cnt[d] += (high + 1) * p;
                else if (d == cur) cnt[d] += high * p + (low + 1);
                else cnt[d] += high * p;
            } else {
                if (high == 0) continue; // 最高位不能是 0
                if (cur == 0) cnt[0] += (high - 1) * p + (low + 1);
                else cnt[0] += high * p;
            }
        }
    }
}

int main() {
    int n = read();
    solve(n);
    for (int i = 0; i < 10; ++i) writeln(cnt[i]);
    return 0;
}

*/

#include <bits/stdc++.h>
using namespace std;

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

int a[10];

void solve(int n) {
    int len = log10(n) + 1;
    for (int i = 0, p = 1; i < len; ++i, p *= 10) {
        int l = n / (p * 10), r = n % p, d = (n / p) % 10;
        for (int j = 0; j < 10; ++j) {
            a[j] += l * p;
            if (j == 0 && l == 0) a[j] -= p;
        }
        if (d > 0) a[0] -= p;
        for (int j = 0; j < d; ++j) a[j] += p;
        a[d] += r + 1;
    }
}

int main() {

    int n;
    n = read();
    solve(n);
    for (int i = 0; i < 10; ++i) 
        writeln(a[i]);
    return 0;
}
