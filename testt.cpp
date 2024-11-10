#include <iostream>
#include <cstdio>
#include <algorithm>

#define N 200005

using namespace std;

int n, k;
int ans[N], diff[N];

struct node {
    int val;
    int index;
} a[N];

inline int read() {
    int w = 0, f = 1;
    char ch = getchar_unlocked();
    while (ch < '0' || ch > '9') {
        if (ch == '-') {
            f = -1;
        }
        ch = getchar_unlocked();
    }
    while (ch >= '0' && ch <= '9') {
        w = (w << 3) + (w << 1) + (ch - '0');
        ch = getchar_unlocked();
    }
    return w * f;
}

bool cmp(node x, node y) {
    return x.val < y.val;
}

int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        a[i].val = read();
        a[i].index = i;
    }

    // 先排序，方便用双指针扫描处理
    sort(a + 1, a + 1 + n, cmp);

    // 使用双指针，找到每个 a[i] 的满足条件的右端点范围
    for (int i = 1, j = 1; i <= n; ++i) {
        // 找到第一个不满足条件的 j，使得 a[j].val > a[i].val + k
        while (j <= n && a[j].val <= a[i].val + k) {
            ++j;
        }
        // 差分数组标记，从 i 到 j-1 的元素满足条件
        diff[i]++;
        if (j <= n) diff[j]--;
    }

    for (int i = 1; i <= n; ++i) {
        ans[a[i].index] = (i == 1 ? 0 : ans[a[i - 1].index]) + diff[i];
    }

    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
    }

    return 0;
}
