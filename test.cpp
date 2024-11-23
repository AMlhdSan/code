#include <iostream>
#include <vector>
#include <set>
using namespace std;

int solve(int n, int k) {
    vector<set<long long> > prev(k + 1), curr(k + 1);

    // 初始化：dp[0][j] = {1}
    for (int j = 0; j <= k; ++j) {
        prev[j].insert(1);
    }

    // 动态规划
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            curr[j] = curr[j - 1]; // 不选当前数 j-1
            
            if (i >= j - 1) {
                for (long long prod : prev[j]) {
                    curr[j].insert(prod * (j - 1));
                }
            }
        }
        swap(prev, curr); // 滚动更新
    }

    return prev[k].size();
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << solve(n, k) << endl;
    return 0;
}
