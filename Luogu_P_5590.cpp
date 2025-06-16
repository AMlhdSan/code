#include <bits/stdc++.h>

#define N 3010
#define PII pair<int, int>

using namespace std;

int n, m;
int du[N], dv[N];
vector<PII> edges[N];
vector<PII> adges[N];
bool tag1[N], tag2[N];
int nxt[N], head[N], to[N], w[N], e = 0;

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

inline void add_edge1(int u, int v, int c) {
    edges[u].push_back(make_pair(v, c));
}

inline void add_edge2(int u, int v, int c) {
    adges[u].push_back(make_pair(v, c));
}

inline void dfs1(int p, int pre) {
    for(PII au : edges[p]) {
        int v = au.first;
        int index = au.second;
        dfs1(v, p);
        tag1[index] = 1;
    }
}

inline void dfs2(int p, int pre) {
    for(PII au : adges[p]) {
        int v = au.first;
        int index = au.second;
        dfs2(v, p);
        tag2[index] = 1;
    }
}

int dis[N];
bool vis[N];

inline void spfa() {
    queue<int> q;
    memset(dis, 0x3f, sizeof(dis));
    vis[1] = 1;
    dis[1] = 0;
}

int main() {

    n = read();
    m = read();

    for(int i = 1; i <= m; ++i) {
        du[i] = read();
        dv[i] = read();
        add_edge1(du[i], dv[i], i);
        add_edge2(dv[i], du[i], i);
    }

    dfs1(1, 0);
    dfs2(n, 0);

    for(int i = 1; i <= m; ++i) {
        if(tag1[i] && tag2[i]) {
            add_edge(du[i], dv[i], 9);
            add_edge(dv[i], du[i], -1);
        }
    }

    spfa();

    return 0;
}