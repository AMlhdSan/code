#include <bits/stdc++.h>

#define N 100001

using namespace std;

int n;
int a[N];
int b[N];
int p[N];
map<int, int> mp;
int dp[N]; // dp[i]表示以i为结尾的最长上升子序列


int main() {

    ios::sync_with_stdio(false);
    
    cin >> n;

    memset(dp, 0x3f, sizeof(dp));

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    for(int i = 1; i <= n; ++i) {
        cin >> b[i];
        p[i] = mp[b[i]];
    }

    for(int i = 1; i <= n; ++i) {
        *lower_bound(dp + 1, dp + n + 1, p[i]) = p[i];
    }

    cout << (lower_bound(dp + 1, dp + n + 1, 0x3f3f3f3f) - dp - 1) << endl;

    return 0;
}