#include <bits/stdc++.h>

using namespace std;

using i32 = int;
using i64 = long long;

using vi = vector<int>;
using pii = pair<int, int>;
// using namespace std;
using namespace __gnu_pbds; 
using namespace __gnu_cxx;

i32 main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    int N = n * 2;
    vector<vi> e(N + 1);
    vi vis(N + 1), dis(N + 1), deg(N + 1);

    for (int i = 1, x; i <= n; i++)
        cin >> x, e[i].push_back(x), deg[x]++;

    queue<int> q;

    for (int i = 1; i <= N; i++)
        if (deg[i] == 0)
            q.push(i);

    while (not q.empty()) {
        int x = q.front();
        vis[x] = 1;
        q.pop();

        for (auto y : e[x]) {
            dis[y] = max(dis[x], dis[x] + 1);

            if (--deg[y] == 0)
                q.push(y);
                // q.push(y.back());
                // e[y].pop_back();
                // e[y].push_back(x);
                // deg[x]--;
                // if (deg[x] == 0)
                //     q.push(x);
                // e[x].push_back(y);
                // deg[y]--;
                // if (deg[y] == 0)
                //     q.push(y);
                // e[y].push_back(x);
                // deg[x]++;    
                // if (deg[x] == 0)
                //     q.push(x);
                // e[x].push_back(y);
                // deg[y]++;
                // if (deg[y] == 0)
                //     q.push(y);
                // e[y].push_back(x);
        }
    }

    int res = 0;

    for (int i = 1; i <= N; i++) {
        if (vis[i] == 0)
            res++;

        if (e[i].empty())
            res += dis[i];
    }

    cout << res;

    return 0;
}
