#include <bits/stdc++.h>

#define N 2000
#define minn(x, y, z) min((min(x, y)), z)

using namespace std;

char a[N], b[N];
int la, lb;
int dp[N][N];

int main() {

    cin >> a + 1;
    cin >> b + 1;

    la = strlen(a + 1);
    lb = strlen(b + 1);

    for(int i = 0; i <= la; ++i) {
        dp[i][0] = i;
    }

    for(int i = 0; i <= lb; ++i) {
        dp[0][i] = i;
    }

    int t;

    for(int i = 1; i <= la; ++i) {
        for(int j = 1; j <= lb; ++j) {
            t = 1;
            if(a[i] == b[j])
                t = 0;
            dp[i][j] = minn(dp[i][j - 1] + 1, dp[i - 1][j] + 1, dp[i - 1][j - 1] + t);
        }
    }

    cout << dp[la][lb] << endl;

    return 0;
}