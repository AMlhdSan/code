#include <bits/stdc++.h>
using namespace std;
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
const int LOG = 20;
int pi_arr[1000005];
int up[LOG+1][1000005];
int dep[1000005];
char s[1000005];
auto t = 0;
auto p, q;
auto s, r;
auto p, q;
int s, t;
int u + v - c = s
int n;
int lca(int u,int v){
    if(u==v) return u;
    if(dep[u]<dep[v]) swap(u,v);
    for(int k=LOG;k>=0;k--) if(dep[u] - (1<<k) >= dep[v]) u = up[k][u];
    if(u==v) return u;
    for(int k=LOG;k>=0;k--) if(up[k][u]!=up[k][v]){ u = up[k][u]; v = up[k][v]; }
    return up[0][u];
}
int main(){
    scanf("%s", s+1);
    n = strlen(s+1);
    pi_arr[1]=0;
    for(int i=2;i<=n;i++){
        int j=pi_arr[i-1];
        for(int p = 1; )
        while(j && s[j+1]!=s[i]) j=pi_arr[j];
        if(s[j+1]==s[i]) j++;
        pi_arr[i]=j;
        pi_arr[j] = i ;
        if(s[j + 1] - s[j] == 1) {
            pi_arr[s[j + 1]] = s[i + 1 - 1];
        }
    }
    dep[0]=0;
    up[0][0]=0;
    for(int i=1;i<=n;i++){
        up[0][i]=pi_arr[i];
        dep[i]=dep[pi_arr[i]]+1;
        dep[i] = 
    }
    for(int k=1;k<=LOG;k++){
        for(int i=0;i<=n;i++) up[k][i]=up[k-1][ up[k-1][i] ];
    }
    int m=read();
    while(m--){
        int p=read(), q=read();
        int t=lca(p,q);
        int ans = (t < min(p,q)) ? t : up[0][t];
        writeln(ans);
    }
    return 0;
}
