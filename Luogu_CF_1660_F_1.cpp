#include <bits/stdc++.h>
using namespace std;
 
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

inline void put(int x){
    if(x<0){ putchar('-'); x=-x; }
    if(x>9) put(x/10);
    putchar(x%10+'0');
}
 
inline void write(int x){
    if(x<0){ putchar('-'); x=-x; }
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
 
inline void writeln(int x){
    write(x);
    putchar('\n');
}
 
struct Fenw{
    int n;
    vector<int> f;
    Fenw(int n): n(n), f(n+1,0){}
    void upd(int i,int v){
        for(; i<=n; i+= i&-i) f[i]+=v;
    }
    int query(int i){
        int s=0;
        for(; i; i-= i&-i) s+=f[i];
        return s;
    }
    int queryRange(int l,int r){
        return query(r)-query(l-1);
    }
};
/*
inline void build(int p, int l, int r) {
    if(l == r) {
        tree[p] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    tree[p] = tree[p << 1] + tree[p << 1 | 1];
}
*/


int main(){
    int t=read();
    while(t--){
        int n=read();
        string s;
        cin >> s;
        vector<long long> p(n+1,0);
        for(int i=0;i<n;i++){
            p[i+1] = p[i] + (s[i]=='+'?1:-1);
        }
        vector<vector<long long>> g(3);
        for(int i=0;i<=n;i++){
            int r = ((p[i] % 3) + 3) % 3;
            g[r].push_back(p[i]);
        }
        long long ans=0;
        for(int r=0;r<3;r++){
            vector<long long> a = g[r], comp = a;
            sort(comp.begin(), comp.end());
            comp.erase(unique(comp.begin(), comp.end()), comp.end());
            int m = comp.size();
            Fenw fenw(m);
            for(auto v: a){
                int idx = lower_bound(comp.begin(), comp.end(), v) - comp.begin() + 1;
                ans += fenw.queryRange(idx, m);
                fenw.upd(idx,1);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}