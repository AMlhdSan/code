#include <bits/stdc++.h>
using namespace std;

int n, ans;
vector<int> adj[6005];
int f[6005][2], is_h[6005], vis[6005];

void addedge(int u, int v) {
    adj[u].push_back(v); 
}

void calc(int k) {
    vis[k] = 1;
    for (int v : adj[k]) { 
        if (vis[v]) 
            continue;
        calc(v);
        f[k][1] += f[v][0];
        f[k][0] += max(f[v][0], f[v][1]); 
    }
    return;
}

int main() {
    cin >> n;

    for(int i = 1; i <= n; i++) 
        cin >> f[i][1];
    for(int i = 1; i < n; i++) {
        int l, k;
        cin >> l >> k;
        is_h[l] = 1; 
        addedge(k, l);
    }
    for (int i = 1; i <= n; i++)
        if (!is_h[i]) { 
            calc(i);
            cout << max(f[i][1], f[i][0]) << endl;
            return 0;
        }
    return 0;
}
