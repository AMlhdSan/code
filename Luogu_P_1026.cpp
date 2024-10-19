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

int main() {

    cin >> p >> k;

    len = p * 20;

    while(p--) {
        cin >> tmp;
        str += tmp;
    }

    cin >> s;

    for(int i = 1; i <= s; ++i) {
        cin >> word[i];
    }

    for(int i = 1; i <= len; ++i) {
        for(int j = i; j <= len; ++j) {
            int ll = j - i + 1
            tmp = str.substr(i, ll);
            for(int k = 1; k <= s; ++k) {
                if(tmp.find(word[i]) != tmp.npos) {
                    ++sum[i][j];
                }
            }
        }
    }

    for(int i = 1; i <= n; ++i) {
        dp[i][1] = sum[1][i];
    }

    for(int i = 1; i <= len; ++i) {
        for(int j = 2; j <= len; ++j) {
            
        }
    }

    return 0;
}