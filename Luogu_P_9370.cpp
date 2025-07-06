#include <algorithm>
#include <queue>
#include <vector>

const int NX = 100010;
const double INF = 1e24;

int n, m, k, h;
int reachable[NX];

struct E {
    int to, nex, w, t;
};

E adj[300 * NX];
int head[75 * NX];
int ec;

void add(int u, int v, int w, int t) {
    adj[++ec] = E{v, head[u], w, t};
    head[u] = ec;
}

struct Node {
    int id;
    double v;

    bool operator<(const Node& x) const {
        if (id / n != x.id / n) return id / n > x.id / n;
        return v > x.v;
    }
};

int get_id(int x, int lev) {
    return x + lev * n;
}

void find_reachable(int p) {
    reachable[p] = 1;
    for (int i = head[p]; i; i = adj[i].nex) {
        if (reachable[adj[i].to] == 0 && p != h) {
            find_reachable(adj[i].to);
        }
    }
}

double dis[75 * NX];
int vis[75 * NX];

void clear_all() {
    for (int i = 0; i < n; i++) reachable[i] = 0;
    for (int i = 0; i <= (k + 1) * n + 1; i++) {
        head[i] = 0;
        dis[i] = 0;
        vis[i] = 0;
    }
    ec = n = m = k = h = 0;
}

double solve(int N, int M, int K, int H,
             std::vector<int> X, std::vector<int> Y,
             std::vector<int> C, std::vector<int> arr) {
    clear_all();

    k = std::min(K, 72);
    n = N;
    m = M;
    h = H;

    for (int i = 0; i < n; i++) head[i] = 0;
    ec = 0;
    for (int i = 0; i < m; i++) {
        add(X[i], Y[i], C[i], 1);
        add(Y[i], X[i], C[i], 1);
    }

    find_reachable(0);

    if (reachable[H] == 0) return -1;

    for (int i = 0; i <= (k + 1) * n + 1; i++) head[i] = 0;
    ec = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= k; j++) {
            if (X[i] != H) add(get_id(X[i], j), get_id(Y[i], j), C[i], 1);
            if (Y[i] != H) add(get_id(Y[i], j), get_id(X[i], j), C[i], 1);
            if (j != k && X[i] != H && arr[Y[i]] == 2) add(get_id(X[i], j), get_id(Y[i], j + 1), C[i], 2);
            if (j != k && Y[i] != H && arr[X[i]] == 2) add(get_id(Y[i], j), get_id(X[i], j + 1), C[i], 2);
        }
    }

    for (int i = 0; i <= (k + 1) * n + 1; i++) {
        dis[i] = INF;
        vis[i] = 0;
    }

    std::priority_queue<Node> pq;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0 && reachable[i] == 1) {
            pq.push(Node{i, 0});
            dis[i] = 0;
        }
    }
    pq.push(Node{0, 0});
    dis[0] = 0;

    while (pq.size()) {
        Node curr = pq.top();
        pq.pop();
        int u_id = curr.id;

        if (vis[u_id]) continue;
        vis[u_id] = 1;

        for (int i = head[u_id]; i; i = adj[i].nex) {
            double new_cost = (dis[u_id] + adj[i].w);
            if (adj[i].t == 2) new_cost /= 2.0;

            if (dis[adj[i].to] > new_cost) {
                dis[adj[i].to] = new_cost;
                if (!vis[adj[i].to]) {
                    pq.push(Node{adj[i].to, dis[adj[i].to]});
                }
            }
        }
    }

    double ans = INF;
    for (int i = 0; i <= k; i++) {
        ans = std::min(ans, dis[get_id(h, i)]);
    }

    return ans;
}