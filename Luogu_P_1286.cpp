#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 11;
const int MAXM = MAXN * (MAXN - 1) / 2 + 1;
const int MAXA = 100001;

int n, m;
int sums[MAXM];      // 存储所有的和
int result[MAXN];    // 存储结果数组
bool used[MAXM];     // 标记哪些和已经被使用
bool num_used[MAXA]; // 标记哪些数字已经被使用（避免重复）
bool found_solution; // 是否找到解

void dfs(int pos, int depth, int nums[MAXN], bool sum_used[MAXM]) {
    if (found_solution) return; // 已经找到解就直接返回
    
    // 复制当前状态
    bool temp_sum_used[MAXM];
    memcpy(temp_sum_used, sum_used, sizeof(bool) * MAXM);
    int temp_nums[MAXN];
    memcpy(temp_nums, nums, sizeof(int) * MAXN);
    
    temp_sum_used[pos] = true; // 标记当前和已使用
    
    if (depth == 3) {
        // 当找到前三个数时，通过方程组求解
        // s1 = a[1] + a[2], s2 = a[1] + a[3], sp = a[2] + a[3]
        double total = (sums[1] + sums[2] + sums[pos]) / 2.0;
        if (total != (int)total) return; // 剪枝：如果不是整数则无解
        
        int s = (int)total;
        temp_nums[1] = s - sums[pos];  // a[1] = (s1 + s2 - sp) / 2
        temp_nums[2] = s - sums[2];    // a[2] = (s1 + sp - s2) / 2  
        temp_nums[3] = s - sums[1];    // a[3] = (s2 + sp - s1) / 2
        
        // 检查解的有效性
        if (temp_nums[1] < 0 || temp_nums[2] < 0 || temp_nums[3] < 0) return;
        if (temp_nums[1] > temp_nums[2] || temp_nums[2] > temp_nums[3]) return;
    }
    
    if (depth > 3) {
        // 对于第k个数，ak = (某个和) - a1
        temp_nums[depth] = sums[pos] - temp_nums[1];
        
        // 剪枝：检查是否重复使用数字
        if (num_used[temp_nums[depth]]) return;
        num_used[temp_nums[depth]] = true;
        
        // 剪枝：检查是否保持非递减序列
        if (temp_nums[depth] < temp_nums[depth - 1]) {
            num_used[temp_nums[depth]] = false;
            return;
        }
        
        // 剪枝：验证ak与前面所有数的和都存在
        for (int i = 2; i < depth; i++) {
            int required_sum = temp_nums[depth] + temp_nums[i];
            if (!binary_search(sums + 1, sums + m + 1, required_sum)) {
                num_used[temp_nums[depth]] = false;
                return;
            }
        }
    }
    
    // 如果已经找到n个数
    if (depth == n) {
        memcpy(result, temp_nums, sizeof(int) * MAXN);
        found_solution = true;
        return;
    }
    
    // 继续搜索下一个数
    for (int i = 3; i <= m; i++) {
        if (!temp_sum_used[i]) {
            dfs(i, depth + 1, temp_nums, temp_sum_used);
        }
    }
    
    // 回溯
    if (depth > 3) {
        num_used[temp_nums[depth]] = false;
    }
}

void solve_once() {
    m = n * (n - 1) / 2;
    found_solution = false;
    memset(result, 0, sizeof(result));
    memset(num_used, false, sizeof(num_used));
    
    // 读入所有的和
    int total_sum = 0;
    for (int i = 1; i <= m; i++) {
        scanf("%d", &sums[i]);
        total_sum += sums[i];
    }
    
    // 剪枝：检查总和的奇偶性
    // 所有和的总和 = (n-1) * (a1 + a2 + ... + an)
    if (total_sum % (n - 1) != 0) {
        printf("Impossible\n");
        return;
    }
    
    // 对和进行排序
    sort(sums + 1, sums + m + 1);
    
    // 初始化搜索状态
    bool initial_used[MAXM];
    memset(initial_used, false, sizeof(initial_used));
    initial_used[1] = initial_used[2] = true; // 前两个和肯定会被使用
    
    int initial_nums[MAXN];
    memset(initial_nums, 0, sizeof(initial_nums));
    
    // 从第3个和开始尝试作为a[2] + a[3]
    dfs(2, 2, initial_nums, initial_used);
    
    if (!found_solution) {
        printf("Impossible\n");
        return;
    }
    
    // 输出结果（已经是排序的）
    for (int i = 1; i <= n; i++) {
        printf("%d", result[i]);
        if (i < n) printf(" ");
    }
    printf("\n");
}

int main() {
    while (scanf("%d", &n) == 1) {
        solve_once();
    }
    return 0;
}