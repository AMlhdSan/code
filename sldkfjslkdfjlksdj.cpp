#include <bits/stdc++.h>
using namespace std;

const int MOD=1000000007;

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

inline void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(int x) {
    write(x);
    putchar('\n');
}

int n,m;
vector<long long> b, t1, t2;

void add(vector<long long>& t,int i,long long v){
    if(v<0) v=(v%MOD+MOD)%MOD; else v%=MOD;
    for(;i<=n;i+=i&-i){ t[i]+=v; if(t[i]>=MOD) t[i]-=MOD; }
}
long long sum(const vector<long long>& t,int i){
    long long r=0;
    for(;i;i-=i&-i){ r+=t[i]; if(r>=MOD) r-=MOD; }
    return r;
}
long long qpow(long long a,long long e){
    long long r=1%MOD; a%=MOD;
    while(e){ if(e&1) r=r*a%MOD; a=a*a%MOD; e>>=1; }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    n=read(); m=read();
    b.assign(n+1,0); t1.assign(n+1,0); t2.assign(n+1,0);
    for(int i=1;i<=n;i++){
        long long x=read();
        b[i]=x%MOD;
        add(t1,i,b[i]);
        add(t2,i,(x%MOD)*(x%MOD)%MOD);
    }
    while(m--){
        int c=read(), x=read(), y=read();
        if(c==1){
            long long old=b[x];
            long long ny=y%MOD;
            long long d1=ny-old; if(d1<0) d1+=MOD;
            long long d2=(ny*ny%MOD - old*old%MOD); if(d2<0) d2+=MOD;
            add(t1,x,d1);
            add(t2,x,d2);
            b[x]=ny;
        }else{
            int l=x,r=y;
            int k=r-l+1;
            long long S1=(sum(t1,r)-sum(t1,l-1)+MOD)%MOD;
            long long S2=(sum(t2,r)-sum(t2,l-1)+MOD)%MOD;
            long long invk=qpow(k,MOD-2);
            long long tA=S2*invk%MOD;
            long long tB=S1*invk%MOD;
            long long ans=(tA - tB*tB%MOD + MOD)%MOD;
            writeln((int)ans);
        }
    }
    return 0;
}
