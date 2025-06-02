#include <bits/stdc++.h>

#define N 70010
#define M 100010
#define mod 1000000007

using namespace std;

int n, m, q;
int A, B, C, P;
int sum = 0;
int fa[N];
int dep[N];
int dp[N][20];
int mx[N][20];
vector<pair<int, int>> adj[N];

struct edge {
    int u, v, w;
    bool operator<(const edge& other) const {
        return w < other.w;
    }
} e[M];

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

inline int rnd() {
    return A = (A * B + C) % P;
}

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void dfs(int u, int f, int d) {
    dep[u] = d;
    dp[u][0] = f;
    for(int i = 1; i < 20; ++i) {
        dp[u][i] = dp[dp[u][i-1]][i-1];
        mx[u][i] = max(mx[u][i-1], mx[dp[u][i-1]][i-1]);
    }
    for(auto& edge : adj[u]) {
        int v = edge.first, w = edge.second;
        if(v != f) {
            mx[v][0] = w;
            dfs(v, u, d + 1);
        }
    }
}

int solve(int u, int v) {
    if(find(u) != find(v)) return 0;
    
    int ans = 0;
    if(dep[u] < dep[v]) swap(u, v);
    
    for(int i = 19; i >= 0; --i) {
        if(dep[dp[u][i]] >= dep[v]) {
            ans = max(ans, mx[u][i]);
            u = dp[u][i];
        }
    }
    
    if(u == v) return ans;
    
    for(int i = 19; i >= 0; --i) {
        if(dp[u][i] != dp[v][i]) {
            ans = max(ans, max(mx[u][i], mx[v][i]));
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    
    ans = max(ans, max(mx[u][0], mx[v][0]));
    return ans;
}

int main() {
    n = read();
    m = read();
    
    for(int i = 1; i <= n; ++i) fa[i] = i;
    
    for(int i = 1; i <= m; ++i) {
        e[i].u = read();
        e[i].v = read();
        e[i].w = read();
    }
    
    sort(e + 1, e + m + 1);
    
    for(int i = 1; i <= m; ++i) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        int fu = find(u), fv = find(v);
        if(fu != fv) {
            fa[fu] = fv;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
    }
    
    for(int i = 1; i <= n; ++i) {
        if(find(i) == i && dep[i] == 0) {
            dfs(i, i, 1);
        }
    }
    
    q = read();
    A = read();
    B = read();
    C = read();
    P = read();
    
    while(q--) {
        int u = rnd() % n + 1;
        int v = rnd() % n + 1;
        sum = (sum + solve(u, v)) % mod;
    }
    
    writeln(sum);
    return 0;
}