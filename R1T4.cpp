#include <bits/stdc++.h>

#define N 1010

using namespace std;

struct node {
    int st, ed, len;
};

int a[N + 1];
int n;
vector<node> v;

int main() {
    freopen("bigwin.in", "r", stdin);
    freopen("bigwin.out", "w", stdout);
    
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; ++i) {
        int sum = 0;
        for(int j = i; j <= n; ++j) {
            sum += a[j];
            if (sum >= 0) {
                v.push_back({i, j, j - i + 1});
            }
        }
    }

    int maxx = 0;

    int cnt = v.size();
    for (int mk = 0; mk < (1 << cnt); ++mk) {
        bool flg = true;
        int nw = 0;

        bool vis[N + 1];
        memset(vis, false, sizeof(vis));

        for (int i = 0; i < cnt; ++i) {
            if (mk & (1 << i)) {
                const node &seg = v[i];
                for (int k = seg.st; k <= seg.ed; ++k) {
                    if (vis[k]) {
                        flg = false;
                        break;
                    }
                }
                if (!flg) break;

                for (int k = seg.st; k <= seg.ed; ++k) {
                    vis[k] = true;
                }
                nw += seg.len;
            }
        }

        if(flg) {
            maxx = max(maxx, nw);
        }
    }

    cout << maxx << endl;
    
    return 0;
}
