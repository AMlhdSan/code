#include <bits/stdc++.h>

#define N 200001

using namespace std;

int n;
vector<int> edges[N];
int w[N];
int tmpu, tmpv;
int maxx;

void add_edges(int u, int v) {
    edges[u].push_back(v);
    edges[v].push_back(u);
}

int main() {

    cin >> n;

    for(int i = 1; i <= n - 1; ++i) {
        cin >> tmpu >> tmpv;
        add_edges(tmpu, tmpv);
    }

    for(int i = 1; i <= n; ++i) {
        cin >> w[i];
    }

    for(int i = 1; i <= n; ++i) {
        
    }

    return 0;
}