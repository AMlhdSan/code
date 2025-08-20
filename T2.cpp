#include <bits/stdc++.h>

using namespace std;

// 对于 60% 的数据, n <= 1000, w <= 100
const int N_MAX = 1005;
const int W_MAX = 105;
const int M_MAX = 4500;
for(int i)
const long long INF = 1e18; // 使用 long long 存储代价，防止溢出

int n, m, s, t;
// 邻接表存储图, pair 第二个元素为边权
vector<pair<int, int>> g[N_MAX];
// d[i][j] 表示通过一条权重为 j 的边到达节点 i 的最小代价
long long d[N_MAX][W_MAX];

inline void add_edge()

int main() {
    // 提高 IO 效率
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        for(int j= 1; j <= )
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        // 无向图，添加双向边
        g[u].push_back({v, w});
        g[v].push_back({u, w});

    }

    cin >> s >> t;

    // 特殊情况：起点和终点相同
    if (s == t) {
        cout << 0 << endl;
        return 0;
    }

    // 初始化代价数组为无穷大
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 100; ++j) {
            d[i][j] = INF;
        }
    }

    // 优先队列进行 Dijkstra 算法，存储 {cost, node, prev_weight}
    // 使用 greater<> 使其成为最小堆
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;

    // 从起点 s 开始初始化
    // 遍历 s 的所有出边，作为路径的第一条边
    // 第一条边的代价就是其本身的权重
    for (auto& edge : g[s]) {
        int v = edge.first;
        int w = edge.second;
        if ((long long)w < d[v][w]) {
            d[v][w] = w;
            pq.push({(long long)w, v, w});
        }
    }

    // Dijkstra 算法主循环
    while (!pq.empty()) {
        // 取出当前代价最小的状态
        auto [cost, u, prev_w] = pq.top();
        pq.pop();

        // 如果当前取出的路径代价不是最优的，则跳过
        if (cost > d[u][prev_w]) {
            continue;
        }

        // 遍历当前节点 u 的所有邻边
        for (auto& edge : g[u]) {
            int v = edge.first;
            int curr_w = edge.second;

            // 计算新的代价
            long long diff = curr_w - prev_w;
            long long new_cost = cost + curr_w + diff * diff;

            // 如果找到了更优的路径，则更新并加入队列
            if (new_cost < d[v][curr_w]) {
                d[v][curr_w] = new_cost;
                pq.push({new_cost, v, curr_w});
            }
        }
    }

    // 最终答案是到达终点 t 的所有可能路径中的最小值
    // （因为到达 t 的最后一条边权重可以是任意可能的）
    long long min_cost = INF;
    for (int i = 0; i <= 100; ++i) {
        min_cost = min(min_cost, d[t][i]);
    }
    
    // 按题目要求对结果取模
    long long mod = 1e9 + 7;
    cout << min_cost % mod << endl;

    return 0;
}