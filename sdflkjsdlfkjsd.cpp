#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
ll p(ll a, ll b, ll mod) {
    ll r = 1;
    a %= mod;
    while(b) {
        if(b & 1) r = (r * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return r;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    int M = 2000000;
    vector<ll> f(M+1), inv(M+1);
    f[0] = 1;
    for (int i = 1; i <= M; i++) {
        f[i] = f[i-1] * i % MOD;
    }
    inv[M] = p(f[M], MOD-2, MOD);
    for (int i = M; i >= 1; i--) {
        inv[i-1] = inv[i] * i % MOD;
    }
    auto C = [&](int n, int k) -> ll {
        if(k < 0 || k > n) return 0;
        return f[n] * inv[k] % MOD * inv[n-k] % MOD;
    };
    while(T--){
        int a, b;
        cin >> a >> b;
        if(a == 0 || b == 0){
            cout << 1 << "\n";
            continue;
        }
        int s = a + b;
        ll tot = C(s, a);
        ll tns = ((s - 1LL) * 2 % MOD) * C(s - 2, a - 1) % MOD;
        cout << (tot + tns) % MOD << "\n";
    }
    return 0;
}
