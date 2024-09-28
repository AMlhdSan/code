#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int T;
ll n, m;

int main() {
    cin >> T;
    while(T--) {
        cin >> n >> m;
        if(n == m) {
            cout << 0 << endl;
        }
        else if(gcd(n, m) == 1) {
            cout << -1 << endl;
        }
        else {
            breakdown(n);
            breakdown(m);
        }
    }
    return 0;
}