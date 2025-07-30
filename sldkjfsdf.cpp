#include <bits/stdc++.h>
using namespace std;

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*f;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
inline void writeln(int x){
    write(x);putchar('\n');
}

const int MOD=104857601;
typedef long long ll;
ll powmod(ll a,ll b){
    ll r=1;
    while(b){if(b&1)r=r*a%MOD;a=a*a%MOD;b>>=1;}
    return r;
}
void prep(int n, vector<ll>& f, vector<ll>& inv){
    f[0]=1;
    for(int i=1;i<=n;i++)f[i]=f[i-1]*i%MOD;
    inv[n]=powmod(f[n],MOD-2);
    for(int i=n;i>0;i--)inv[i-1]=inv[i]*i%MOD;
}
inline ll C(const vector<ll>& f,const vector<ll>& inv,int n,int k){
    return f[n]*inv[k]%MOD*inv[n-k]%MOD;
}

int n,m,q;
char *outp;
static char outbuf[1<<23];

namespace T1{
    void go(){
        outbuf[0]='0';
        for(int i=1;i<(1<<22);i<<=1)
            for(int j=0;j<i;j++)
                outbuf[i+j]=outbuf[j]^1;
        fwrite(outbuf,1,1<<22,stdout);
        putchar('\n');
    }
}

namespace T2{
    void go(){
        string a="0",b="1",c;
        for(int i=3;i<=33;i++){c=a+b;a=b;b=c;}
        fwrite(b.data(),1,b.size(),stdout);
        putchar('\n');
    }
}

namespace T3{
    bool vis[532000];
    bool dfs(int x,int y){
        if(x==531441)return true;
        y=y*3%531441;
        for(int i=0;i<3;i++){
            if(!vis[y+i]){
                vis[y+i]=1;
                *outp++=i+'0';
                if(dfs(x+1,y+i))return true;
                vis[y+i]=0; outp--;
            }
        }
        return false;
    }
    void go(){
        outp=outbuf;
        for(int i=0;i<11;i++)*outp++='0';
        dfs(0,0);
        *outp++='\n';
        fwrite(outbuf,1,outp-outbuf,stdout);
    }
}

namespace T4{
    void go(){
        prep(262144, *(new vector<ll>(262145)), *(new vector<ll>(262145)));
        auto &f=*(vector<ll>*)(&*(new vector<ll>(262145)));
        auto &inv=*(vector<ll>*)(&*(new vector<ll>(262145)));
        vector<ll> ff(262145),ii(262145);
        f=vector<ll>(262145); ii=vector<ll>(262145);
        prep(262144,f,ii);
        writeln(262144);
        for(int i=0;i<=262144;i++)writeln(C(f,ii,262144,i));
    }
}

namespace T5{
    void go(){
        vector<ll> f(131073),ii(131073);
        prep(131072,f,ii);
        writeln(131072);
        for(int i=0;i<=131072;i++){
            ll v=C(f,ii,131072,i);
            if(i&1)v=(MOD-v)%MOD;
            writeln(v);
        }
    }
}

namespace T6{
    void go(){
        vector<ll> f(177148),ii(177148);
        prep(177147,f,ii);
        writeln(177147);
        for(int i=0;i<=177147;i++){
            ll v=C(f,ii,177147,i)*powmod(23333333,177147-i)%MOD*powmod(33333333,i)%MOD;
            writeln(v);
        }
    }
}

int fa[100005];
int findp(int x){return fa[x]==x?x:fa[x]=findp(fa[x]);}

void task7(){
    for(int i=1;i<=n;i++)fa[i]=i;
    q=read();
    for(int i=0;i<m;i++){
        int u=read(),v=read();
        fa[findp(u)]=findp(v);
    }
    while(q--){
        int u=read(),v=read();
        if(findp(u)==findp(v))write(0),putchar('\n');
        else writeln(2139062143);
    }
}

const int N=100005;
int head[N],nxt[N*2],to[N*2],w[N*2],en;
int dep[N],up[N][17],mx[N][17];
void add(int u,int v,int z){nxt[++en]=head[u];head[u]=en;to[en]=v;w[en]=z;}
void bfs(int s){
    queue<int> qq;
    dep[s]=1;qq.push(s);
    while(!qq.empty()){
        int u=qq.front();qq.pop();
        for(int i=head[u];i;i=nxt[i]){
            int v=to[i];
            if(!dep[v]){
                dep[v]=dep[u]+1;
                up[v][0]=u; mx[v][0]=w[i];
                for(int j=1;j<17;j++){
                    up[v][j]=up[up[v][j-1]][j-1];
                    mx[v][j]=max(mx[v][j-1],mx[up[v][j-1]][j-1]);
                }
                qq.push(v);
            }
        }
    }
}

int query(int u,int v){
    int r=0;
    if(dep[u]<dep[v])swap(u,v);
    for(int i=16;i>=0;i--)
        if(dep[up[u][i]]>=dep[v]){
            r=max(r,mx[u][i]);
            u=up[u][i];
        }
    if(u==v)return r;
    for(int i=16;i>=0;i--){
        if(up[u][i]!=up[v][i]){
            r=max(r,max(mx[u][i],mx[v][i]));
            u=up[u][i];v=up[v][i];
        }
    }
    return max(r,max(mx[u][0],mx[v][0]));
}

void task8(){
    q=read();
    while(m--){
        int u=read(),v=read(),z=read();
        add(u,v,z); add(v,u,z);
    }
    bfs(1);
    while(q--){
        int u=read(),v=read();
        writeln(query(u,v));
    }
}

struct E{int u,v,z;};
vector<E> es;
void task9(){
    m=read(); q=read();
    for(int i=1;i<=m;i++){
        int u=read(),v=read(),z=read();
        es.push_back({u,v,z});
    }
    sort(es.begin(),es.end(),[](E&a,E&b){return a.z<b.z;});
    for(int i=1;i<=n;i++)fa[i]=i;
    for(auto &e:es){
        int u=findp(e.u),v=findp(e.v);
        if(u!=v){
            fa[u]=v;
            add(e.u,e.v,e.z); add(e.v,e.u,e.z);
        }
    }
    for(int i=1;i<=n;i++)if(!dep[i])bfs(i);
    while(q--){
        int u=read(),v=read();
        if(findp(u)!=findp(v))writeln(2139062143);
        else writeln(query(u,v));
    }
}

void task10(){
    puts("Your program should output itself here.");
    puts("Sounds very difficult, yeah?");
    puts("Anyway, good luck!");
}

int main(){
    n=read();
    if(n==22)T1::go();
    else if(n==33)T2::go();
    else if(n==12)T3::go();
    else if(n==131072)T4::go();
    else if(n==262144)T5::go();
    else if(n==531441)T6::go();
    else if(n==100000) {
        m = read();
        if(m == n) task7();
        else task8();
    }
    else if(n==50000)task9();
    else if(n==100)task10();
    return 0;
}