#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Grid {
    int score;
    int clearCount;
};

int main() {
    int n;
    cin >> n;
    vector<Grid> grids(n);
    
    // 读取得分
    for (int i = 0; i < n; ++i) {
        cin >> grids[i].score;
    }
    
    // 读取清除数
    for (int i = 0; i < n; ++i) {
        cin >> grids[i].clearCount;
    }
    
    vector<int> dp(n + 1, 0);  // 最大得分数组
    vector<int> last(n + 1, -1);  // 记录路径
    stack<int> chosen;  // 记录选择的格子
    
    int maxScore = 0;
    int endIndex = -1;
    
    for (int i = 0; i < n; ++i) {
        if (!chosen.empty()) {
            dp[i] = dp[chosen.top()] + grids[i].score;
        } else {
            dp[i] = grids[i].score;
        }
        
        // 更新最大得分和终点位置
        if (dp[i] > maxScore) {
            maxScore = dp[i];
            endIndex = i;
        }
        
        // 记录路径
        last[i] = chosen.empty() ? -1 : chosen.top();
        chosen.push(i);
        
        // 清除操作
        int toClear = grids[i].clearCount;
        while (toClear > 0 && !chosen.empty()) {
            chosen.pop();
            --toClear;
        }
    }
    
    // 输出结果
    vector<int> path;
    for (int i = endIndex; i != -1; i = last[i]) {
        path.push_back(i + 1);
    }
    
    reverse(path.begin(), path.end());
    
    cout << path.size() << endl;
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i] << " ";
    }
    cout << endl;
    cout << maxScore << endl;
    
    return 0;
}