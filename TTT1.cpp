#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <limits>

using namespace std;

// 定义一个大数表示无穷大
const double INF = numeric_limits<double>::max();

// 计算两个球的碰撞时间
double collision_time(int x1, int v1, int x2, int v2) {
    if (v1 == v2) return INF; // 两球速度相同，不会碰撞
    double t = (double)(x2 - x1) / (v1 - v2);
    return t > 0 ? t : INF; // 只有 t > 0 时才是有效碰撞
}

// 计算某个移除方案下的最早碰撞时间
double earliest_collision_time(vector<pair<int, int> >& balls, set<int>& removed) {
    double min_time = INF;
    int n = balls.size();
    for (int i = 0; i < n - 1; ++i) {
        if (removed.count(i) || removed.count(i + 1)) continue; // 如果球被移除，跳过
        double t = collision_time(balls[i].first, balls[i].second, balls[i + 1].first, balls[i + 1].second);
        min_time = min(min_time, t);
    }
    return min_time;
}

// 枚举所有移除方案
double solve(int n, int k, vector<pair<int, int> >& balls) {
    double max_time = 0.0;

    // 枚举所有移除方案 (最多移除 k 个球)
    int total = 1 << n; // 总共 2^n 种移除方案
    for (int mask = 0; mask < total; ++mask) {
        set<int> removed;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) removed.insert(i); // 如果第 i 位是 1，表示移除第 i 个球
        }
        if (removed.size() > k) continue; // 超过 k 个球被移除，跳过

        // 计算当前移除方案下的最早碰撞时间
        double t = earliest_collision_time(balls, removed);
        max_time = max(max_time, t); // 更新最大时间
    }

    return max_time;
}

int main() {
    // 输入
    int n, k;
    cin >> n >> k;
    vector<pair<int, int> > balls(n);
    for (int i = 0; i < n; ++i) {
        cin >> balls[i].first >> balls[i].second; // 位置和速度
    }

    // 求解并输出结果
    double result = solve(n, k, balls);
    if(result == INF) {
        printf("Rorever");
    }
    printf("%.3f\n", result);
    return 0;
}
