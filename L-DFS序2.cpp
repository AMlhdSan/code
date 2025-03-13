#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1000010;
const int MSEG = N << 2;

int n, m, r;
int w[N];                   // 每个结点的权值
int tin[N], tout[N], subsize[N], euler[N];
int timer = 0;

vector<int> adj[N];         // 邻接表存储树

// 线段树以及 lazy 标记
int seg[MSEG], lazy[MSEG];

// DFS 生成欧拉序，记录 tin, tout 以及子树大小 subsize
void dfs(int u, int parent) {
    tin[u] = ++timer;
    euler[timer] = w[u];
    subsize[u] = 1;
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u);
        subsize[u] += subsize[v];
    }
    tout[u] = timer;
}

// 构造线段树
void buildSeg(int p, int l, int r) {
    if (l == r) {
        seg[p] = euler[l];
        lazy[p] = 0;
        return;
    }
    int mid = (l + r) / 2;
    buildSeg(p << 1, l, mid);
    buildSeg(p << 1 | 1, mid + 1, r);
    seg[p] = seg[p << 1] + seg[p << 1 | 1];
    lazy[p] = 0;
}

// 下传 lazy 标记
void pushDown(int p, int l, int r) {
    if (lazy[p] == 0) return;
    int mid = (l + r) / 2;
    seg[p << 1] += lazy[p] * (mid - l + 1);
    seg[p << 1 | 1] += lazy[p] * (r - mid);
    lazy[p << 1] += lazy[p];
    lazy[p << 1 | 1] += lazy[p];
    lazy[p] = 0;
}

// 区间更新：区间 [ql, qr] 加上 val
void updateSeg(int p, int l, int r, int ql, int qr, int val) {
    if (ql <= l && r <= qr) {
        seg[p] += val * (r - l + 1);
        lazy[p] += val;
        return;
    }
    pushDown(p, l, r);
    int mid = (l + r) / 2;
    if (ql <= mid) updateSeg(p << 1, l, mid, ql, qr, val);
    if (qr > mid) updateSeg(p << 1 | 1, mid + 1, r, ql, qr, val);
    seg[p] = seg[p << 1] + seg[p << 1 | 1];
}

// 区间查询：区间 [ql, qr] 的和
int querySeg(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return seg[p];
    }
    pushDown(p, l, r);
    int mid = (l + r) / 2, sum = 0;
    if (ql <= mid) sum += querySeg(p << 1, l, mid, ql, qr);
    if (qr > mid) sum += querySeg(p << 1 | 1, mid + 1, r, ql, qr);
    return sum;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        // 无向树
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(r, 0);
    buildSeg(1, 1, n);
    
    while(m--){
        int op;
        cin >> op;
        if(op == 1){
            int a, x;
            cin >> a >> x;
            // 更新结点 a 的子树：区间 [tin[a], tin[a] + subsize[a] - 1]
            updateSeg(1, 1, n, tin[a], tin[a] + subsize[a] - 1, x);
        }
        else{ // op == 2
            int a;
            cin >> a;
            cout << querySeg(1, 1, n, tin[a], tin[a] + subsize[a] - 1) << "\n";
        }
    }
    
    return 0;
}