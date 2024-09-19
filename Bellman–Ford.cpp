#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n, m, s;

struct Edge {
    int v;
    int c;
};
vector<Edge> edges[MAXN];
int dis[MAXN];

void bellman_ford() {
    // 初始化
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

    cin >> n >> m >> s;
    
    for(int i = 1; i <= m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        Edge tmp;
        tmp.c = c;
        tmp.v = v;
        edges[u].push_back(tmp);
    }

    bellman_ford();

    for(int i = 1; i <= n; ++i) {
        cout << (dis[i] == 0x3f3f3f3f ? 2147483647 : dis[i]) << ' ';
    }
    cout << endl;
    return 0;
}