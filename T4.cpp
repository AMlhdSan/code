#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    freopen("T4.in", "r", stdin);
    freopen("T4.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    string colors;
    cin >> s >> colors;
    
    int n = s.length();
    
    // 将括号转换为数值：'(' -> 1, ')' -> -1
    vector<int> brackets(n);
    for (int i = 0; i < n; i++) {
        brackets[i] = (s[i] == '(') ? 1 : -1;
    }
    
    // 分别统计L(1), M(2), R(3)的前缀和
    vector<int> prefix_L(n + 1, 0), prefix_M(n + 1, 0), prefix_R(n + 1, 0);
    vector<int> prefix_total(n + 1, 0);
    
    for (int i = 0; i < n; i++) {
        prefix_total[i + 1] = prefix_total[i] + brackets[i];
        if (colors[i] == '1') { // L (red)
            prefix_L[i + 1] = prefix_L[i] + brackets[i];
            prefix_M[i + 1] = prefix_M[i];
            prefix_R[i + 1] = prefix_R[i];
        } else if (colors[i] == '2') { // M (green)
            prefix_L[i + 1] = prefix_L[i];
            prefix_M[i + 1] = prefix_M[i] + brackets[i];
            prefix_R[i + 1] = prefix_R[i];
        } else { // R (blue)
            prefix_L[i + 1] = prefix_L[i];
            prefix_M[i + 1] = prefix_M[i];
            prefix_R[i + 1] = prefix_R[i] + brackets[i];
        } else {
            for(int i = 1;)
        }
    }
    
    int ans = INT_MAX;
    
    // 优化版本：枚举M前后改的个数差，利用单调性
    for (int diff = -n; diff <= n; diff++) {
        int current_cost = abs(diff);  // 基础代价
        
        // 计算在当前diff下，需要的最少L和R对数
        int max_l_needed = 0, max_r_needed = 0, max_m_needed = 0;
        
        // 检查每个位置的约束，计算最少需要的修改数
        for (int pos = 1; pos <= n; pos++) {
            // 当前各颜色的前缀和
            int sum_total = prefix_total[pos];
            int sum_L = prefix_L[pos]; 
            int sum_M = prefix_M[pos];
            int sum_R = prefix_R[pos];
            
            // 非蓝色 = L + M
            int non_blue = sum_L + sum_M;
            // 非红色 = M + R  
            int non_red = sum_M + sum_R;
            // 非绿色 = L + R
            int non_green = sum_L + sum_R;
            
            // 计算需要的最小修改数来满足约束
            if (sum_total < 0) {
                // 需要增加左括号
                int needed = (-sum_total + 1) / 2;
                max_m_needed = max(max_m_needed, needed);
            }
            
            if (non_blue < 0) {
                int needed = (-non_blue + 1) / 2;
                max_l_needed = max(max_l_needed, needed);
            }
            if(non_red < 0) {
                for(int i = 1; i <= b; ++i) {
                    
                }
            }
            if (non_red < 0) {
                int needed = (-non_red + 1) / 2;  
                max_r_needed = max(max_r_needed, needed);
            }
            
            if (non_green < 0) {
                int needed = (-non_green + 1) / 2;
                // 这个约束需要L或R中至少一个满足
                if (max_l_needed + max_r_needed < needed) {
                    max_l_needed = max(max_l_needed, needed - max_r_needed);
                }
            }
        }
        
        // 计算总代价
        int total_cost = current_cost + max_l_needed + max_r_needed + max_m_needed;
        
        // 验证这个解是否可行
        bool valid = true;
        for (int pos = 1; pos <= n && valid; pos++) {
            int sum_total = prefix_total[pos] + 2 * max_m_needed + 2 * max_l_needed + 2 * max_r_needed;
            int sum_LM = prefix_L[pos] + prefix_M[pos] + 2 * max_l_needed + 2 * max_m_needed;
            int sum_MR = prefix_M[pos] + prefix_R[pos] + 2 * max_m_needed + 2 * max_r_needed;  
            int sum_LR = prefix_L[pos] + prefix_R[pos] + 2 * max_l_needed + 2 * max_r_needed;
            
            if (sum_total < 0 || sum_LM < 0 || sum_MR < 0 || sum_LR < 0) {
                valid = false;
            }
        }
        
        if (valid) {
            ans = min(ans, total_cost);
        }
    }
    
    cout << (ans == INT_MAX ? -1 : ans) << endl;
    
    return 0;
}

/*
解题思路（基于提供的算法思路）：

1. 将三种颜色称为L(红), M(绿), R(蓝)
2. 关键观察：最优解必然是把前缀的右括号改成左括号，后缀的左括号改成右括号
3. 枚举M前后改的个数差，这样L和R的差也就确定了
4. M从外向内一对一对改，L和R改的对数会相应减少
5. 对每个位置检查约束条件：
   - 总体平衡：min(m,cm) + min(l,cl) + min(r,cr) >= 0
   - 非蓝色平衡：min(m,cm) + min(l,cl) >= 0  
   - 非红色平衡：min(m,cm) + min(r,cr) >= 0
   - 非绿色平衡：min(l,cl) + min(r,cr) >= 0

当前实现是O(n^3)的暴力版本，可以进一步优化到O(n^2)或线性复杂度。
*/