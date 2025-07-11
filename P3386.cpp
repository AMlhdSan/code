#include <bits/stdc++.h>

#define N 500010
#define ll long long

using namespace std;

ll nxt[N], to[N], head[N], w[N];
ll now[N];
int d[N];
ll n, m, s, t;
ll cnt = 1;
int e;

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

inline void add(int u, int v, ll c) {
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
    w[cnt] = c;
    
    nxt[++cnt] = head[v];
    head[v] = cnt;
    to[cnt] = u;
    w[cnt] = 0;
}

inline bool bfs() {
    queue<int> q;
    q.push(s);
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;
    now[s] = head[s];
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i = head[x]; i; i = nxt[i]) {
            int v = to[i];
            if(d[v] == 0x3f3f3f3f && w[i] > 0) {
                d[v] = d[x] + 1;
                now[v] = head[v];
                q.push(v);
                if(v == t) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

inline ll dfs(int x, ll flow) {
    if(x == t) {
        return flow;
    }
    ll k;
    for(int i = now[x]; i; i = nxt[i]) {
        now[x] = i;
        int v = to[i];
        if(d[v] != d[x] + 1 || w[i] <= 0) {
            continue;
        }
        k = dfs(v, min(flow, w[i]));
        if(k) {
            w[i] -= k;
            w[i ^ 1] += k;
            return k;
        }
        else {
            d[v] = 0x3f3f3f3f;
        }
    }
    return 0;
}

inline ll dinic() {
    ll sum = 0;
    while(bfs()) {
        sum += dfs(s, 0x7fffffff);
    }
    return sum;
}

int main() {
    n = read();
    m = read();
    e = read();
    
    s = 0;
    t = n + m + 1;
    
    for(int i = 1; i <= n; i++) {
        add(s, i, 1);
    }
    
    for(int i = 1; i <= m; i++) {
        add(n + i, t, 1);
    }
    
    for(int i = 0; i < e; i++) {
        int u = read();
        int v = read();
        add(u, n + v, 1);
    }
    
    writeln(dinic());
    
    return 0;
}