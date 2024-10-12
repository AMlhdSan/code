#include <bits/stdc++.h>

#define N 501

using namespace std;

int dp[N][N];
int a[N];
int n;

int main() {

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for(int i = 1; i <= n - 1; ++i) {
        if(a[i] == a[i + 1]) {
            dp[i][i + 1] = 1;
        }
        else {
            dp[i][i + 1] = 2;
        }
    }

    return 0;
}