#include <bits/stdc++.h>

#define N 401

using namespace std;

int n;
int s[N], f[N];
int dp[N][N];
int ss[N], ff[N];

int main() {

    cin >> n;
    
    for(int i = 1; i <= n; ++i) 
        cin >> s[i] >> f[i];
    
    dp[0][0] = 0;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            dp[i][j] = ;
        }
    }
    return 0;
}