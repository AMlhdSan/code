#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const ll MOD = 998244353;
 
inline int read(){
    int x=0, f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        x = (x<<3) + (x<<1) + (ch^48);
        ch=getchar();
    }
    return x * f;
}
 
inline void write(ll x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
 
inline void writeln(ll x){
    write(x);
    putchar('\n');
}
 
ll modexp(ll a, ll b, ll m){
    ll res = 1 % m;
    a %= m;
    while(b){
        if(b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}
 
int main(){
    freopen("45.in", "r", stdin);
    freopen("45.out", "w", stdout);
    int T;
    T = read();
    while(T--) {
    int n = read();
    int y = read();
    if(y==0){
        writeln(0);
        // return 0;
        continue;
    }
    int r = min(y, n);
    ll P = modexp(10, n, MOD);
    ll t1 = modexp(10, n-1, MOD);
    ll t2 = modexp(10, n - r, MOD);
    ll num = ((40 % MOD) * t1 + (5 % MOD) * t2) % MOD;
    ll inv9 = modexp(9, MOD-2, MOD);
    ll T_val = (num * inv9) % MOD;
    ll B = (P + MOD - 1) % MOD;
    ll cnt = ( (P + MOD) - T_val ) % MOD;
    ll sumPair = (T_val + B) % MOD;
    ll inv2 = modexp(2, MOD-2, MOD);
    ll ans = ( (sumPair % MOD) * (cnt % MOD) ) % MOD;
    ans = (ans * inv2) % MOD;
    writeln(ans);
    }
    return 0;
}
