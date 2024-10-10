#include <bits/stdc++.h>

#define MOD 998244353
#define N 1001
#define M 20001

using namespace std;

int dp[N][N]; // 以 j 为结尾的，i 为前继的最长等差数列长度
int n;
int h[N];
vector<int> t[M];

long long calc(int p) {
    
}

int main() {

    memset(dp, 0, sizeof(dp));

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> h[i];
        t[h[i]].push_back(i);
    }

    for(int i = 1; i <= n; ++i) {
        dp[i][i] = 1;
    }

    for(int j = 2; j <= n; ++j) {
        for(int i = 1; i <= j; ++i) {
            int d = h[j] - h[i];
            for(int p : t[h[i] - d]) {
                dp[i][j] += dp[p][i];
            }
        }
    }

    long long ans = 0;

    for(int j = 1; i <= n; ++i) {
        for(int i = 1; i <= j - 1; ++i) {
            ans += calc(dp[i][j]);
            ans %= MOD;
        }
    }


    return 0;
}