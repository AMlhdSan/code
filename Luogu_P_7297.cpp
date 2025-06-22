#include <bits/stdc++.h>
#define N 50010
#define inf 1e9
using namespace std;

int n, k, b[N], dis[N];
char s[55][55];
vector<int> pos[55];
bool vis[N];

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

int main() {
    n = read(), k = read();
    for (int i = 1; i <= n; ++i) {
        b[i] = read();
        pos[b[i]].push_back(i);
        dis[i] = inf;
    }
    for (int i = 1; i <= k; ++i) scanf("%s", s[i] + 1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    dis[1] = 0;
    q.push({0, 1});

    while (!q.empty()) {
        int d = q.top().first, u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        int t = b[u];
        for (int j = 1; j <= k; ++j) {
            if (s[t][j] == '1') {
                for (int v : pos[j]) {
                    if (!vis[v] && dis[v] > d + abs(u - v)) {
                        dis[v] = d + abs(u - v);
                        q.push({dis[v], v});
                    }
                }
            }
        }
    }

    if (dis[n] == inf) writeln(-1);
    else writeln(dis[n]);
    return 0;
}
