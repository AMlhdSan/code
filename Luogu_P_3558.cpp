/*一维数组*/
#include <bits/stdc++.h>

using namespace std;

int dp[3];
int dp1[3];
int a, b;
int n;
int ans;

int main() {
    cin >> n;
    dp[1] = dp[2] = dp[0] = 0x3f3f3f3f;
    cin >> a;
    b = a;
    dp[a + 1] = 0;
    for(int i = 2; i <= n; ++i) {
        dp1[1] = dp[1];
        dp1[2] = dp[2];
        dp1[0] = dp[0];
        cin >> a;
        if(a == -1) {
            dp[0] = dp1[0];
            if(b == 1) {
                dp[1] = min(dp1[0], dp1[1]) + 1;
            }
            if(b == 1) {
                dp[2] = min(dp1[0], min(dp1[1], dp1[2])) + 2;
            }
            else {
                dp[2] = dp1[2] + 2;
            }
        }
        else if(a == 0) {
            dp[0] = dp1[0] + 1;
            dp[1] = min(dp1[0], dp1[1]);
            if(b == 1) {
                dp[2] = min(dp1[0], min(dp1[1], dp1[2])) + 1;
            }
            else {
                dp[2] = dp1[2] + 1;
            }
        }
        else {
            dp[0] = dp1[0] + 2;
            if(b == -1) {
                dp[1] = min(dp1[1], dp1[0]) + 1;
            }
            else {
                dp[1] = dp1[0] + 1;
            }
            dp[2] = min(dp1[1], min(dp1[2], dp1[0]));
        }
    }

    ans = min(dp[0], min(dp[1], dp[2]));
    if(ans >= 0x3f3f3f3f) {
        cout << "BRAK" << endl;
    }
    else {
        cout << ans << endl;
    }
    
    return 0;
}

/* 二维数组*/

/*
#include <bits/stdc++.h>

#define N 1000001

using namespace std;

int dp[N][3];
int a[N];
int n;
int ans;

int main() {

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    } 

    for(int i = 1; i <= n; ++i) {
        dp[i][1] = dp[i][2] = dp[i][0] = 0x3f3f3f3f;
    } 

    dp[1][a[1] + 1] = 0;
    
    for(int i = 2; i <= n; ++i) {
        if(a[i] == -1) {
            dp[i][0] = dp[i - 1][0];
            if(a[i - 1] == 1) {
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
            }
            if(a[i - 1] == 1) {
                dp[i][2] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 2;
            }
            else {
                dp[i][2] = dp[i - 1][2] + 2;
            }
        }
        else if(a[i] == 0) {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
            if(a[i - 1] == 1) {
                dp[i][2] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
            }
            else {
                dp[i][2] = dp[i - 1][2] + 1;
            }
        }
        else {
            dp[i][0] = dp[i - 1][0] + 2;
            if(a[i - 1] == -1) {
                dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]) + 1;
            }
            else {
                dp[i][1] = dp[i - 1][0] + 1;
            }
            dp[i][2] = min(dp[i - 1][1], min(dp[i - 1][2], dp[i - 1][0]));
        }
    }

    ans = min(dp[n][0], min(dp[n][1], dp[n][2]));
    if(ans >= 0x3f3f3f3f) {
        cout << "BRAK" << endl;
    }
    else {
        cout << ans << endl;
    }
    
    return 0;
}
*/