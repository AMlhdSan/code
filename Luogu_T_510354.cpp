#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e12;

vector<vector<int> > tree;
vector<long long> a;  // 水杯温度

bool dfs(int node) {
    long long sum = a[node];
    for (int child : tree[node]) {
        if (!dfs(child)) {
            return false;
        }
        sum += a[child];  // 合并子树的温度影响
    }
    if (sum < 0 || (node == 0 && sum != 0)) {
        return false;
    }
    return true;
}

int main() {
    int c;
    cin >> c;  // 测试点编号
    int t;
    cin >> t;  // 测试数据组数
    
    while (t--) {
        int n;
        cin >> n;
        tree.assign(n, vector<int>());
        a.assign(n, 0);
        
        // 构建树的父子关系
        for (int i = 1; i < n; i++) {
            int parent;
            cin >> parent;
            parent--;
            tree[parent].push_back(i);
        }
        
        // 输入初始水杯温度
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // 进行DFS判断
        if (dfs(0)) {
            cout << "Huoyu" << endl;
        } else {
            cout << "Shuiniao" << endl;
        }
    }
    
    return 0;
}
