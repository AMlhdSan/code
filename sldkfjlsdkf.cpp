#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

// 全局变量
vector<long long> positions, prefixSum, leftMin, rightMax, result;
int stationCount;

// 计算在给定长度限制下的最优分配
void calculateOptimalAllocation(int stationIndex, long long maxLength) {
    // 如果总路径长度不超过限制，直接分配
    if (leftMin[stationCount] + rightMax[stationCount] <= maxLength) {
        result[stationIndex] += rightMax[stationCount];
        result[stationIndex + 1] += leftMin[stationCount];
        return;
    }
    
    // 二分查找最优分割点
    int left = 1, right = stationCount - 1, optimalPoint = stationCount;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (leftMin[mid] + rightMax[mid] > maxLength) {
            optimalPoint = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    // 根据分割点特性分配路径
    if (rightMax[optimalPoint] == rightMax[optimalPoint - 1]) {
        result[stationIndex] += rightMax[optimalPoint];
        result[stationIndex + 1] += maxLength - rightMax[optimalPoint];
    } else {
        result[stationIndex] += maxLength - leftMin[optimalPoint];
        result[stationIndex + 1] += leftMin[optimalPoint];
    }
}

int main() {

    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int totalStations;
    cin >> totalStations >> stationCount;
    
    // 初始化数组大小
    positions.resize(totalStations + 1);
    prefixSum.resize(stationCount + 1);
    leftMin.resize(stationCount + 1);
    rightMax.resize(stationCount + 1);
    result.resize(totalStations + 1);
    
    // 读取站点位置
    for (int i = 1; i <= totalStations; i++) {
        cin >> positions[i];
    }
    
    // 计算前缀和以及左右边界
    for (int i = 1; i <= stationCount; i++) {
        int movement;
        cin >> movement;
        prefixSum[i] = prefixSum[i - 1] + movement;
        leftMin[i] = min(leftMin[i - 1], prefixSum[i]);
        rightMax[i] = max(rightMax[i - 1], prefixSum[i]);
    }
    
    // 将左边界转为绝对值
    for (int i = 1; i <= stationCount; i++) {
        leftMin[i] = abs(leftMin[i]);
    }
    
    // 处理起点和终点
    result[1] += leftMin[stationCount];
    result[totalStations] += rightMax[stationCount];
    
    // 处理中间站点间的最优分配
    for (int i = 1; i < totalStations; i++) {
        long long segmentLength = positions[i + 1] - positions[i];
        calculateOptimalAllocation(i, segmentLength);
    }
    
    // 输出结果
    for (int i = 1; i <= totalStations; i++) {
        cout << result[i] << "\n";
    }
    
    return 0;
}