#include <bits/stdc++.h>

#define int long long

using namespace std;

int n;
int tmp;
int ans = 0;

priority_queue<int> q;

signed main() {

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> tmp;
        q.push(-tmp);
        if(-q.top() < tmp) {
            ans += tmp + q.top();
            q.pop();
            q.push(-tmp);
        }
    }
    cout << ans << endl;

    return 0;
}