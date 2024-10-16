#include <bits/stdc++.h>

#define N 101

using namespace std;

string str;
int len;
int dp[N][N]; // 

string out(int l, int r) {
    string ans = "";
    for(int i = l; i <= r; ++i) {
        ans += str[i];
    }
    return ans;
}

int f(int x) {
    if(x <= 9) {
        return 1;
    }
    if(x <= 99) {
        return 2;
    }
    if(x <= 100) {
        return 3;
    }
}

int main() {

    cin >> str;
    len = str.length();
    str = " " + str;

    memset(dp, 0x3f, sizeof(dp));

    for(int i = 1; i <= len; ++i) {
        dp[i][i] = 1;
    }

    for(int l = 1; l <= len; ++l) {
        for(int i = 1; i + l - 1 <= len; ++i) {
            int j = i + l - 1;
            for(int k = i; k <= j - 1; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
            for(int k = i; k <= j - 1; ++k) {
                if(l % (k - i + 1) != 0) {
                    continue;
                }
                string tmp = out(i, k);
                string tar = "";
                for(int t = 1; t <= l / (k - i + 1); ++t) {
                    tar += tmp;
                }
                if(tar == out(i, j)) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + 2 + f(l / (k - i + 1)));
                }
            }
        }
    }
    cout << dp[1][len] << endl;

    return 0;
}