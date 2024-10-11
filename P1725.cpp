#include <bits/stdc++.h>

#define N 200001

using namespace std;

int n, l, r;
int a[N];
int dp[N]; // dp[i]表示到第i格所能获得的最大冰冻指数

int main() {

    cin >> n >> l >> r;

    for(int i = 0; i <= n; ++i) {
        cin >> a[i];
    }

    dp[0] = a[0];

    for(int i = 1; i <= n; ++i) {
        if(i - l < 0) {
            continue;
        }
        else if(i - r < 0) {
            // [0, i - l]
            for(int j = 0; j <= i - l; ++j) {
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
        else {
            for(int j = i - r; j <= i - l; ++j) {
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
    }

    int maxx = -0x7fffffff;

    for(int i = n - r; i <= n; ++i) {
        maxx = max(maxx, dp[i]);
    }

    cout << maxx << endl;


    return 0;
}