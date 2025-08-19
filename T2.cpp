#include <bits/stdc++.h>

#define N 100001

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

vector<int> g[N];
bool vis[N];

void dfs(int u, int v) {
    if (vis[u]) return;
    vis[u] = true;
    if (g[u][v] == v) {
        writeln(v);
        return;
    }
    for (int i = 0; i < g[u].size(); i++) {
        dfs(g[u][i], v);
    }
}

int main() {
    int n = read();
    
    for (int i = 0; i < n - 1; i++) {
        int u = read(), v = read();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    for (int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
    }
    
    memset(vis, false, sizeof(vis));
    dfs(1, 1);
    
    return 0;
}