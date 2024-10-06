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

    for(int i = 1; i <= l; ++i) {
        for(int j = i + 1; j <= l; ++j) {
            if(a[i] == a[j]) {
                dp[i][j] = min(dp[i + 1][j], min(dp[i][j - 1], dp[i][j]));
            }
            else {
                if(a[i] == a[j - 1]) {
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                }
                if(a[i - 1] == a[j]) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                }
            }
        }
    }

    cout << dp[1][l] << endl;

    return 0;
}