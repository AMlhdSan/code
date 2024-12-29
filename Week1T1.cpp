#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll n;
ll c;
ll l, r;
ll a, b;

int main() {

	cin >> n;

	for(int i = 1; i <= n; ++i) {
        b = a;
		cin >> a;
        if(i == 1) {
            b = a;
            continue;
        }
        else {
            c = a - b;
            if(c > 0)
                l += c;
            else
                r -= c;
        }
	}

	cout << max(l, r) << endl << abs(l - r) + 1;

	return 0;
}