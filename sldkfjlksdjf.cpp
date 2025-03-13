#include <bits/stdc++.h>

#define N 500010
#define ll long long

using namespace std;

int n, m;
vector<int> g[N];
int step[N];
int mx[N];
int fa[N][110];

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

void dfs(int x, int f) {
    mx[x] = max(x, mx[f]);
    fa[x][0] = f;
    step[x] = step[f] + 1;
    for (int i = 0; i < g[x].size(); i++) {
        if (g[x][i] != f) {
            dfs(g[x][i], x);
        }
    }
}

int lca(int x, int y) {
    if (step[x] > step[y]) swap(x, y);
    int k = 0;
    while (1 << (k + 1) <= step[y]) k++;
    for (int i = k; i >= 0; i--) {
        if (step[x] <= step[fa[y][i]]) {
            y = fa[y][i];
        }
    }
    if (x == y) return x;
    for (int i = k; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}

int main() {
    n = read();
    for (int i = 2; i <= n; i++) {
        int x = read();
        g[x + 1].push_back(i);
    }
    
    dfs(1, 0);
    
    for (int i = 1; i < 100; i++) {
        for (int j = 1; j <= n; j++) {
            fa[j][i] = fa[fa[j][i - 1]][i - 1];
        }
    }
    
    m = read();
    vector<int> v;
    
    while (m--) {
        int len = read();
        v.clear();
        
        for (int i = 1; i <= len; i++) {
            int x = read();
            v.push_back(x + 1);
        }
        
        int LCA = lca(v[0], v[1]);
        for (int i = 2; i < len; i++) {
            LCA = lca(LCA, v[i]);
        }
        
        writeln(mx[LCA] - 1);
    }
    
    return 0;
}