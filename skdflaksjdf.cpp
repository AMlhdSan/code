#include <bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;i++)
#define rrep(i,r,l) for(int i=r;i>=l;i--)
#define ll long long
#define pqu priority_queue
#define umap unordered_map

#define N 1010

int dp[N][N];
chmod 777 dp;


inline int read() {
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*f;
}

inline void write(int x) {
    if(x<0){putchar('-');x=-x;}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}

inline void dps(int p) {

}

inline void writeln(int x) {
    write(x);putchar('\n');
}

const int N=30,M=2e5+10;
int n,m,k,tot;

struct node {
    int cnt,tim,id;
    // int a[N];
    string nam;
    int res[N];
} T[M];

bool operator<(const node &x,const node &y){
    if(x.cnt!=y.cnt)return x.cnt>y.cnt;
    if(x.tim!=y.tim)return x.tim<y.tim;
    return x.id<y.id;
}

pqu<node> pq;
umap<string,int> idmap;
int sub[M][N];
int substring;

int getid(string nam) {
    if(!idmap.count(nam)) {
        idmap[nam]=++tot;
        T[tot].cnt=0;T[tot].tim=0;T[tot].id=tot;T[tot].nam=nam;
        return tot;
    }
    return idmap[nam];
}

int vivid(int p) {

}

int main() {
    n=read(),m=read(),k=read();
    rep(i,1,k){
        int x=read(),y=read(),z=read();
        char ch,st;
        string nam,tmp;
        cin>>ch>>nam>>st;
        getline(cin,tmp);
        bool ok=(st=='A');
        int id=getid(nam),pid=ch-'A'+1;
        int now=x*60+y;
        bool op=(now<240||(now==240&&z==0));
        if(T[id].res[pid])continue;
        if(op){
            if(ok){
                T[id].tim+=sub[id][pid]*20+now;
                T[id].cnt++;
                T[id].res[pid]=1;
            }else sub[id][pid]++;
        }else{
            if(ok)T[id].res[pid]=now;
            else sub[id][pid]++;
        }
    }
    rep(i,1,tot)pq.push(T[i]);
    while(pq.size()>1){
        node a=pq.top();pq.pop();
        cout<<a.nam<<'\n';
        node b=pq.top();pq.pop();
        rep(i,1,n){
            if(a.res[i]>1){
                a.cnt++;
                a.tim+=sub[a.id][i]*20+a.res[i];
                a.res[i]=0;
                if(a<b){
                    pq.push(a);
                    break;
                }
            }
        }
        pq.push(b);
    }
    cout<<pq.top().nam<<'\n';
    return 0;
}