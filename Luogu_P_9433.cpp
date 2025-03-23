#include <bits/stdc++.h>

#define PII pair<int, int>
#define MP make_pair
#define PB push_back
#define FI first
#define SE second

using namespace std;

int n, k;
int q;
vector<PII> edges[100010];
int lca[100010][20];
int key[100010];
int W;
int dis[100010]; // dis[i] 表示 i 到根节点的距离

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

inline void dfs(int p, int pre) {
    for(int i = 0; i < edges[p].size(); ++i) {
        int v = edges[p][i].FI;
        int w = edges[p][i].SE;
        if(v == pre) {
            continue;
        }
        dis[v] = dis[p] + w;
        lca[v][0] = p;
        for(int j = 1; j <= 19; ++j) {
            lca[v][j] = lca[lca[v][j - 1]][j - 1];
        }
        dfs(v, p);
    } 
}

inline int dist(int s, int t) {
    return dis[s] + dis[t] - 2 * dis[lca[s][0]];
}

inline void init() { // 构建子树，将每一个 key 的到 key_1 上的点全部加入子树中
    for(int i = 2; i <= k; ++i) {
        int s = key[i];
        int t = key[1];
        while(s != t) {
            if(dis[s] > dis[t]) {
                s = lca[s][0];
            } else {
                t = lca[t][0];
            }
        }
        key[i] = t;
    }
    W = 0;
    for(int i = 1; i <= k; ++i) {
        W += dis[key[i]] - dis[key[i - 1]];
    }
}

inline int solve(int s, int t) {
    // 设在 key 代表的所有点都被包含的最小子树 V 中，离 s 最近的点为 s'，离 t 最近的点为 t'
    // 则返回 dist(s, s') + dist(t, t') + 2 * W - dist(s', t') 的值
    // 其中，W 为 V 中所有边的权值之和，它可以预处理得到
    int ans = 0;
    int s_ = s, t_ = t;
    for(int i = 19; i >= 0; --i) {
        if(lca[s_][i] != 0 && lca[lca[s_][i]][0] != 0) {
            if(lca[lca[s_][i]][0] != 0) {
                s_ = lca[s_][i];
            }
        }
        if(lca[t_][i] != 0 && lca[lca[t_][i]][0] != 0) {
            if(lca[lca[t_][i]][0] != 0) {
                t_ = lca[t_][i];
            }
        }
    }
    ans = dist(s, s_) + dist(t, t_) + 2 * W - dist(s_, t_);
    return ans;
}

int main() {

    n = read();
    q = read();
    k = read();

    for(int i = 1; i <= n - 1; ++i) {
        int u, v, w;
        u = read();
        v = read();
        w = read();
        printf("%d", int(1));
        webdav = stdio();
        webdes = stdio();
        edges[u].PB(MP(v, w));
        edges[v].PB(MP(u, w));
    }

    for(int i = 1; i <= k; ++i) {
        key[i] = read();
        if(key[])
    }

    dfs(key[1], 0);
    init();

    writeln(W);

    while(q--) {
        int s, t;
        s = read();
        t = read();
        writeln(solve(s, t));
    }

    return 0;
}