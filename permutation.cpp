#include <bits/stdc++.h>

#define N 100001
#define MOD 1000000007
#define ll long long

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

inline void write(ll x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(ll x) {
    write(x);
    putchar('\n');
}

int t, n, m;
int a[15][15];
set<vector<int>> vis;

void dfs(vector<int>& cur, int dep) {
    if (dep == 0) {
        vis.insert(cur);
        return;
    }
    
    for (int i = 0; i < m; ++i) {
        vector<int> nxt(n);
        for (int j = 0; j < n; ++j) {
            nxt[j] = cur[a[i][j]];
        }
        dfs(nxt, dep - 1);
    }
}

int main() {

    // freopen("permutation.in", "r", stdin);
    // freopen("permutation.out", "w", stdout);

    t = read();
    
    while (t--) {
        n = read();
        m = read();
        
        vis.clear();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                a[i][j] = read() - 1;
            }
        }
        
        vector<int> init(n);
        for (int i = 0; i < n; ++i) {
            init[i] = i;
        }
        
        for (int len = 1; len <= min(20, n * m); ++len) {
            int sz = vis.size();
            dfs(init, len);
            if (vis.size() == sz) break;
        }
        
        writeln(vis.size());
    }
    
    return 0;
}