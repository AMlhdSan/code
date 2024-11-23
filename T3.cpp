#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int parent[MAXN], color[MAXN];
vector<pair<int, int> > edges;


int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}
void unite(int x, int y) {
    int rx = find(x), ry = find(y);
    if (rx != ry) parent[rx] = ry;
}

// 计算当前割边方案的权值
int calcValue(vector<bool>& cut, int n) {
    for (int i = 1; i <= n; i++) parent[i] = i;

    for (int i = 0; i < edges.size(); i++) {
        if (!cut[i]) {
            unite(edges[i].first, edges[i].second);
        }
    }


    unordered_map<int, unordered_set<int>> blocks;
    for (int i = 1; i <= n; i++) {
        blocks[find(i)].insert(color[i]);
    }


    int value = 0;
    for(auto& block : blocks) {
        if (block.second.size() == 1) value++;
    }
    return value;
}

int main() {
    int t;
    cin >> t; // 测试组数

    while (t--) {
        int n;
        cin >> n;

        // 读取颜色
        for (int i = 1; i <= n; i++) {
            cin >> color[i];
        }

        // 读取边
        edges.clear();
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        int maxValue = 0;
        int m = edges.size();
        for (int mask = 0; mask < (1 << m); mask++) {
            vector<bool> cut(m);
            for (int i = 0; i < m; i++) {
                cut[i] = (mask >> i) & 1;
            }
            maxValue = max(maxValue, calcValue(cut, n));
        }

        cout << maxValue << endl;
    }

    return 0;
}
