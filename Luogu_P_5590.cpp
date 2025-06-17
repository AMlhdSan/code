#include <bits/stdc++.h>

#define N 5000
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
    tag1[p] = 1;
    for(PII au : edges[p]) {
        int v = au.first;
        if(!tag1[v])dfs1(v, p);
    }
}

inline void dfs2(int p, int pre) {
    tag2[p] = 1;
    for(PII au : adges[p]) {
        int v = au.first;
        // int index = au.second;
        // tag2[v] = 1;
        if(!tag2[v])
            dfs2(v, p);
    }
}

int dis[N];
bool vis[N];
int tot[N];

inline bool spfa() {
    queue<int> q;
    memset(dis, 0x3f, sizeof(dis));
    // memset(vis, 0, sizeof(vis));
    vis[1] = 1;
    dis[1] = 0;
    q.push(1);
    while(!q.empty()) {
        int p = q.front();
        q.pop();
        vis[p] = 0;
        ++tot[p];
        for(int i = head[p]; i; i = nxt[i]) {
            int v = to[i];
            if(dis[v] > dis[p] + w[i]) {
                dis[v] = dis[p] + w[i];
                if(!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
                if(tot[v] > n)
                    return 0;
            }
        }
    }
    return 1;
}

int main() {

    n = read();
    m = read();

    // memset(head, -1, sizeof(head));

    for(int i = 1; i <= m; ++i) {
        du[i] = read();
        dv[i] = read();
        add_edge1(du[i], dv[i], i);
        add_edge2(dv[i], du[i], i);
    }

    dfs1(1, 0);
    dfs2(n, 0);

    for(int i = 1; i <= m; ++i) {
        if(tag1[du[i]] && tag2[du[i]] && tag1[dv[i]] && tag2[dv[i]]) {
            add_edge(du[i], dv[i], 9);
            add_edge(dv[i], du[i], -1);
        }
    }

    bool flag = spfa();

    if(!flag)
        writeln(-1);
    else if(dis[n] == 0x3f3f3f3f || dis[n] == 0) {
		writeln(-1);
	}
    else {
        write(n), putchar(' '), writeln(m);
        for(int i = 1; i <= m; ++i) {
            write(du[i]), putchar(' '), write(dv[i]), putchar(' ');
            if(!tag1[du[i]] || !tag2[du[i]] || !tag1[dv[i]] || !tag2[dv[i]] ) 
                writeln(1);
            else writeln(abs(dis[dv[i]] - dis[du[i]]));
        }
    }

    return 0;
}