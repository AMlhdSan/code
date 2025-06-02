#include <bits/stdc++.h>

#define M 100010
#define mid ((l + r) >> 1)

using namespace std;

int n, m, q;
int a[M], b[M];
int val[M];
int cnt;
int fa[M], sz[M];
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

inline void add(int u, int v) {
    nxt[++e] = head[u];
    head[u] = e;
    to[e] = v;
}

inline int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

inline bool check(int t) {

}

inline int solve(int x, int y, int z) {
    int l = 1, r = n;
    int ans;
    while(l < r) {
        int midd = (l + r) >> 1;
        if(check(midd)) {
            ans = midd;
            l = midd + 1;
        }
        else {
            r = midd - 1;
        }
    }
    return ans;
}

int main() {

    n = read();
    cnt = n;
    m = read();

    for(int i = 1; i <= M; ++i) {
        fa[i] = i;
    }

    for(int i = 1; i <= m; ++i) {
        a[i] = read();
        b[i] = read();
        a[i] = find(a[i]);
        b[i] = find(b[i]);
        if(a[i] != b[i]) {
            fa[a[i]] = fa[b[i]] = ++cnt;
            add(a[i], cnt);
            add(b[i], cnt);
            val[cnt] = i;
        }
    }

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