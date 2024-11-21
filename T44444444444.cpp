#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    
    // freopen("d.in", "r", stdin);
    // freopen("d.out", "w", stdout);
    
    
    cin >> n >> m;

    vector<int> a(n), b(n), c(n);
    vector<vector<int> > edges(n);

    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        edges[i].push_back(i);
        edges[a[i]].push_back(i);
        edges[i].push_back(a[i]);
    }

    for(int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    auto work = [&]() {
        c.assign(n, 0);
        for (int x = 0; x < n; ++x) {
            int d = edges[x].size();
            int base = b[x] / d;
            int tmp = b[x] - base * (d - 1);

            for (int y : edges[x]) {
                if (y == x) {
                    c[x] += tmp;
                } else {
                    c[y] += base;
                }
            }
        }
    };

    work();

    for (int i = 0; i < m; ++i) {
        int op;
        cin >> op;

        if (op == 1) {
            int x, y;
            cin >> x >> y;
            x--; y--;

            for(auto it = edges[x].begin(); it != edges[x].end(); ++it) {
                if (*it == a[x]) {
                    edges[x].erase(it);
                    break;
                }
            }
            for(auto it = edges[a[x]].begin(); it != edges[a[x]].end(); ++it) {
                if (*it == x) {
                    edges[a[x]].erase(it);
                    break;
                }
            }

            a[x] = y;
            edges[x].push_back(y);
            edges[y].push_back(x);

            work();

        } else if (op == 2) {
            int x;
            cin >> x;
            x--;
            cout << c[x] << endl;
        } 
        else if (op == 3) {
            int minn = INT_MAX, maxx = INT_MIN;
            for (int val : c) {
                minn = min(minn, val);
                maxx = max(maxx, val);
            }
            cout << minn << " " << maxx << endl;
        }
    }

    return 0;
}