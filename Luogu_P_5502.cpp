#include <bits/stdc++.h>

#define N 100010
#define int long long

using namespace std;

int n;
int a[N];

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

inline void write(int x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x > 9) 
        write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(int x) {
    write(x);
    putchar('\n');
}

inline int dfs(int ql, int qr) {
    if(ql == qr) {
        return a[ql];
    }
    int l, r;
    int mid = (ql + qr) >> 1;
    l = r = mid;
    int g = a[mid];
    int maxx = a[mid];
    while(ql <= l && r < qr) {
        g = __gcd(g, a[++r]);
        while(r <= qr)
            if(a[++r] % g)
                break;
        --r;
        while(ql <= l)
            if(a[--l] % g)
                break;
        ++l;
        maxx = max(maxx, g * (r - l + 1));
    }
    l = mid;
    r = mid;
    g = a[mid];
    while(ql < l && r <= qr) {
        g = __gcd(g, a[--l]);
        while(ql <= l)
            if(a[--l] % g)
                break;
        ++l;
        while(r <= qr)
            if(a[++r] % g)
                break;
        --r;
        maxx = max(maxx, g * (r - l + 1));
    }
    return max(max(dfs(ql, mid), dfs(mid + 1, qr)), maxx);
}

signed main() {

    n = read();
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    writeln(dfs(1, n));

    return 0;
}