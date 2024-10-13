#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 200005;

int n, m, k, q;
vector<int> adj[MAXN];
int indeg[MAXN];   // 记录每个节点的入度
bool has_theater[MAXN];  // 记录每个候场室是否还有剧团
vector<int> topo_order;  // 拓扑排序的顺序
int command[MAXN];  // 记录命令序列

// 拓扑排序
void topo_sort() {
    queue<int> q;
    
    for (int i = 1; i <= n; ++i) {
        if (indeg[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo_order.push_back(u);
        for (int v : adj[u]) {
            indeg[v]--;
            if (indeg[v] == 0) {
                q.push(v);
            }
        }
    }
}

// 模拟执行命令
int simulate(int l, int r) {
    // 初始化，每个候场室都有剧团
    memset(has_theater, true, sizeof(has_theater));
    int remaining_theaters = n - 1;

    // 依次处理命令
    for (int i = l; i <= r; ++i) {
        int u = command[i];
        if (!has_theater[u]) continue; // 如果这个剧团已经出场，跳过

        bool can_perform = true;
        for (int v : adj[u]) {
            if (has_theater[v]) {
                can_perform = false;
                break;
            }
        }

        if (can_perform) {
            has_theater[u] = false; // 剧团出场
            remaining_theaters--;
        }
    }

    return remaining_theaters;
}

int main() {
    int c;
    cin >> c;
    cin >> n >> m >> k >> q;

    // 构建图
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }

    // 读入命令序列
    for (int i = 1; i <= k; ++i) {
        cin >> command[i];
    }

    // 拓扑排序
    topo_sort();

    // 处理每次查询
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        cout << simulate(l, r) << endl;
    }

    return 0;
}
