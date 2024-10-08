#include <bits/stdc++.h>
using namespace std;

char a[51];
int l;
int dp[51][51];

int main() {

    cin >> a + 1;
    l = strlen(a + 1);

    memset(dp, 0x3f, sizeof(dp));

    for(int i = 1; i <= l; ++i) {
        dp[i][i] = 1;
    }

    for(int i = l; i >= 0; --i) {
        for(int j = i + 1; j <= l; ++j) {
            if(a[i] == a[j]) {
                dp[i][j] = dp[i][j - 1];
            }
            else {
                dp[i][j] = 0x3f3f3f3f;
                for(int k = i; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }
    }

    cout << dp[1][l] << endl;

    return 0;
}