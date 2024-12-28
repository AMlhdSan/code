#include <bits/stdc++.h>

#define N 300010

using namespace std;

int n;

int head[N], to[N], nxt[N], w[N], e = 0;

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

inline void add_edge(int u, int v, int c) {
    to[++e] = v;
    nxt[e] = head[u];
    head[u] = e;
    w[e] = c;
}

inline void dfs(int p, int pre) {
    for(int i = head[p]; i; i = nxt[i]) {
        int v = to[i];
        if(v != pre) {
            dfs(v, p);
        }
    }
}

int main() {

    cout << __cplusplus << '\n';

    n = read();

    for(int i = 1; i <= n - 1; ++i) {
        int u = read(), v = read(), c = read();
        add_edge(u, v, c);
        add_edge(v, u, c);
    }

    return 0;
}