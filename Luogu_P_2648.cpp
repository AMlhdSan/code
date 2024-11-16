#include <bits/stdc++.h>

#define N 10001

using namespace std;

int d, p, c, f;
int s = 0;

int head[N], nxt[N], to[N], w[N];
int cnt = 0;

void add(int u, int v, int c) {
    nxt[++cnt] = head[u];
    head[u] = cnt;
    w[cnt] = c;
    to[cnt] = v;
}

void spfa() {

}

int main() {

    cin >> d >> p >> c >> f;

    for(int i = 1; i <= p; ++i) {
        int u, v;
        cin >> u >> v;
        add(u, v, -d);
    }

    for(int i = 1; i <= p; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        add(u, v, c - d);
    }
    for(int i = 1; i <= c; ++i) {
        add(0, i, -d);
    }

    spfa();

    for(int i = 1; i <= n; )

    return 0;
}