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
int main(){
    // freopen("stone.in", "r", stdin);
    // freopen("stone.out", "w", stdout);
    int n = read();
    int m = read();
    vector<int>a(n+1);
    for(int i=1;i<=n;i++) a[i]=read();
    vector<vector<int>> g(n+1);
    vector<int> indeg(n+1);
    for(int i=0;i<m;i++){
        int u=read(), v=read();
        g[u].push_back(v);
        indeg[v]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++) if(indeg[i]==0) q.push(i);
    vector<int> topo;
    while(!q.empty()){
        int u=q.front();q.pop();
        topo.push_back(u);
        for(int v:g[u]) if(--indeg[v]==0) q.push(v);
    }
    const int L = 60;
    vector<vector<int>> dp(n+1);
    for(int i=(int)topo.size()-1;i>=0;i--){
        int u=topo[i];
        vector<int> tmp;
        tmp.push_back(a[u]);
        for(int v:g[u]){
            for(int x:dp[v]) tmp.push_back(x);
        }
        sort(tmp.begin(), tmp.end(), greater<int>());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        if((int)tmp.size()>L) tmp.resize(L);
        dp[u]=move(tmp);
    }
    for(int i=1;i<=n;i++){
        int ans=-1;
        auto &v=dp[i];
        int sz=v.size();
        for(int x=0;x<sz;x++){
            for(int y=x+1;y<sz;y++){
                int t = v[x] & v[y];
                if(t>ans) ans=t;
            }
        }
        if(i>1) putchar(' ');
        write(ans);
    }
    putchar('\n');
    return 0;
}
