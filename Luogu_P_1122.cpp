#include <bits/stdc++.h>

#define N 16001

using namespace std;

int a[N];
int n;
int dp[N];
int tmp1, tmp2;

vector<int> edge[N];

void dfs(int p, int pre) {
    dp[p] = a[p];
    for(int e : edge[p]) {
        if(e != pre) {
            dfs(e, p);
            dp[p] = max(dp[p], dp[e] + dp[p]);
        }
    }
}

int main() {

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        //dp[i] = a[i];
    }

    for(int i = 1; i <= n - 1; ++i) {
        cin >> tmp1 >> tmp2;
        edge[tmp1].push_back(tmp2);
        edge[tmp2].push_back(tmp1);
    }

    dfs(1, 0);
    int maxx = -0x7fffffff;

    for(int i = 1; i <= n; ++i) {
        maxx = max(maxx, dp[i]);
    }
    cout << maxx << endl;

    return 0;
}