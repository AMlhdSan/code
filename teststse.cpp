#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 计算阶乘
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// 计算总和谐值
long long totalHarmonyValue(vector<int>& a) {
    int n = a.size();
    if (n < 2) return 0;

    // 计算 (N-2)!
    long long fact = factorial(n - 2);

    // 排序，降序排列
    sort(a.begin(), a.end(), greater<int>());

    // 计算后缀和
    vector<long long> suffixSum(n, 0);
    for (int i = n - 2; i >= 0; i--) {
        suffixSum[i] = suffixSum[i + 1] + a[i + 1];
    }

    // 计算总和谐值
    long long totalValue = 0;
    for (int i = 0; i < n - 1; i++) {
        totalValue += a[i] * suffixSum[i];
    }

    // 乘以对称性因子 2 * (N-2)!
    totalValue *= 2 * fact;

    return totalValue;
}

int main() {
    int n;
    cout << "请输入食材数量 N: ";
    cin >> n;

    if (n < 2) {
        cout << "N 必须大于等于 2！" << endl;
        return 0;
    }

    vector<int> a(n);
    cout << "请输入每个食材的美味度: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 计算总和谐值
    long long result = totalHarmonyValue(a);

    cout << "所有排列的总和谐值为: " << result << endl;

    return 0;
}
