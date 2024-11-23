#include <bits/stdc++.h>

#define N 100010
#define ll long long 
#define MOD 100000007

using namespace std;

ll n;
ll a[N];
ll sum[N];
ll s = 0;
ll cnt = 1;
ll num[N];

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

int main() {

    n = read();
    for(ll i = 1; i <= n; ++i) {
        a[i] = read();
    }

    sort(a + 1, a + 1 + n);

    for(ll i = 1; i <= n; ++i) {
        
    }
    return 0;
}