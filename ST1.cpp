#include <bits/stdc++.h>
using namespace std;
int n;
int r[100001];
int t[100001];
int maxx = -1;
int main() {
    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> r[i];
        ++t[r[i]];
        maxx = max(maxx, t[r[i]]);
    }
    cout << maxx << endl;
    return 0;
}