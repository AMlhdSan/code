#include <bits/stdc++.h>

#define N 1010

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

int n, m, q, u, v, w, s, t;
int rk[N], dist[N][N], dis[N][N];

struct node {
    int d;
    int id;
} nm[N];

bool cmp(node a, node b) {
    if (a.d == b.d)
        return a.id < b.id;
    return a.d < b.d;
}

int main() {
    n = read(); m = read(); q = read();
    
    for (int i = 1; i <= n; i++) {
        nm[i].d = read();
        nm[i].id = i;
    }
    sort(nm + 1, nm + 1 + n, cmp);
    
    for (int i = 1; i <= n; i++)
        rk[nm[i].id] = i;
    
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; i++)
        dis[i][i] = 0;
    
    for (int i = 1; i <= m; i++) {
        u = read(); v = read(); w = read();
        dis[rk[u]][rk[v]] = dis[rk[v]][rk[u]] = min(dis[rk[u]][rk[v]], w);
    }
    
    memset(dist, 0x3f, sizeof(dist));
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                dist[i][j] = min(dist[i][j], dis[i][j] + max(nm[k].d, max(nm[i].d, nm[j].d)));
            }
    
    while (q--) {
        s = read(); t = read();
        writeln(dist[rk[s]][rk[t]]);
    }
    
    return 0;
}