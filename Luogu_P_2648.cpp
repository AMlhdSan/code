#include <bits/stdc++.h>

#define N 10001

using namespace std;

int d, p, c, f;
int s = 0;

int head[N], nxt[N], to[N], w[N];
int dis[N];
int cnt = 0;
bool vis[N];
int pd[N];

void add(int u, int v, int c) {
    nxt[++cnt] = head[u];
    head[u] = cnt;
    w[cnt] = c;
    to[cnt] = v;
}

bool spfa() {
    memset(dis, 0x3f, sizeof(dis));
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    dis[s] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        ++pd[u];
        if(pd[u] > c) {
            return 1;
        }
        for(int i = head[u]; i; i = nxt[i]) {
            int v = to[i];
            if(dis[v] > dis[u] + w[i]) {
                dis[v] = dis[u] + w[i];
                if(!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return 0;
}

int main() {

    cin >> d >> p >> c >> f;

    for(int i = 1; i <= p; ++i) {
        int u, v;
        cin >> u >> v;
        add(u, v, -d);
    }

    for(int i = 1; i <= f; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        add(u, v, c - d);
    }
    for(int i = 1; i <= c; ++i) {
        add(s, i, -d);
    }

    if(spfa()) {
        cout << "orz" << endl;
        return 0;
    }

    int maxx = 0x7fffffff;

    for(int i = 1; i <= c; ++i) {
        maxx = min(maxx, dis[i]);
    }

    cout << -maxx << endl;

    return 0;
}