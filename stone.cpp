#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

int main() {

    freopen("stone.in", "r", stdin);
    freopen("stone.out", "w", stdout);
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<ull> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<int>> g(n);
    vector<pair<int,int>> e;
    e.reserve(m);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        --u; --v;
        if (u>=0 && u<n && v>=0 && v<n) {
            g[u].push_back(v);
            e.emplace_back(u, v);
        }
    }

    bool c = false;
    if (m == n-1) {
        vector<int> f(n-1, 0);
        for (auto &x : e) {
            int u = x.first, v = x.second;
            if (u >= 0 && u+1 == v && u < n-1) f[u] = 1;
        }
        bool all = true;
        for (int i = 0; i < n-1; ++i) if (!f[i]) { all = false; break; }
        if (all) c = true;
    }

    vector<ll> ans(n, -1);

    if (c) {
        unordered_map<ull,int> cnt;
        cnt.reserve(1024);
        vector<ull> d;
        d.reserve(1024);
        int sz = 0;
        ull mx = 0;
        for (int j = n-1; j >= 0; --j) {
            ull x = a[j];
            if (sz >= 1) {
                ull y = 0;
                for (ull v : d) {
                    if (cnt[v] > 0) {
                        ull z = x & v;
                        if (z > y) y = z;
                        if (y == x) break;
                    }
                }
                if (y > mx) mx = y;
            }
            if (cnt.find(x) == cnt.end() || cnt[x] == 0) {
                d.push_back(x);
            }
            cnt[x] += 1;
            sz += 1;
            if (sz >= 2) ans[j] = (ll)mx;
            else ans[j] = -1;
        }
    } else if (n <= 100 && m <= 300) {
        for (int s = 0; s < n; ++s) {
            vector<char> vis(n, 0);
            queue<int> q;
            q.push(s); vis[s] = 1;
            vector<int> nd;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                nd.push_back(u);
                for (int v : g[u]) if (!vis[v]) {
                    vis[v] = 1; q.push(v);
                }
            }
            if ((int)nd.size() < 2) { ans[s] = -1; continue; }
            ull mx = 0;
            for (size_t i = 0; i < nd.size(); ++i) {
                for (size_t j = i+1; j < nd.size(); ++j) {
                    ull val = a[nd[i]] & a[nd[j]];
                    if (val > mx) mx = val;
                }
            }
            ans[s] = (ll)mx;
        }
    } else {
        for (int s = 0; s < n; ++s) {
            vector<char> vis(n, 0);
            queue<int> q;
            q.push(s); vis[s] = 1;
            vector<int> nd;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                nd.push_back(u);
                for (int v : g[u]) if (!vis[v]) {
                    vis[v] = 1; q.push(v);
                }
            }
            if ((int)nd.size() < 2) { ans[s] = -1; continue; }
            ull mx = 0;
            for (size_t i = 0; i < nd.size(); ++i) {
                for (size_t j = i+1; j < nd.size(); ++j) {
                    ull val = a[nd[i]] & a[nd[j]];
                    if (val > mx) mx = val;
                }
            }
            ans[s] = (ll)mx;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}