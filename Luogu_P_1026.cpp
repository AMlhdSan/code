#include <bits/stdc++.h>

#define N 201
#define M 41

using namespace std;

int p, k;
string str = "_";
string tmp;
int len;
int s;
string word[7];
int sum[N][N];
int dp[N][M];
bool flag = 1;

int main() {

    cin >> p >> k;

    while(p--) {
        cin >> tmp;
        str += tmp;
    }

    len = str.length() - 1;

    cin >> s;

    for(int i = 1; i <= s; ++i) {
        cin >> word[i];
    }

    for(int j = len; j >= 1; --j) {
        for(int i = j; i >= 1; --i) {
            int ll = j - i + 1;
            tmp = str.substr(i, ll);
            sum[i][j] = sum[i + 1][j];
            flag = 0;
            for(int t = 1; t <= s; ++t) {
                if(tmp.find(word[t]) == 0) {
                    flag = 1;
                    break;
                }
            }
            if(flag)
                ++sum[i][j];
        }
    }

    for(int i = 1; i <= len; ++i) {
        dp[i][1] = sum[1][i];
    }

    for(int i = 1; i <= len; ++i) {
        for(int j = 1; j <= k && j < i; ++j) {
            for(int t = j; t < i; ++t) {
                dp[i][j] = max(dp[i][j], dp[t][j - 1] + sum[t + 1][i]);
            }
        }
    }
    
    cout << dp[len][k] << endl;

    return 0;
}