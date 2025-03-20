#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

inline int read(){
    int x=0,f=1; char ch=getchar();
    while(ch<'0' || ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
inline void write(ll x){
    if(x<0){putchar('-'); x=-x;}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
inline void writeln(ll x){
    write(x); putchar('\n');
}
ll modexp(ll a,ll b){
    ll res=1; a%=MOD;
    while(b){
        if(b&1) res=(res*a)%MOD;
        a=(a*a)%MOD; b>>=1;
    }
    return res;
}
ll inv(ll x){ return modexp(x,MOD-2); }
struct NodeRes{
    int L;
    long double F;
    ll Fm;
};
int n;
vector<vector<int>> child;
vector<char> cam;
NodeRes dfs(int u){
    if(child[u].empty()){
        return {1,0.0,0};
    }
    vector<NodeRes> vec;
    int tot = 0;
    for(auto v : child[u]){
        NodeRes res = dfs(v);
        tot += res.L;
        vec.push_back(res);
    }
    vector<pair<long double,int>> ord;
    for(int i=0;i<vec.size();i++){
        long double A = (cam[child[u][i]]=='Y' ? 2.0 : (2.0+vec[i].F));
        ord.push_back({A/vec[i].L, i});
    }
    sort(ord.begin(), ord.end(), [](auto &a, auto &b){ return a.first < b.first; });
    long double num = 0.0;
    ll numm = 0;
    int sum = tot;
    for(auto &p : ord){
        int idx = p.second;
        int v = child[u][idx];
        long double T = 1.0 + vec[idx].F;
        long double A = (cam[v]=='Y' ? 2.0 : (2.0+vec[idx].F));
        num += T * vec[idx].L + A * (sum - vec[idx].L);
        numm = numm + (( ( (1 + vec[idx].Fm) % MOD) * vec[idx].L) % MOD) % MOD;
        ll A_mod = (cam[v]=='Y' ? 2LL : ((2 + vec[idx].Fm) % MOD));
        numm = (numm + (A_mod * ((sum - vec[idx].L) % MOD)) % MOD) % MOD;
        sum -= vec[idx].L;
    }
    long double Fval = num / tot;
    ll Fmod = (numm * inv(tot)) % MOD;
    return {tot, Fval, Fmod};
}
int main(){
    freopen("catch.in", "r", stdin);
    freopen("catch.out", "w", stdout);
    n = read();
    child.resize(n+1);
    cam.resize(n+1, 'N');
    //节点1为根，无监控
    for(int i=2;i<=n;i++){
        int f = read();
        char c; 
        scanf(" %c", &c);
        child[f].push_back(i);
        cam[i] = c;
    }
    NodeRes res = dfs(1);
    writeln(res.Fm);
    return 0;
}
