#include <bits/stdc++.h>

#define N 10010

using namespace std;

int n, m;
int head[N], nxt[N], to[N], w[N], e = 0;
int uu[N], vv[N], cc[N];

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

int dis[N];
bool vis[N];
int cnt[N];

inline bool spfa() {
    // memset(head, -1, sizeof(head));
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, false, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    dis[0] = 0;
    queue<int> q;
    q.push(0);
    vis[0] = true;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;

        for(int i = head[u]; i; i = nxt[i]) {
            int v = to[i];
            int c = w[i];

            if(dis[v] > dis[u] + c) {
                dis[v] = dis[u] + c;
                cnt[v]++;

                if(cnt[v] > n) {
                    puts("NO");
                    return false;
                }

                // if(!vis[v]) {
                    // vis[v] = true;
                    q.push(v);
                // }
            }
        }
    }
    return true;
}

int main() {

    n = read();
    m = read();

    for(int i = 1; i <= m; ++i) {
        int u, v, c;
        u = read();
        v = read();
        c = read();
        uu[i] = u;
        vv[i] = v;
        cc[i] = c;

        // x_u - x_v <= c

        add_edge(v, u, c);
    }

    for(int i = 1; i <= n; ++i) {
        add_edge(0, i, 0); // Add a source node with zero cost to all nodes
    }

    bool flag = spfa();

    if(flag) {
        for(int i = 1; i <= n; ++i) {
            write(dis[i]);
            putchar(' ');
        }
    }

    return 0;
}