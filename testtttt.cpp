#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1005; // 假设 n 最大为 1000
const int MAXK = 25;   // 假设 k 最大为 20

int n, L, R, k;
vector<int> tree[MAXN];
int a[MAXN]; // 点权
int dp[MAXN][MAXN]; // dp[u][x] 表示以 u 为根的子树中选择 x 个红色点的方案数
map<int, int> freq[MAXN]; // freq[u] 表示以 u 为根的子树中每个点权的出现次数

// 合并两个点权多重集
void merge(map<int, int>& a, const map<int, int>& b) {
    for (auto& [key, value] : b) {
        a[key] += value;
    }
}

// 树形 DP
void dfs(int u) {
    dp[u][0] = 1; // 不选任何红色点的方案数为 1
    freq[u][a[u]] = 0; // 初始化子树中点权的频率

    for (int v : tree[u]) {
        dfs(v);

        // 临时数组用于存储当前节点的 DP 转移
        vector<int> temp(n + 1, 0);

        for (int x = 0; x <= n; ++x) { // 当前节点的红色点数
            for (int y = 0; y <= n; ++y) { // 子节点的红色点数
                if (x + y <= n) {
                    temp[x + y] = (temp[x + y] + 1LL * dp[u][x] * dp[v][y] % MOD) % MOD;
                }
            }
        }

        // 更新当前节点的 DP 表
        for (int x = 0; x <= n; ++x) {
            dp[u][x] = temp[x];
        }

        // 合并子树的点权频率
        merge(freq[u], freq[v]);
    }

    // 如果当前节点被选择为红色
    for (int x = n; x >= 1; --x) {
        dp[u][x] = dp[u][x - 1];
    }
    dp[u][0] = 0; // 如果当前节点是红色，则不能有 0 个红色点

    // 更新当前节点的点权频率
    freq[u][a[u]]++;
}

int main() {
    // 输入
    cin >> n >> L >> R >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        tree[p].push_back(i); // 构建树的邻接表
    }

    // 初始化 DP 表
    memset(dp, 0, sizeof(dp));

    // 树形 DP
    dfs(1);

    // 统计答案
    int result = 0;
    for (int x = L; x <= R; ++x) {
        result = (result + dp[1][x]) % MOD;
    }

    cout << result << endl;
    return 0;
}
