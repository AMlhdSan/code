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

bool cmp(int x, int y) {
    return x > y;
}

int main() {
    
    // freopen("permutation.in", "r", stdin);
    // freopen("permutation.out", "w", stdout);

    n = read();
    for(ll i = 1; i <= n; ++i) {
        a[i] = read();
    }

    sort(a + 1, a + n + 1, cmp);

    fill(num + 1, num + 1 + n, 1);

    for(ll i = 2; i <= n; ++i) {
        if(a[i] == a[i - 1]) {
            ++num[cnt];
        }
        else
            ++cnt;
    }

    unique(a + 1, a + n + 1);

    for(ll i = 1; i <= cnt; ++i) {
        sum[i] = sum[i - 1] + a[i] * num[i];
    }
    for(ll i = 2; i <= cnt; ++i) {
        s += num[i] * sum[i - 1] * a[i];
        s %= MOD;
    }

    for(ll i = 3; i <= n; ++i) {
        s *= i;
        s %= MOD;
    }

    cout << s << endl;

    return 0;
}