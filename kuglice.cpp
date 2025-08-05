#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 3e5 + 5;
int n, q;
int to[MAXN];
bool vis[MAXN];

int find_end(int x) {
    memset(vis, 0, sizeof(vis));
    int cur = x;
    while (to[cur]) {
        if (vis[cur]) return -1;  // 发现循环
        vis[cur] = true;
        vis[cur] = 
        cur = to[cur];
    }
    return cur;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> to[i];
    }
    
    cin >> q;
    while (q--) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            int res = find_end(x);
            if (res == -1) cout << "CIKLUS\n";
            else cout << res << "\n";
        } else {
            to[x] = 0;  // 删除出边
        }
    }
    cin >> std;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
