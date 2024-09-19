#include <bits/stdc++.h>
using namespace std;

int n, m, s;
struct Edge {
    int v, c;
};
vector<Edge> e[100005];

int main() {

    cin >> n >> m >> s;

    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].v = v;
        e[u].c = c;
    }

    return 0;
}