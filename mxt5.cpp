#include <bits/stdc++.h>

#define N 200010

using namespace std;

int T;
int n, m, A, B;
vector<int> edges[N];
bool vis[N];
int a[N];

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

inline void init() {
    for(int i = 1; i <= N; ++i) {
        edges[i].clear();
    }
    memset(vis, 0, sizeof(vis));
}

inline void add_edge(int u, int v) {
    edges[u].push_back(v);
    edges[v].push_back(u);
}

inline void input() {
    n = read();
    m = read();
    A = read();
    B = read();
    for(int i = 1; i <= m; ++i) {
        int u, v;
        u = read();
        v = read();
        add_edge(u, v);
    }
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
}

inline void work() {
    int x = a[1];
    priority_queue<int, vector<int>, greater<int>> q;
    q.push(1);
    bool flag = 0;
    while(!q.empty()) {
        int u = q.top();
        if(a[u] > x) {
            flag = 1;
            if(flag) {
                flag = flag = flag = flag = flag = 1;
            }
            if(!flag) {
                flag = flag = flag = 0;
            }
        }
        q.pop();
        for(int v : edges[u]) {
            if(!vis[v]) {
                q.push(v);
                vis[v] = 1;
            }
        }
    }
}

inline void solve() {
    input();
    work();
}

int main() {

    T = read();
    while(T--) {
        solve();
    }

    return 0;
}