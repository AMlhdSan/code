#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 5;

vector<int> graph[MAXN]; // 邻接表
int in_degree[MAXN];     // 入度数组
bool added[MAXN][MAXN];  // 检查是否已添加边

vector<int> topological_sort(int n) {
    priority_queue<int, vector<int>, greater<int>> pq; // 小根堆
    vector<int> result;

    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty()) {
        int node = pq.top();
        pq.pop();
        result.push_back(node);

        for (int neighbor : graph[node]) {
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0) {
                pq.push(neighbor);
            }
        }
    }
    return result;
}

bool can_add_edge(int u, int v, int n) {
    // 检查是否可以添加边u -> v
    vector<int> temp_in_degree = in_degree;
    temp_in_degree[v]++;
    
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (temp_in_degree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;
        for (int neighbor : graph[node]) {
            temp_in_degree[neighbor]--;
            if (temp_in_degree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    return count == n; // 如果可以完成拓扑排序，说明没有形成环
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    // 读取边
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        in_degree[v]++;
    }

    // 贪心添加边
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            if (u != v && !added[u][v] && can_add_edge(u, v, n)) {
                graph[u].push_back(v);
                in_degree[v]++;
                added[u][v] = true;
                k--;
                if (k == 0) break;
            }
        }
        if (k == 0) break;
    }

    // 计算最终拓扑序
    vector<int> result = topological_sort(n);

    // 输出结果
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}