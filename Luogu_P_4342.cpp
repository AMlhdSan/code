#include <bits/stdc++.h>

#define N 51

using namespace std;

int n;
int ta;
int tb;
int t[N << 1];
int a[N << 1][N << 1];
int b[N << 1][N << 1];

int main() {

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        char tmp;
        cin >> tmp;
        cin >> a[i];
        a[i + n] = a[i];
        dp[i][i] = a[i];
        dp[i + n][i + n] = a[i];

        if(tmp == 't') {
            t[i] = t[i + n] = 1;
        }
        else {
            t[i] = t[i + n] = 0;
        }
    }

    for(int l = 1; l <= n; ++l) {
        for(int i = 1; i <= (n << 1) - l + 1; ++i) {
            int j = i + l - 1;
            for(int k = i; k <= j - 1; ++k) {
                if(t[k]) { // *
                    dp[i][j] = max(d[i][j], )
                }
                else { // +

                }
            }
        }
    }



    return 0;
}