#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<ull> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<int>> g(n);
    vector<pair<int,int>> edges;
    edges.reserve(m);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        --u; --v;
        if (u>=0 && u<n && v>=0 && v<n) {
            g[u].push_back(v);
            edges.emplace_back(u, v);
        }
    }

    // 检测是否为链：m == n-1 且对于所有 i in [0..n-2] 存在边 i->i+1
    bool is_chain = false;
    if (m == n-1) {
        vector<int> need(n-1, 0);
        for (auto &e : edges) {
            int u = e.first, v = e.second;
            if (u >= 0 && u+1 == v && u < n-1) need[u] = 1;
        }
        bool all = true;
        for (int i = 0; i < n-1; ++i) if (!need[i]) { all = false; break; }
        if (all) is_chain = true;
    }

    vector<long long> ans(n, -1);

    if (is_chain) {
        // 子任务3：链（从 i 可达的就是后缀 i..n-1）
        // 从右往左维护 S = {a[j+1..n-1]}，插入时计算与已有元素的最大 & 值
        unordered_map<ull,int> cnt;
        cnt.reserve(1024);
        vector<ull> distinct_vals;
        distinct_vals.reserve(1024);
        int suffix_size = 0;
        ull current_best = 0; // 当前后缀（已插入部分）里任意两点 AND 的最大值（当后缀大小<2时无意义）
        // we will insert elements from right to left; at step j, S holds elements from j+1..n-1
        for (int j = n-1; j >= 0; --j) {
            ull x = a[j];
            if (suffix_size >= 1) {
                ull best_with_x = 0;
                // 遍历去重值集合（启发式加速）
                for (ull v : distinct_vals) {
                    if (cnt[v] > 0) {
                        ull cand = x & v;
                        if (cand > best_with_x) best_with_x = cand;
                        // 小优化：若 best_with_x already equals x, can't get bigger -> break
                        if (best_with_x == x) break;
                    }
                }
                if (best_with_x > current_best) current_best = best_with_x;
            }
            // 插入 x 到 S
            if (cnt.find(x) == cnt.end() || cnt[x] == 0) {
                distinct_vals.push_back(x);
            }
            cnt[x] += 1;
            suffix_size += 1;
            if (suffix_size >= 2) ans[j] = (long long)current_best;
            else ans[j] = -1;
        }
    } else if (n <= 100 && m <= 300) {
        // 子任务1：暴力解。对每个起点 BFS 找到可达集合，然后两两枚举最大 AND
        for (int s = 0; s < n; ++s) {
            vector<char> vis(n, 0);
            queue<int> q;
            q.push(s); vis[s] = 1;
            vector<int> nodes;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                nodes.push_back(u);
                for (int v : g[u]) if (!vis[v]) {
                    vis[v] = 1; q.push(v);
                }
            }
            if ((int)nodes.size() < 2) { ans[s] = -1; continue; }
            ull best = 0;
            for (size_t i = 0; i < nodes.size(); ++i) {
                for (size_t j = i+1; j < nodes.size(); ++j) {
                    ull val = a[nodes[i]] & a[nodes[j]];
                    if (val > best) best = val;
                }
            }
            ans[s] = (long long)best;
        }
    } else {
        // 既不是链也不属于小规模暴力子任务 — 仍然提供暴力实现（可能超时）
        // 我们尽量在当前代码里做 BFS + 对可达集合两两枚举（风险自负）
        for (int s = 0; s < n; ++s) {
            vector<char> vis(n, 0);
            queue<int> q;
            q.push(s); vis[s] = 1;
            vector<int> nodes;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                nodes.push_back(u);
                for (int v : g[u]) if (!vis[v]) {
                    vis[v] = 1; q.push(v);
                }
            }
            if ((int)nodes.size() < 2) { ans[s] = -1; continue; }
            ull best = 0;
            for (size_t i = 0; i < nodes.size(); ++i) {
                for (size_t j = i+1; j < nodes.size(); ++j) {
                    ull val = a[nodes[i]] & a[nodes[j]];
                    if (val > best) best = val;
                }
            }
            ans[s] = (long long)best;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}
