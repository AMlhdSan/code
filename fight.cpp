#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll n, y, p;
long long ans = 0;

ll c(ll n, ll m) {
    ll a = 1, b = 1, c = 1;
    for (ll i = n; i >= 1; --i) 
        a *= i;
    for (ll i = m; i >= 1; --i) 
        b *= i;
    for (ll i = n - m; i >= 1; --i) 
        c *= i;
    return a / (b * c);
}

int main() {
    cin >> n >> y >> p;

    for(int x = 0; x <= n && x + y <= n && x + y >= 0; ++x) {
        ans += c(n, x) * c(n, x + y);
    }

    cout << ans % p << endl;
    
    return 0;
}