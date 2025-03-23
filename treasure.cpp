#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll INF = 1LL << 60;

// 边结构：保存孩子节点和从父节点到该孩子的行走时间
struct Edge {
    int to, cost;
};

int n, T;
vector<ll> a, b;              // a[i]: i节点宝物数；b[i]:每个宝物挖掘所需时间
vector<vector<Edge>> tree;

// 状态定义：一个状态表示花费 time 时间获得 treasure 个宝物
// 一个节点返回的状态集合表示从该节点出发到返回该节点期间所有可能的选择方案
typedef vector<pair<ll, ll>> State;

/*
 * mergeState：将两个状态集合进行合并，枚举所有方案组合
 * 每个组合的总时间为两部分时间之和，总宝物数为两部分宝物数之和
 * 合并后需要删除被支配的状态（即：存在某方案花更少时间却得到更多宝物时，劣势方案可舍去）
 */
State mergeState(const State &s1, const State &s2) {
    State merged;
    for (auto &p : s1) {
        for (auto &q : s2) {
            ll newTime = p.first + q.first;
            ll newTreasure = p.second + q.second;
            merged.push_back({newTime, newTreasure});
        }
    }
    sort(merged.begin(), merged.end());
    State result;
    ll bestTreasure = -1;
    for (auto &st : merged) {
        if (st.second > bestTreasure) {
            result.push_back(st);
            bestTreasure = st.second;
        }
    }
    return result;
}

/*
 * dfs：深度优先搜索处理每个节点
 * 返回状态集合，表示从当前节点出发经过各种决策能获得的（时间消耗，宝物数量）组合
 */
State dfs(int u) {
    State dp;
    // 方案一：在 u 节点处直接挖宝后原路返回（不进入子树）
    // 枚举在 u 节点挖掘 x 个宝物，耗时 x * b[u]，获得 x 个宝物
    for (int x = 0; x <= a[u]; x++) {
        dp.push_back({(ll)x * b[u], x});
    }
    
    // 遍历 u 的所有子节点
    for (auto &edge : tree[u]) {
        int v = edge.to;
        int travelCost = edge.cost;
        // 递归获得子树 v 的状态集合
        State childState = dfs(v);
        
        // 模拟小 B 的剪枝策略：小 B 会剪掉对小 A 最有利的一支，
        // 这里简单以一个惩罚值 penalty 表示，实际问题中可能需要根据 v 的具体情况计算
        ll penalty = 0; // TODO: 根据实际情况调整惩罚策略
        for (auto &st : childState) {
            st.second = max(0LL, st.second - penalty);
        }
        
        // 从 u 进入子树 v 需要先支付行走时间 travelCost，
        // 然后利用子树 v 内的方案得到返回 u 的收益
        State option = mergeState({{travelCost, 0}}, childState);
        
        // 将当前节点 u 的状态与进入 v 的方案进行合并
        dp = mergeState(dp, option);
        
        // 压缩 dp 状态，删除劣势方案（时间更长但宝物更少）
        sort(dp.begin(), dp.end());
        State newDP;
        ll best = -1;
        for (auto &st : dp) {
            if (st.second > best) {
                newDP.push_back(st);
                best = st.second;
            }
        }
        dp = newDP;
    }
    return dp;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> T;
    a.resize(n + 1);
    b.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    
    tree.resize(n + 1);
    for (int i = 2; i <= n; i++){
        int parent, cost;
        cin >> parent >> cost;
        tree[parent].push_back({i, cost});
    }
    
    // 从根节点开始 DFS 得到所有可能状态
    State res = dfs(1);
    ll answer = 0;
    // 在所有方案中选出耗时不超过 T 的最大宝物数
    for (auto &st : res) {
        if (st.first <= T)
            answer = max(answer, st.second);
    }
    cout << answer << "\n";
    return 0;
}
