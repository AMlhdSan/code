// 思路: 冒泡ioa的题解
// 非抄袭
#include <bits/stdc++.h>

#define N 101

using namespace std;

vector<int> edges[N]; 
int n, V;
int t = -1;

void dfs(int p, int pre, int ss) {
    t = max(t, ss);
    for(int v : edges[p]) {
        if(v != pre)
            dfs(v, p, ss + 1);
    }
}

int main() {
    
    cin >> V >> n;

    for (int i = 1; i <= V - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    dfs(0, -1, 1);

    if(n + 1 <= t) {
        cout << n + 1 << endl;
    }
    else {
        cout << min(V, t + (n - t + 1) / 2);
    }

    return 0;
}
