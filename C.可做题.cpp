#include <bits/stdc++.h>

#define N 500010
#define ll long long
#define int long long

using namespace std;

int n, m;
int maxx = -0x7fffffff;
int sum = 0;

struct node {
    int a, b;
}c[N];

bool cmp(node x, node y) {
    return x.b < y.b;
}

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

inline int log2_ll(int x) {
    ll ans = 0;
    
}

inline int log2_int(int x) {
    int ans = 0;
    while((x >>= 1))
        ++ans;
    return ans;
}

inline int solve(int l, int r) {
    int ret = 0;
    int s = 10010;

    if(c[l].b == 1) {
        int tp = 0;
        for(int i = l; i <= r; ++i) {
            tp ^= c[i].a;
            ret += tp;
        }
    }
    else {
        for(int i = 30; i >= 0; --i) {
            int x = 1, y = 0;
            int d = 1, e = 0;
            for(int j = l; j <= r; ++j) {
                x ^= (c[j].a >> i) & 1;
                d += x;
            }
            for(int j = l; j <= r; ++j) {
                y ^= (c[j].a >> i) & 1;
                e += y;
            }
            ret += (1 << i) * min(d, e);
        }
    }
    return ret;
}

signed main() {

    n = read();
    m = read();

    for(int i = 1; i <= m; ++i) {
        c[i].b = read();
        c[i].a = read();
    }

    sort(c + 1, c + m + 1, cmp);

    int p = 1, q = 1;

    while(p <= m) {
        q = p;
        while(c[p].b + 1 == c[p + 1].b && p <= m) {
            ++p;
        }
        sum += solve(q, p);
        ++p;
    }

    cout << sum << endl;

    return 0;
}