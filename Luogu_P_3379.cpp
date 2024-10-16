#include <bits/stdc++.h>

#define N 500005
#define ll long long
#define M 31

using namespace std;

int n, m, s;
int lg[N];
int xx, yy;
vector<int> edge[N];
int dep[N];
int fa[N][M];

void add_edge(int u, int v) {
    edge[u].push_back(v);
    edge[v].push_back(u);
}

void dfs(int p, int pre) {
    fa[p][0] = pre;
    dep[p] = dep[pre] + 1;
    for(int i = 1; i <= lg[dep[p]]; ++i) {
        fa[p][i] = fa[fa[p][i - 1]][i - 1];
    }
    for(int nxt : edge[p]) {
        if(nxt != pre) {
            dfs(nxt, p);
        }
    }
}

int lca(int u, int v) {
    if(dep[u] < dep[v]) {
        swap(u, v);
    }
    while(dep[u] > dep[v]) {
        u = fa[u][lg[dep[u] - dep[v]] - 1];
    }
    if(u == v) {
        return u;
    }
    for(int llg = lg[dep[u]] - 1; llg >= 0; --llg) {
        if(fa[u][llg] != fa[v][llg]) {
            u = fa[u][llg];
            v = fa[v][llg];
        }
    }

    return fa[u][0];
}

int main() {

    cin >> n >> m >> s;

    for(int i = 1; i <= n - 1; ++i) {
        cin >> xx >> yy;
        add_edge(xx, yy);
    }

    int cntt = 0;

    for(int i = 1; i <= n; ++i) {
        if(i >= (1 << cntt)) {
            ++cntt;
            lg[i] = cntt;
        }
        else {
            lg[i] = cntt;
        }
    }
    
    dfs(s, 0);

    while(m--) {
        cin >> xx >> yy;
        cout << lca(xx, yy) << endl;
    }

    return 0;
}