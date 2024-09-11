#include <bits/stdc++.h>
using namespace std;

int n, c;
int sum[1001];
int maxx;

int main() {

    ios::sync_with_stdio(false);

    cin >> n >> c;
    a[0] = 0;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
        if(a[i] > c) {

        }
    }

    cout << maxx << endl;
    return 0;
}