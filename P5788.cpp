#include <bits/stdc++.h>
using namespace std;

int n;
int a[3000001];
int ans[3000001];
stack<pair<int, int> > q;

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++i) {
        if(q.empty()) {
            q.push(make_pair(a[i], i));
        }
        else if(a[i] < q.top().first) {
            q.push(make_pair(a[i], i));
        }
        else {
            while(!q.empty()) {
                if(a[i] > q.top().first) {
                    ans[q.top().second] = i;
                    q.pop();
                }
                else {
                    q.push(make_pair(a[i], i));
                    break;
                }
            }
            if(q.empty()) {
                q.push(make_pair(a[i], i));
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}