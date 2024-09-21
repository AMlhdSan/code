#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int f[10001];
int ans = 0;
int cnt = 0;

struct Edge {
    int u, v, c;
};

Edge edges[10001];

bool cmp(Edge a, Edge b) {
    return a.c < b.c;
}

void add_edge(int uu, int vv, int cc, int index) {
    edges[index].c = cc;
    edges[index].u = uu;
    edges[index].v = vv;
}

int find_root(int x) {
    if(f[x] == x)
        return x;
    else
        return f[x] = find_root(f[x]);
}

void merge(int x, int y) {
    f[find_root(x)] = find_root(y);
}



void kruskal() {
    for(int i = 1; i <= m; ++i) {
        int fu = find_root(edges[i].u);
        int fv = find_root(edges[i].v);
        if(fu != fv) {
            merge(fu, fv);
            ans += edges[i].c;
            cnt++;
        }
        if(cnt == n - k) {
            cout << ans << endl;
            return;
        }
    }
    cout << "No Answer" << endl;
}

int main() {
    cin >> n >> m >> k;

    for(int i = 1; i <= n; ++i) 
        f[i] = i;

    for(int i = 1; i <= m; ++i) {
        int uu, vv, cc;
        cin >> uu >> vv >> cc;
        add_edge(uu, vv, cc, i);
    }

    sort(edges + 1, edges + m + 1, cmp);

    kruskal();

    return 0;
}