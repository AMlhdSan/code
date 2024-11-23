#include <bits/stdc++.h>

#define N 100001
#define ll long long

using namespace std;

ll n;
ll a[N], b[N];

ll gcd(ll a, ll b) {
	if(!b) 
        return a;
	else return gcd(b, a % b);
}

inline ll read() {
    ll x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

void merge(ll p1, ll a1, ll p2, ll a2, ll &p, ll &a) {
	p = p1 / gcd(p1, p2) * p2;
	if(p1 < p2) {
        swap(p1, p2);
        swap(a1, a2);
    }
	a = a1;
	while(a % p2 != a2)
		a += p1;
}
int main() {

	n = read();

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
        b[i] = read();
        b[i] %= a[i];
    }

    for(int i = 2; i <= n; ++i) {
        merge(a[i], b[i], a[i - 1], b[i - 1], a[i], b[i]);
    }

    cout << b[n] << endl;

	return 0;
}
