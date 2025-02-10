#include <bits/stdc++.h>

#define N 2000010
#define ull unsigned long long
#define int unsigned long long

using namespace std;

int n, m, v;
int a[N], b[N], c[N];
int t[N];

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

inline void gen(int n, ull seed) {
    std::mt19937_64 rnd(seed);
    for(int i = 1; i <= n; ++i) {
    	a[i] = rnd() % ((long long)1e18) + 1;
		b[i] = rnd() % ((int)1e9) + 1;
		c[i] = rnd() % ((int)1e9) + 1;
        t[i] = a[i] + b[i] * c[i];
	}
}

signed main() {

    // freopen("task.in", "r", stdin);
    // freopen("task.out", "w", stdout);

    n = read();
    m = read();
    v = read();

    // readin

    if(n <= 100000) {
        for(int i = 1; i <= n; ++i) {
            a[i] = read();
            b[i] = read();
            c[i] = read();
            t[i] = a[i] + b[i] * c[i];
        }
    }
    else {
        int seed = read();
        gen(n, seed);
    }

    

    return 0;
}