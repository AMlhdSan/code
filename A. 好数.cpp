#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll n;

ll qpow(ll a, ll b) {
	ll ans = 1;
	while(b > 0) {
		if(b & 1) {
			ans *= a;
		}
		a = a * a;
		b >>= 1;
	}
	return ans;
}

bool test(ll p) {
    for(ll i = 2; i <= 24; ++i) {
        for(ll j = 1; j; ++j) {
            if(qpow(j, i) == p) {
                return 1;
            }
            else if(qpow(j, i) > p) {
                break;
            }
        }
    }
    return 0;
}

int main() {

    cin >> n;

    for(ll i = n; i >= 1; --i) {
        if(test(i)) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}