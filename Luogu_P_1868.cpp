#include <bits/stdc++.h>

#define N 150001
#define mid ((l + r) >> 1)

using namespace std;

int n;
int dp[N]; // dp[i] 表示以 a[i] 的右端点作为结尾的最大草坪数

struct node {
    int x, y;
}a[N];

bool cmp(node x, node y) {
    return x.y < y.y;
}

int main() {

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i].x >> a[i].y;
    }

    sort(a + 1, a + n + 1, cmp);

    for(int i = 1; i <= n; ++i) {
        int p = 0, l = 1, r = i - 1;
        while(l <= r) {
            if(a[mid].y < a[i].x) {
                p = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        dp[i] = max(dp[i - 1], dp[p] + a[i].y - a[i].x + 1);
    }

    cout << dp[n] << endl;

    return 0;
}