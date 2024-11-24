#include <bits/stdc++.h>

#define N 100010

using namespace std;

struct node {
    int v;
    int t;
    int index;
    int id;
};

struct node1 {
    int v;
    int c;
};

int n, r, s, x;
int e[N], c[N];
int tv[N], tl[N];
int t[N];
node tmp;

vector<node> edges[N];
vector<node1> edges_0[100001];
priority_queue<pair<int, int> > q1;
int dis1[100001];
bool vis1[100001];

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

inline void write(int x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

void add_edge1(int u, int v, int t) {
    tmp.index = 1;
    tmp.id = 0;
    tmp.v = v;
    tmp.t = t;
    edges[u].push_back(tmp);

    tmp.index = 1;
    tmp.id = 0;
    tmp.v = u;
    tmp.t = t;
    edges[v].push_back(tmp);
}

void add_edge2(int u, int v, int t, int id) {
    tmp.index = 2;
    tmp.id = id;
    tmp.t = t;
    tmp.v = v;
    edges[u].push_back(tmp);

    tmp.index = 2;
    tmp.id = id;
    tmp.t = t;
    tmp.v = u;
    edges[v].push_back(tmp);
}

void add_edge(int u, int v, int w) {
    node1 tmp1;
    tmp1.v = v;
    tmp1.c = w;
    edges_0[u].push_back(tmp1);
}

void dijkstra() {
    memset(dis1, 0x3f, sizeof(dis1));
    memset(vis1, false, sizeof(vis1));
    dis1[1] = 0;
    q1.push(make_pair(0, 1));
    while(1) {
        if(q1.empty()) 
            return;
        int u = q1.top().second;
        q1.pop();
        if(vis1[u])
            continue;
        vis1[u] = true;
        for(node1 e : edges_0[u]) {
			int v = e.v;
			if (dis1[v] > dis1[u] + e.c) {
				dis1[v] = dis1[u] + e.c;
				q1.push(make_pair(-dis1[v], v));
			}
		}
    }
}

int main() {

    // freopen("capital.in", "r", stdin);
    // freopen("capital.out", "w", stdout);

    cin >> n >> r >> s >> x;

    if(s == 0) {
        for(int i = 1; i <= n; ++i) {
            e[i] = read();
        }
        for(int i = 1; i <= n; ++i) {
            c[i] = read();
        }
        for(int i = 1; i <= r; ++i) {
            int a, b, t;
            a = read();
            b = read();
            t = read();
            add_edge(a, b, t);
            add_edge(b, a, t);
        }
        dijkstra();
        write(0);
        putchar('\n');
        for(int i = 2; i <= n; ++i) {
            write(dis1[i] + x);
            putchar('\n');
        }
        return 0;
    }

    for(int i = 1; i <= n; ++i) {
        e[i] = read();
    }
    
    for(int i = 1; i <= n; ++i) {
        c[i] = read();
    }

    for(int i = 1; i <= r; ++i) {
        int a, b, t;
        a = read();
        b = read();
        t = read();
        add_edge1(a, b, t);
    }

    for(int i = 1; i <= s; ++i) {
        int k;
        k = read();
        for(int j = 1; j <= k; ++j) {
            tv[j] = read();
            tl[j] = read();
        }
        tv[k + 1] = read();
        for(int i = 1; i <= k; ++i) {
            add_edge2(tv[i], tv[i + 1], tl[i], i);
        }
        t[i] = read();
    }

    return 0;
}