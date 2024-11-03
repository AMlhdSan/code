#include <bits/stdc++.h>

#define N 1000001

using namespace std;

int dp[N][3];
int a[N];
int n;

int main() {

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    } 

    dp[1][a[1]] = 0;
    
    for(int i = 2; i <= n; ++i) {
        if(a[i] == 1) {
            
        }
    }
    return 0;
}