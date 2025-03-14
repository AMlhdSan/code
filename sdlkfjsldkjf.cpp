#include <bits/stdc++.h>

#define N 1000010 
#define ll long long
#define int long long
#define pll pair<ll, ll>

using namespace std;

ll n, m, r;
ll v[N];

struct qry { 
    ll op, a, b; 
} q[N];

ll lca[N];

namespace LCA {
    ll cnt;
    ll rt[N];
    ll lv[N];
    ll dfn[N];
    ll dep[N];
    ll vis[N];
    vector<ll> G[N];
    vector<pll> mt[N];

    namespace DSU {
        ll rt[N];
        
        void init(ll n) { 
            for (ll i = 1; i <= n; i++) { 
                rt[i] = i; 
            } 
        }
        
        ll find(ll x) { 
            if (rt[x] == x) return x; 
            return rt[x] = find(rt[x]); 
        }
        
        void mount(ll u, ll v) { 
            rt[u] = v; 
        } 
    }
    
    using namespace DSU;
    
    void dfs(ll u) { 
        dfn[u] = ++cnt; 
        vis[u] = 1; 
        
        for (auto i : mt[u]) 
            if (vis[i.first]) 
                lca[i.second] = find(i.first); 
                
        for (auto v : G[u]) 
            if (v != LCA::rt[u]) { 
                LCA::rt[v] = u; 
                dep[v] = dep[u] + 1; 
                dfs(v); 
                mount(v, u); 
            } 
            
        lv[u] = cnt; 
    }
    
    void build(ll s = 1) { 
        DSU::init(n); 
        dfs(s); 
    } 
}

using namespace LCA;

class TreeArr {
private:
    ll C[N];
    
    inline ll lowbit(ll k) { 
        return k & -k; 
    }
    
    void add(ll idx, ll c) { 
        for (ll i = idx; i <= n; i += lowbit(i)) 
            C[i] += c; 
    }
    
public:
    void add(ll l, ll r, ll c) { 
        add(l, c); 
        add(r + 1, -c); 
    }
    
    ll sum(ll idx) { 
        ll ans = 0; 
        for (ll i = idx; i; i -= lowbit(i)) 
            ans += C[i]; 
        return ans; 
    } 
} v1, v2;

inline ll dist(ll u) { 
    if (!u) return 0; 
    return v1.sum(dfn[u]) + v2.sum(dfn[u]) * dep[u]; 
}

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

signed main() {
    n = read();
    m = read();
    r = read();
    
    for (ll i = 1; i <= n; i++) 
        v[i] = read();
    
    for (ll u, v, i = 1; i < n; i++) {
        u = read();
        v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    for (ll i = 1; i <= m; i++) {
        q[i].op = read();
        q[i].a = read();
        q[i].b = read();
        
        if (q[i].op == 3) {
            mt[q[i].a].push_back({q[i].b, i});
            mt[q[i].b].push_back({q[i].a, i});
        }
    }
    
    build(r);
    
    for (ll i = 1; i <= n; i++) 
        v1.add(dfn[i], lv[i], v[i]);
    
    for (ll i = 1; i <= m; i++) {
        ll u = q[i].a;
        ll v = q[i].b;
        
        if (q[i].op == 1) 
            v1.add(dfn[u], lv[u], v);
        else if (q[i].op == 2) {
            v1.add(dfn[u], lv[u], v * (1 - dep[u]));
            v2.add(dfn[u], lv[u], v);
        }
        else {
            printf("%lld\n", dist(u) + dist(v) - dist(lca[i]) - dist(LCA::rt[lca[i]]));
        }
    }
    
    return 0;
}