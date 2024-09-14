#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, c;
int a[1001];
int maxx;

int summ(int t) {
    int sum = 0;
    for(int i = 1; i <= t; ++i)
        sum += a[i];
    return sum;
}

void dfs(int t, int sum) {
    if(sum + summ(t) <= maxx) {
        return ;
    }
    maxx = max(maxx, sum);
    for(int i = t; i >= 1; --i) {
        if(sum + a[i] <= c) {
            dfs(i - 1, sum + a[i]);
        }
    }
    return ;
}

signed main() {

    ios::sync_with_stdio(false);

    cin >> n >> c;

    a[0] = 0;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        
        if(a[i] > c) {
            n = i - 1;
            break;
        }
    }

    dfs(n, 0);

    cout << maxx << endl;
    return 0;
}