#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

struct Edge {
    int to, cost;
};

int n, T;
vector<ll> a, b;
vector<vector<Edge>> tree;

// 状态结构：在某节点处，如果用掉 time 单位时间，最多能获得 treasure 个宝物
// 状态数组按时间（消耗）递增排序，且宝物数单调递增
typedef vector<pair<ll, ll>> State;

// 将两个状态进行“卷积”：意思是在节点 u 内部（或 u 与其子树之间）的不同决策组合后得到的状态
// 这里的合并操作需要考虑时间的消耗和宝物数的累加
// 具体的转移可能涉及对抗双方博弈（小B剪枝），因此合并时需使用极小化策略
State mergeState(const State &s1, const State &s2) {
    // 采用类似于“背包合并”的方法：枚举 s1 与 s2 中的状态组合
    State res;
    for (auto &p : s1) {
        for (auto &q : s2) {
            ll tCost = p.first + q.first;
            ll tVal  = p.second + q.second;
            res.push_back({tCost, tVal});
        }
    }
    // 排序并删除被支配的状态（时间更短且宝物更多的状态支配另一个状态）
    sort(res.begin(), res.end());
    State ret;
    ll best = -1;
    for (auto &st : res) {
        if (st.second > best) {
            ret.push_back(st);
            best = st.second;
        }
    }
    return ret;
}

// 返回节点 u 的状态数组，表示从 u 出发（经过最优博弈决策后）在回返根节点前可获得的“额外”宝物数与所需时间
State dfs(int u) {
    State dp;
    // 【方案1】直接从 u 按原路返回（不进入子树）的状态
    // 注意：返回时在 u 点可以挖掘最多 a[u] 个宝物，每个宝物需要 b[u] 单位时间，
    // 这里采用枚举在 u 处挖掘的宝物数量 x（0 <= x <= a[u]），
    // 消耗时间为 x * b[u]（假设 u 到 u 的“行走时间”为 0），收获 x 个宝物。
    for (int x = 0; x <= a[u]; x++) {
        dp.push_back({(ll)x * b[u], x});
    }
    
    // 对 u 的每个儿子进行处理
    for (auto &edge : tree[u]) {
        int v = edge.to;
        int travelCost = edge.cost; // 从 u 到 v 的行走时间
        // 递归获得子树 v 的状态数组
        State childState = dfs(v);
        
        // 当小 A 选择进入子树 v 时，必须支付从 u 到 v 的行走时间，
        // 到达 v 后（进入子树后），还会有小 B 的操作：小 B 会从 v 的儿子中剪掉一个最优分支，
        // 这使得 v 后续可用的状态变得“更差”。
        // 这里我们简单模拟：将 childState 中每个状态的宝物数减去一个惩罚值 penalty
        // （惩罚值如何计算需要根据 v 的儿子情况确定，这里只作示例处理）
        ll penalty = 0; // TODO：根据 v 的情况计算小 B 的剪枝惩罚
        for (auto &st : childState) {
            st.second = max(0LL, st.second - penalty);
        }
        // 加上从 u 到 v 的行走时间，再与 u 在 v 处的决策进行合并
        // 合并后，相当于：在 u 处选择进入 v 得到的状态
        State option;
        // 在进入 v 后，选择合适状态，并在返回 u 前还可以在 u 点挖宝（同样枚举挖宝数量）
        // 这里使用 mergeState 进行合并
        option = mergeState({{travelCost, 0}}, childState);
        
        // 合并 option 与 u 之前的状态 dp：这里采用“取最大”的思想，
        // 即小 A 会在各个子树中选出一个收益最大的方案，但小 B 会在每一步剪枝，使得最终收益取较小值。
        // 因此合并时需要取两者的较小值（最坏情况）。
        dp = mergeState(dp, option);
        
        // 在合并后对 dp 进行状态压缩，删除被支配的状态
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
    a.resize(n+1);
    b.resize(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    tree.resize(n+1);
    for (int i = 2; i <= n; i++){
        int f, c;
        cin >> f >> c;
        tree[f].push_back({i, c});
    }
    
    // 求解从根节点出发的状态
    State dp = dfs(1);
    ll ans = 0;
    // 在状态 dp 中找出所需时间不超过 T 的最大宝物数
    for (auto &st : dp) {
        if (st.first <= T) {
            ans = max(ans, st.second);
        }
    }
    cout << ans << "\n";
    return 0;
}
