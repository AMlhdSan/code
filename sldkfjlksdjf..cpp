#include <cstdio>
#include <unordered_map>
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
inline void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
inline void writeln(int x){
    write(x);
    putchar('\n');
}
void dfs(int x,int c,unordered_map<int,int>& mp){
    if(!mp.count(x)||mp[x]>c) mp[x]=c;
    if(x==1)return;
    if(x%2==0) dfs(x/2,c+1,mp);
    else{
        dfs(x/2,c+1,mp);
        dfs((x+1)/2,c+1,mp);
    }
}
int main(){
    // freopen("bread.in", "r", stdin);
    // freopen("bread.out", "w", stdout);
    int n=read();
    unordered_map<int, pair<int,int>> g;
    for(int i=0;i<n;i++){
        int a=read();
        unordered_map<int,int> mp;
        dfs(a,0,mp);
        for(auto &p:mp){
            int v=p.first, c=p.second;
            if(!g.count(v)) g[v]={c,1};
            else {g[v].first+=c; g[v].second++;}
        }
    }
    int ansv=0, ansc=0;
    for(auto &p:g){
        if(p.second.second==n){
            int v=p.first, cost=p.second.first;
            if(v>ansv||(v==ansv&&cost<ansc)){
                ansv=v; ansc=cost;
            }
        }
    }
    write(ansc); putchar(' '); writeln(ansv);
    return 0;
}
