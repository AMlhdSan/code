#include <bits/stdc++.h>

#define N 1510

using namespace std;

int n;
vector<int> edges[N];
int dp[N][2]; // dp[i][0] 表示以 i 为子树的节点中没有选择 i 的最少个数
              // dp[i][1] 表示以 i 为子树的节点中选择了 i 的最少个数
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

inline void init() {
    for(int i = 1; i <= n; ++i) {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
}

inline void dfs(int p, int fa) {
    vis[p] = 1;
    dp[p][0] = 0;
    dp[p][1] = 1;
    for(int v : edges[p]) {
        if(v != fa && !vis[v]) {
            dfs(v, p);
            dp[p][0] += dp[v][1];
            dp[p][1] += min(dp[v][0], dp[v][1]);
        }
    }
}

int main() {

    n = read();

    // init();

    for(int i = 1; i <= n; ++i) {
        int p, k, tmp;
        p = read();
        k = read();
        for(int i = 1; i <= k; ++i) {
            tmp = read();
            edges[p].push_back(tmp);
            edges[tmp].push_back(p);
        }
    }

    dfs(0, -1);

    cout << min(dp[0][0], dp[0][1]);

    return 0;
}