#include <bits/stdc++.h>

#define N 11
#define M 11
#define K 51
#define R 151

using namespace std;

int n, m, k, r;
int a[N], b[M], c[K];
int dp[R];
int sum;
int ans = 0;

int main() {

    cin >> n >> m >> k >> r;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    for(int i = 1; i <= m; ++i) {
        cin >> b[i];
    }

    for(int i = 1; i <= m; ++i) {
        cin >> c[i];
    }

    for(int i = 1; i <= m; ++i) {
        for(int j = r; j >= b[i]; --j) {
            dp[j] = max(dp[j], dp[j - b[i]] + c[i]);
        }
    }

    for(int i = 1; i <= r; ++i) {
        if(dp[i] >= k) {
            sum = r - i;
            break;
        }
    }

    for(int i = 1; i <= n; ++i) {
        if(sum > a[i]) {
            sum -= a[i];
            ++ans;
        } 
        else {
            break;
        }
    }

    cout << ans << endl;

    return 0;
}