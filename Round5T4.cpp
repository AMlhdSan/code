#include <bits/stdc++.h>

#define N 100100

using namespace std;

int n, k, s;
int c[N], l[N];
int a[N], b[N];

struct Edge {
    int v;
    int c;
};
vector<Edge> edges[MAXN];
int dis[MAXN];

inline int read() {
    int w = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        w = (w << 3) + (w << 1) + (ch - '0');
        ch = getchar();
    }
    return w * f;
}

void bellman_ford() {
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;

    bool flag;

    for(int i = 1; i <= n - 1; ++i) {
        flag = false;
        for(int u = 1; u <= n; ++u) {
            for(Edge e : edges[u]) {
                if(dis[e.v] > dis[u] + e.c) {
                    dis[e.v] = dis[u] + e.c;
                    flag = true;
                }
            }
        }
        if(!flag)
            break;
    }
}

int main() {

    cin >> n >> k;

    for(int i = 1; i <= n; ++i) {
        c[i] = read();
        l[i] = read();
        
        a[i] = c[i] % k;
        b[i] = ((c[i] + l[i] - 1) % k + 1) % k;
        edges[a[i]].push_back(b[i]);
        edges[b[i]].push_back(a[i]);

        Edge tmp;
        tmp.c = -1;
        tmp.v = b[i];
        edges[a[i]].push_back(tmp);

        tmp.c = -1;
        tmp.v = a[i];
        edges[c[i]].push_back(tmp);
    }

    bellman_ford();

    return 0;
}