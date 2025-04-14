#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
inline void write(int x){
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
inline void writeln(int x){
    write(x);
    putchar('\n');
}
long long modExp(long long b, long long e) {
    long long r = 1 % MOD;
    b %= MOD;
    while(e){
        if(e & 1) r = (r * b) % MOD;
        b = (b * b) % MOD;
        e >>= 1;
    }
    return r;
}
int main(){
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    int T = read();
    vector<tuple<int,int,int>> qs;
    int maxN = 0;
    for(int i = 0; i < T; i++){
        int n = read(), m = read(), k = read();
        qs.push_back({n, m, k});
        if(n > maxN) maxN = n;
    }
    vector<int> fac(maxN+1), invfac(maxN+1);
    fac[0] = 1;
    for (int i = 1; i <= maxN; i++) fac[i] = (long long)fac[i-1] * i % MOD;
    invfac[maxN] = modExp(fac[maxN], MOD-2);
    for (int i = maxN; i >= 0; i--) {
        if(i) invfac[i-1] = (long long)invfac[i] * i % MOD;
    }
    for(auto &t : qs){
        int n, m, k;
        tie(n, m, k) = t;
        long long ans = 0;
        if(k > n){
            writeln(0);
            continue;
        }
        int lim = n - k;
        long long base = (m - 1LL) % MOD;
        for (int j = 0; j <= lim; j++){
            long long comb = (long long)fac[n] * invfac[j] % MOD * invfac[n - j] % MOD;
            long long p = modExp(base, j);
            ans = (ans + comb * p % MOD) % MOD;
        }
        writeln((int)ans);
    }
    return 0;
}
