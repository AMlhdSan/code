#include <iostream>
using namespace std;

int n;
int a[5001];
int dp[5001];
int maxx = 1;

int main() {

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    dp[1] = 1;

    for(int i = 2; i <= n; ++i) {
        dp[i] = 1;
        for(int j = 1; j < i; ++j) {
            if(a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    for(int i = 1; i <= n; ++i) {
        maxx = max(maxx, dp[i]);
    }

    cout << maxx;
    return 0;
}