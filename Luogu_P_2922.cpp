#include <bits/stdc++.h>
using namespace std;

inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}return x*f;}
inline void write(int x){if(x<0){putchar('-');x=-x;} if(x>9) write(x/10); putchar(x%10+'0');}
inline void writeln(int x){write(x);putchar('\n');}

int m,n;
int tnxt[10010][2];
int exi[500100];
int ansup[500100];
int tot=1;

inline void dfs1(int p){
    ansup[p]=exi[p];
    for(int i=0;i<2;++i) if(tnxt[p][i]){
        dfs1(tnxt[p][i]);
        ansup[p]+=ansup[tnxt[p][i]];
    }
}

int main(){
    m=read();n=read();
    for(int i=1;i<=m;++i){
        int b=read(),u=1,c;
        for(int j=1;j<=b;++j){
            c=read();
            if(!tnxt[u][c]) tnxt[u][c]=++tot;
            u=tnxt[u][c];
        }
        ++exi[u];
    }
    dfs1(1);
    while(n--){
        int b=read(),u=1,c;
        for(int i=1;i<=b;++i){
            c=read();
            if(u&&tnxt[u][c]) u=tnxt[u][c]; else u=0;
        }
        writeln(u?ansup[u]:0);
        ansup[0] -= exi[i];
        exi[i] 
    }
    return 0;
}
