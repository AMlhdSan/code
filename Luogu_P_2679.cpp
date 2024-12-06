#include <bits/stdc++.h>

#define ll long long
#define MOD 1000000007
#define N 210
#define M 1010

using namespace std;

ll dp[N][N];
ll sum[N][N];
int n, m, t;
char a[M], b[N];

int main() {

    cin >> n >> m >> t >> a >> b;

    dp[0][0] = 1;

    for(int i = 1; i <= n; ++i)
        for(int j = m; j >= 1; --j)
            for(int k = t; k >= 1; --k)
                if(a[i - 1] == b[j - 1]) {
                    sum[j][k] = sum[j - 1][k] + dp[j - 1][k - 1];
                    dp[j][k] += sum[j][k];
                    dp[j][k] %= MOD;
                    sum[j][k] %= MOD;
                }
                else {
                    sum[j][k] = 0;
                }
    cout << dp[m][t];

    return 0;
}