#include <bits/stdc++.h>
using namespace std;

int n;

long long dp[21];

int main() {

    cin >> n;

    dp[0] = 1;
    dp[1] = 0;

    for(int i = 2; i <= n; ++i) {
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
    }

    cout << dp[n];

    return 0;
}