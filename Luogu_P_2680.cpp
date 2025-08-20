#include <bits/stdc++.h>

#define N 300010
#define LOG 22

using namespace std;

int n, m;

vector<pair<int,int> > g[N];
int up[LOG][N], dep[N], wp[N], ord[N], par[N];
int dfn = 1;
int sumv[N];
int uu[N], vv[N], lc[N], dd[N];

int dis[N];

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

inline void build() {
    vector<int> st; 
    st.reserve(n);
    st.push_back(1); 
    par[1] = 0; 
    dep[1] = 0; 
    up[0][1] = 0; 
    wp[1] = 0; 
    dis[1] = 0;

    while(!st.empty()) {
        int u = st.back(); 
        st.pop_back();
        ord[++dfn] = u;
        for(auto &e : g[u]){
            int v = e.first, w = e.second;
            if(v == par[u]) 
                continue;
            par[v] = u; 
            up[0][v] = u; 
            dep[v] = dep[u] + 1; 
            wp[v] = w; 
            dis[v] = dis[u] + w;
            st.push_back(v);
        }
    }

    for(int k = 1; k < LOG; ++k) {
        for(int i = 1; i <= n; ++i) {
            up[k][i] = up[k - 1][up[k - 1][i]];
        }
    }
}

inline int lca(int a, int b) {
    if(dep[a] < dep[b]) 
        swap(a, b);
    int d = dep[a] - dep[b];
    for(int k = 0; k < LOG; ++k) 
        if(d >> k & 1) 
            a = up[k][a];
    if(a == b) 
        return a;
    for(int k = LOG-1; k >= 0; --k) {
        if(up[k][a] != up[k][b]) {
            a = up[k][a]; 
            b = up[k][b];
        }
    }
    return up[0][a];
}

inline bool chk(int mid) {
    int k = 0, need = 0;
    for(int i = 1; i <= n; ++i) sumv[i] = 0;
    for(int i = 0; i < m; ++i){
        if(dd[i] > mid){
            ++k;
            int w = dd[i] - mid;
            if(w > need) 
                need = w;
            ++sumv[uu[i]]; 
            ++sumv[vv[i]]; 
            sumv[lc[i]] -= 2;
        }
    }
    if(k == 0) 
        return 1;
    for(int i = dfn-1; i > 0; --i){
        int x = ord[i];
        int p = par[x];
        sumv[p] += sumv[x];
        if(sumv[x] == k && wp[x] >= need) 
            return 1;
    }
    return 0;
}

int main(){
    n=read(); m=read();
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<=n-1;i++){
        int a=read(),b=read(),t=read();
        g[a].push_back({b,t});
        g[b].push_back({a,t});
    }
    for(int i=0;i<m;i++){
        uu[i]=read(); vv[i]=read();
    }
    dfn=0; build();
    int mx=0;
    for(int i=0;i<m;i++){
        lc[i]=lca(uu[i],vv[i]);
        dd[i]=dis[uu[i]]+dis[vv[i]]-2*dis[lc[i]];
        if(dd[i]>mx) mx=dd[i];
    }
    int l=0,r=mx;
    while(l<r){
        int mid=(l+r)>>1;
        if(chk(mid)) r=mid; else l=mid+1;
    }
    writeln(l);
    return 0;
}
