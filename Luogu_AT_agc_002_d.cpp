#include <bits/stdc++.h>

#define M 200010
#define mid ((l + r) >> 1)

using namespace std;
// Luogu AT: https://www.luogu.com.cn/problem/AT_agc_002_d

int n, m, q;
int a[M], b[M];

int val[M];
int cnt;
int fa[M], sz[M];
int dp[M][21];
int head[M * 2], nxt[M * 2], to[M * 2], e = 0;

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

inline void dfs(int u) {
    if(!head[u]) 
        sz[u] = 1;
    for(int i = head[u]; i; i = nxt[i]) {
        int v = to[i];
        dp[v][0] = u;
        for(int j = 1; j <= 20; ++j) {
            dp[v][j] = dp[dp[v][j - 1]][j - 1];
        }
        dfs(v);
        sz[u] += sz[v];
    }
}

inline void add(int u, int v) {
    nxt[++e] = head[u];
    head[u] = e;
    to[e] = v;
}

inline int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

inline bool check(int t, int x, int y, int z) {
    for(int i = 19; i >= 0; --i) {
        if(val[dp[x][i]] <= t) {
            x = dp[x][i];
        }
    }
    for(int i = 19; i >= 0; --i) {
        if(val[dp[y][i]] <= t) {
            y = dp[y][i];
        }
    }
    if(x == y) {
        return (sz[x] >= z);
    }
    else {
        return (sz[x] + sz[y] >= z);
    }
}

inline int solve(int x, int y, int z) {
    int l = 1, r = m;
    // int ans;
    while(l <= r) {
        int midd = (l + r) >> 1;
        if(check(midd, x, y, z)) {
            r = midd - 1;
        }
        else {
            l = midd + 1;
            // ans = midd;
        }
    }
    return l;
}

int main() {

    n = read();
    cnt = n;
    m = read();

    for(int i = 1; i <= m * 2; ++i) {
        fa[i] = i;
    }

    for(int i = 1; i <= m; ++i) {
        a[i] = read();
        b[i] = read();
        a[i] = find(a[i]);
        b[i] = find(b[i]);
        if(a[i] != b[i]) {
            fa[a[i]] = fa[b[i]] = ++cnt;
            add(cnt, a[i]);
            add(cnt, b[i]);
            val[cnt] = i;
        }
    }

    val[0] = 0x7fffffff;
    dfs(cnt);

    q = read();

    while(q--) {
        int x, y, z;
        x = read();
        y = read();
        z = read();
        writeln(solve(x, y, z));
    }

    return 0;
}