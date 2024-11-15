#include <bits/stdc++.h>

#define M 200010

using namespace std;

int n, m, s;
int nxt[M], head[M], to[M], w[M];
int cnt = 0;
int dis[M];

void add(int u, int v, int c) {
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
    w[cnt] = c;
}

void bellman_ford() {
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    bool flag = 0;
    for(int i = 1; i <= n; ++i) {
        flag = 0;
        for(int u = 1; u <= n; ++u) {
            for(int j = head[u]; j; j = nxt[j]) { 
                int v = to[j];
                if (dis[v] > dis[u] + w[j]) { 
                    dis[v] = dis[u] + w[j];
                    flag = true;
                } 
            }
        }
        if(!flag) {
            break;
        }
    }
}

int main() {

    cin >> n >> m >> s;
    while(m--) {
        int u, v, c;
        cin >> u >> v >> c;
        add(u, v, c);
    }

    bellman_ford();

    for(int i = 1; i <= n; ++i)
		cout << (dis[i] == 0x3f3f3f3f ? 2147483647 : dis[i]) << ' ';
    cout << endl;

    return 0;
}