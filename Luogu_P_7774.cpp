#include <bits/stdc++.h>

#define N 11
#define M 11
#define MAX 361

using namespace std;

int n, m;
int a[N], b;
int dp[MAX];

int main() {

    cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    dp[0] = 1;

    for(int i = 1; i <= n; ++i) {
        for(int j = a[i]; j <= 1000; ++j) {
            dp[j % 360] = max(dp[j % 360], max(dp[(j - a[i]) % 360], dp[(j + a[i]) % 360]));
        }
    }

    while(m--) {
        cin >> b;
        if(dp[b]) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}