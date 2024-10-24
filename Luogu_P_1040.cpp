#include <bits/stdc++.h>

#define N 31
#define ll long long

using namespace std;

int n;
int a[N];
ll ans = 0;
ll dp[N][N];
int rr[N][N];

void coutt(int l, int r) {
    if(l == r) {
        cout << l << ' ';
        return;
    }
    else if(l > r) {
        return;
    }
    cout << rr[l][r] << ' ';
    coutt(l, rr[l][r] - 1);
    coutt(rr[l][r] + 1, r);
}

int main() {

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        rr[i][i] = i;
        dp[i][i] = a[i];
        dp[i][i - 1] = 1;
    }

    for(int len = 2; len <= n; ++len) {
        for(int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            for(int k = i; k < j; ++k) {
                int tmp = dp[i][k - 1] * dp[k + 1][j] + dp[k][k];
                if(tmp > dp[i][j]) {
                    dp[i][j] = tmp;
                    rr[i][j] = k;
                }
            }
        }
    }
    cout << dp[1][n] << endl;
    coutt(1, n);
    return 0;
}