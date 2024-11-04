#include <bits/stdc++.h>

#define MOD 1000000007 
#define N 200001

using namespace std;

int ans[N];

int n, a, b, c;

int dfs(int t) {
    if(t <= c) {
        return 1;
    }
    else if(ans[t]) {
        return ans[t];
    }
    else {
        ans[t] = (dfs(t - a) % MOD + dfs(t - b) % MOD) % MOD;
        return ans[t];
    }
}

int main() {

    cin >> n >> a >> b >> c;

    cout << dfs(n);

    return 0;
}