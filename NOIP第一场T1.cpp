#include <bits/stdc++.h>

#define N 1010
#define ll long long

using namespace std;

ll n, m, k, p;
ll a[N][N];
ll lsum[N], hsum[N];

int main() {

    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n >> m >> k >> p;

    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= m; ++j) {
            cin >> a[i][j];
            lsum[j] += a[i][j];
            hsum[i] += a[i][j];
        }
    }

    if(p == 0) {
        ll maxx = -0x7fffffff;
        for(ll i = 1; i <= n; ++i) {
            maxx = max(maxx, hsum[i]);
        }
        for(ll i = 1; i <= m; ++i) {
            maxx = max(maxx, lsum[i]);
        }
        cout << maxx * k << endl;
    }
    else if(n == 1 && m == 1) {
        cout << (a[1][1] + a[1][1] - (k - 1) * p) * k / 2 << endl;
    }
    else if(n == 1) {
        
    }

    return 0;
}