#include <bits/stdc++.h>

#define N 100010

using namespace std;

int n, m;
int cnt = 0;
int num = 0;
int edge = 1;
int s, t;
int nxt[N], to[N], head[N], d[N];
int w[N], match[N], start[N], vis[N];

void add(int u, int v, int c) {
    ++edge;
    nxt[edge] = head[u];
    head[u] = edge;
    to[edge] = v;
    w[edge] = c;

    ++edge;
    nxt[edge] = head[v];
    head[v] = edge;
    to[edge] = u;
    w[edge] = 0;
}

int bfs() {
    queue<int> q;
    q.push(s);
    memset(d, 0, sizeof(d));
    d[s] = 1;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i = head[x]; i; i = nxt[i]) {
            int p = to[i];
            if(d[p] || w[i] <= 0) {
                continue;
            }
            d[p] = d[x] + 1;
            q.push(p);
        }  
    }
    return d[t];
}

int dfs(int x, int flow) {
    if(x == t) {
        return flow;
    }
    int k;
    for(int i = head[x]; i; i = nxt[i]) {
        int p = to[i];
        if(d[p] != d[x] + 1 || w[i] <= 0) {
            continue;
        }
        
        if(k = dfs(p, min(flow, w[i]))) {
            w[i] -= k;
            w[i ^ 1] += k;
            if(p != t) {
                match[x >> 1] = p >> 1;
            }
            return k;
        }
    }
    return 0;
}

int dinic() {
    int ret = 0, tmp;
    while(bfs()) {
        while((tmp = dfs(s, INT_MAX)) > 0) {
            ret += tmp;
        }
    }
    return ret;
}

int main() {

    cin >> n;

    s = 0, t = 28374;

    while(cnt <= n) {
        ++num;
        add(s, num << 1, 1);
        add((num << 1) | 1, t, 1);
        for(int i = sqrt(num) + 1; i * i < num * 2; ++i) {
            add((i * i - num) << 1, (num << 1) | 1, 1);
        }
        if(dinic() == 0) {
            start[++cnt] = num;
        }
    }

    cout << --num << endl;

    for(int i = 1; i <= n; ++i) {
        if(vis[start[i]]) {
            continue;
        }
        int p = start[i];
        vis[p] = 1;
        while(p) {
            cout << p << ' ';
            p = match[p];
            vis[p] = 1;
        }
        cout << endl;
    }

    return 0;
}