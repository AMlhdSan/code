#include <bits/stdc++.h>

#define N 100010
#define M 500010
#define int long long

using namespace std;

int n, m, Q, v;
int fa[N];
bool ans[M];

struct node {
    int u, v, w;
}e[M];

struct query {
    int u, v;
}q[M];

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
        fa[x] = y;
    }
}

inline void readin() {
    n = read();
    m = read();
    Q = read();
    v = read();

    for(int i = 1; i <= m; ++i) {
        e[i].u = read();
        e[i].v = read();
        e[i].w = read();
    }

    for(int i = 1; i <= Q; ++i) {
        q[i].u = read();
        q[i].v = read();
    }
}

inline void seek(int t) {
    for(int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
    for(int i = 1; i <= m; ++i) {
        if((e[i].w & t) == t) {
            merge(e[i].u, e[i].v);
        }
    }
    for(int i = 1; i <= Q; ++i) {
        if(!ans[i] && find(q[i].u) == find(q[i].v)) {
            ans[i] = true;
        }
    }
}

inline void solve() {

    seek(v);

    int now = 0;
    for(int i = 59; i >= 0; --i) {
        now |= 1ll << i;
        if(!(v >> i & 1)) {
            seek(now);
            now ^= 1ll << i;
        }
    }
}

inline void output() {
    for(int i = 1; i <= Q; ++i) {
        if(ans[i]) {
            puts("Yes");
        }
        else {
            puts("No");
        }
    }
}

signed main() {

    freopen("path.in", "r", stdin);
    freopen("path.out", "w", stdout);

    readin();

    solve();

    output();

    return 0;
}