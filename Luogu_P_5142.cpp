#include <bits/stdc++.h>

#define int long long
#define N 100010
#define MOD 1000000007

using namespace std;

int n, m;
int b[N], t1[N], t2[N];

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

inline void add(int* t, int i, int v) {
    if(v < 0) {
        v = (v % MOD + MOD) % MOD;
    } else {
        v %= MOD;
    }
    for(; i <= n; i += i & -i) {
        t[i] += v;
        if(t[i] >= MOD) 
            t[i] -= MOD;
    }
}

inline int sum(int* t, int i) {
    int r = 0;
    for(; i; i -= i & -i) {
        r += t[i];
        if(r >= MOD) 
            r -= MOD;
    }
    return r;
}

inline int qpow(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

signed main() {
    n = read();
    m = read();
    for(int i = 1; i <= n; i++) {
        b[i] = read() % MOD;
        add(t1, i, b[i]);
        add(t2, i, (b[i] * b[i]) % MOD);
    }

    while(m--) {
        int op = read();
        if(op == 1) {
            int x = read(), y = read();
            add(t1, x, y);
            add(t2, x, (y * y) % MOD);
            b[x] += y;
            if(b[x] >= MOD) 
                b[x] -= MOD;
        } else if(op == 2) {

            int x = read(), y = read();
            writeln((sum(t1, y) - sum(t1, x - 1) + MOD) % MOD);
        } else if(op == 3) {
            int x = read(), y = read();
            writeln((sum(t2, y) - sum(t2, x - 1) + MOD) % MOD);
        }
    }
    return 0;
}