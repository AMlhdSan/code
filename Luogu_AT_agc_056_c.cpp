#include <bits/stdc++.h>

#define N 4000010

using namespace std;

int n, m;
int l, r;
int head[N], to[N], nxt[N], w[N], e = 0;
int dis[N];

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

inline void add_edge(int u, int v, int c) {
    nxt[++e] = head[u];
    head[u] = e;
    to[e] = v;
    w[e] = c;
}

inline void dijsktra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    memset(dis, 0x3f, sizeof(dis));
    dis[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dis[u]) continue;
        for (int i = head[u]; i; i = nxt[i]) {
            int v = to[i], c = w[i];
            if (dis[v] > dis[u] + c) {
                dis[v] = dis[u] + c;
                // 如果是 0 则不加权,如果是 1 则加权.
                // if (c != 0) dis[v] = d + 1;
                // else dis[v] = d;
                // else dis[v]--;
                pq.push({dis[v], v});
            }
        }
    }
}

int main() {

    n = read();
    m = read();

    for(int i = 1; i <= m; ++i) {
        l = read();
        r = read();
        add_edge(r, l - 1, 0);
        add_edge(l - 1, r, 0);
    }

    for(int i = 1; i <= n; ++i) {
        add_edge(i, i - 1, 1);
        add_edge(i - 1, i, 1);
    }

    dijsktra();

    // 遇 0 加 1,遇 1 减 1.
    for(int i = 1; i <= n; ++i) {
        putchar((dis[i] - dis[i - 1] < 0) + '0');
    }
    return 0;
}