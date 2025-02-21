#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
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
    if(x<0){putchar('-'); x=-x;}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
inline void writeln(int x){
    write(x);
    putchar('\n');
}
int main(){
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    int n = read(), m = read();
    vector<vector<pair<int,int>>> g(n+1);
    for(int i=0;i<m;i++){
        int u = read(), v = read(), w = read();
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    vector<int> d(n+1), t(n+1);
    for(int i=1;i<=n;i++){
        d[i] = read();
    }
    for(int i=1;i<=n;i++){
        t[i] = read();
    }
    vector<long long> f(n+1, INF);
    f[1] = 0;
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto [cur, u] = pq.top();
        pq.pop();
        if(cur != f[u]) continue;
        int R = d[u];
        int cost = t[u];
        vector<long long> dist(n+1, INF);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> qp;
        dist[u] = 0;
        qp.push({0,u});
        while(!qp.empty()){
            auto [du, v] = qp.top();
            qp.pop();
            if(du != dist[v]) continue;
            if(du > R) break;
            if(f[v] > f[u] + cost){
                f[v] = f[u] + cost;
                pq.push({f[v], v});
            }
            for(auto &edge : g[v]){
                int w = edge.first, ww = edge.second;
                if(du + ww <= R && du + ww < dist[w]){
                    dist[w] = du + ww;
                    qp.push({dist[w], w});
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(f[i]==INF) write(-1);
        else {
            int x = (int)f[i];
            write(x);
        }
        if(i<n) putchar(' ');
    }
    return 0;
}
