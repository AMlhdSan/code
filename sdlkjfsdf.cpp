#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
inline int read(){
    int x=0, f=1; char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1; c=getchar();
    }
    while(c>='0'&&c<='9'){
        x = (x<<3)+(x<<1)+(c^48); c=getchar();
    }
    return x*f;
}
inline void write(int x){
    if(x<0){putchar('-'); x=-x;}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
inline void writeln(int x){ write(x); putchar('\n'); }
 
int modPow(long long b, int e){
    long long res=1;
    while(e){
        if(e&1) res = res*b % mod;
        b = b*b % mod;
        e >>= 1;
    }
    return res;
}
 
int main(){
    // freopen("calculation.in", "r", stdin);
    // freopen("calculation.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = read(), s = read();
    vector<pair<int,int>> seg(n);
    for(int i=0;i<n;i++){
        int l = read(), r = read();
        seg[i] = {l, r};
    }
    int M = s+2;
    vector<vector<int>> bin(M, vector<int>(M,0));
    for(int i=0;i<M;i++){
        bin[i][0]=1;
        for(int j=1;j<=i;j++){
            bin[i][j]=(bin[i-1][j-1]+bin[i-1][j]) % mod;
        }
    }
    vector<int> inv(M,1);
    for(int i=1;i<M;i++){
        inv[i] = modPow(i, mod-2);
    }
    vector<int> dp(s+1,0), ndp(s+1,0);
    dp[0]=1;
    for(int i=0;i<n;i++){
        int l = seg[i].first, r = seg[i].second;
        vector<int> poly(s+1,0);
        for(int b = l; b<=r; b++){
            // do nothing; we compute F(n,k)=sum_{x=1}^{n} x^k via recurrence
        }
        auto F = [&](int N) -> vector<int> {
            vector<int> f(s+1,0);
            if(N<0) return f;
            f[0] = N % mod;
            for(int k=1;k<=s;k++){
                int num = (modPow(N+1, k+1) - 1 + mod) % mod;
                for(int j=0;j<k;j++){
                    num = (num - (long long)bin[k+1][j] * f[j] % mod + mod) % mod;
                }
                f[k] = (long long)num * inv[k+1] % mod;
            }
            return f;
        };
        vector<int> Fr = F(r), Fl = F(l-1);
        for(int t=0;t<=s;t++){
            poly[t] = (Fr[t] - Fl[t] + mod) % mod;
        }
        fill(ndp.begin(), ndp.end(), 0);
        for(int j=0;j<=s;j++){
            if(dp[j]){
                for(int t=0;j+t<=s;t++){
                    ndp[j+t] = (ndp[j+t] + (long long)dp[j]*poly[t] % mod) % mod;
                }
            }
        }
        dp = ndp;
    }
    writeln(dp[s]);
    return 0;
}
