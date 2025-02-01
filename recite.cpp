#include <bits/stdc++.h>

#define int long long

using namespace std;

int n, m, k;
int ans;

inline long long poww(long long a, long long b, long long mod) {
    long long res = 1;
    while(b) {
        if(b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}

signed main() {

    // freopen("recite.in", "r", stdin);
    // freopen("recite.out", "w", stdout);

    cin >> n >> m >> k;

    if(k == 0)
        cout << (long long)poww(2, poww(2, n, m - 1), m) % m << endl;
    return 0;
}