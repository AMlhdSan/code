#include <bits/stdc++.h>

#define N 20010

using namespace std;

int l[N], r[N];
int n;
int dp[N][2];

int main() {

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> l[i] >> r[i];
    }

    dp[1][0] = r[1] + r[1] - l[1] - 1;
    dp[1][1] = r[1] - 1;
    for(int i = 2; i <= n; ++i) {
        dp[i][0] = min(dp[i - 1][0] + abs(l[i - 1] - r[i]) + r[i] - l[i] + 1, dp[i - 1][1] + abs(r[i - 1] - r[i]) + r[i] - l[i] + 1);
        dp[i][1] = min(dp[i - 1][0] + abs(l[i - 1] - l[i]) + r[i] - l[i] + 1, dp[i - 1][1] + abs(r[i - 1] - l[i]) + r[i] - l[i] + 1);
    }
       
    cout << min(dp[n][0] + n - l[n], dp[n][1] + n - r[n]) << endl;

    return 0;
}