#include <bits/stdc++.h>

#define N 5000010 
#define int long long
#define ll long long

using namespace std;

int n, m, q;
int l[N], r[N], bit[N];

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

inline int lowbit(int x) {
    return x & -x;
}

inline void add(int x, int y) {
    while(x <= n) {
        bit[x] += y;
        x += lowbit(x);
    }
}

inline int query(int x) {
    int res = 0;
    while(x) {
        res += bit[x];
        x -= lowbit(x);
    }
    return res;
}

signed main() {
    n = read();
    m = read();
    q = read();
    
    for(int i = 1; i <= m; ++i) {

    }
    
    for (ll u, v, i = 1; i < n; i++) {
        u = read();
        v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    for (ll i = 1; i <= m; i++) {
        q[i].op = read();
        q[i].a = read();
        q[i].b = read();
        
        if (q[i].op == 3) {
            mt[q[i].a].push_back({q[i].b, i});
            mt[q[i].b].push_back({q[i].a, i});
        }
    }
    
    build(r);
    
    for (ll i = 1; i <= n; i++) 
        v1.add(dfn[i], lv[i], v[i]);
    
    for (ll i = 1; i <= m; i++) {
        ll u = q[i].a;
        ll v = q[i].b;
        
        if (q[i].op == 1) 
            v1.add(dfn[u], lv[u], v);
        else if (q[i].op == 2) {
            v1.add(dfn[u], lv[u], v * (1 - dep[u]));
            v2.add(dfn[u], lv[u], v);
        }
        else {
            printf("%lld\n", dist(u) + dist(v) - dist(lca[i]) - dist(LCA::rt[lca[i]]));
        }
    }
    
    return 0;
}