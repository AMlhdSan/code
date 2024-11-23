#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, y, p;
long long ans = 0;

ll c(ll n, ll m){
    ll res = 1;
    for (ll i = 1; i <= n; ++i) 
        res *= i;
    for (ll i = 1; i <= m; ++i) 
        res /= i;
    for (ll i = 1; i <= n - m; ++i) 
        res /= i;
    return res;
}
 
int main()
{
    cin >> n >> y >> p;

    for(int x = 0; x <= n && x <= n - y; ++x) {
        ans += c(n, x) * c(n, x + y) % p;
        ans %= p;
    }

    cout << ans << endl;
    
    return 0;
}