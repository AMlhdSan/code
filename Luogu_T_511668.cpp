#include <bits/stdc++.h>

#define N 100001
#define ll long long

using namespace std;

char ch[N];
int v[N];
ll dp[N]; // 表示从第i位删到第n为的最小代价
int T;
int len;

int main() {

    cin >> T;
    cin >> T;

    while(T--) {
        memset(dp, 0x3f, sizeof(dp));
        cin >> ch + 1;
        len = strlen(ch + 1);
        for(int i = 1; i <= len; ++i) {
            cin >> v[i];
        }

    }

    

    return 0;
}