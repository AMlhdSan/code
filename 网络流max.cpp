#include <bits/stdc++.h>

#define N 500010

using namespace std;

long long nxt[N], to[N], head[N], w[N];
long long now[N];
int d[N];
long long n, m, s, t;
long long cnt = 1;

inline void add(int u, int v, long long c) {
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

inline long long dfs(int x, long long flow) {
    if(x == t) {
        return flow;
    }
    long long k;
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

inline long long dinic() {
    long long sum = 0;
    while(bfs()) {
        sum += dfs(s, 0x7fffffff);
    }
    return sum;
}

int main() {

    cin >> n >> m >> s >> t;

    while(m--) {
        long long u, v, c;
        scanf("%lld%lld%lld", &u, &v, &c);
        add(u, v, c);
    }

    cout << dinic() << endl;

    return 0;
}