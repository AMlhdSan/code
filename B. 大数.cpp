#include <bits/stdc++.h>


#define MOD 998244353

using namespace std;

int T;
int x[101];

long long qpow(long long a, long long b, long long p) {
	long long ans = 1;
	while(b > 0) {
		if(b & 1) {
			ans = (ans % p) * (a % p);
			ans %= p;
		}
		a = (a % p) * (a % p);
		b >>= 1;
	}
	return ans;
}

int main() {
    
    cin >> T;

    while (T--) {
        for(int i = 1; i <= 9; ++i) {
            cin >> x[i];
        }
        x[10] = 0;
        for(int i = 2; i <= 9; ++i) {
            if(x[1] == 0) {
                break;
            }
            if(x[1] >= x[i]) {
                x[1] -= x[i];
                x[i + 1] += x[i];
                x[i] = 0;
            }
            else {
                x[i] -= x[1];
                x[i + 1] += x[1];
                x[1] = 0;
                break;
            }
        }
        long long ans = 1;
        for(int i = 2; i <= 10; ++i) {
            ans *= qpow(i, x[i], MOD) % MOD;
            ans %= MOD;
        }
        cout << ans << endl;
    }

    return 0;
}
