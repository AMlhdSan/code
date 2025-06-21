#include <bits/stdc++.h>
using namespace std;
const int dx4[4] = {-1, 0, 0, 1};
const int dy4[4] = {0, -1, 1, 0};
const int dx8[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy8[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int _ = 6e6 + 10;
int n, m, k, sx, sy, tx, ty;
bool arr[_], vis[_];
inline bool check(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}
inline int id(int x, int y) {
    return (x - 1) * m + y;
}
struct node {
    int x, y, t, h;
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    cin >> sx >> sy;
    cin >> tx >> ty;
    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        for (int j = 1; j <= m; j++) {
            arr[id(i, j)] = (str[j-1] == '#');
        }
    }
    deque<node> Q(1, (node){sx, sy, 0, 0});
    while (true) {
        node N = Q.front();
        Q.pop_front();
        int x = N.x;
        int y = N.y;
        int t = N.t;
        int h = N.h;
        if (vis[id(x, y)]) continue;
        vis[id(x, y)] = true;
        if (x == tx && y == ty) {
            cout << t << endl;
            return 0;
        }
        if (h) {
            for (int d = 0; d <= 7; d++) {
                int xx = x + dx8[d];
                int yy = y + dy8[d];
                if (check(xx, yy) && !vis[id(xx, yy)]) {
                    Q.push_back((node){xx, yy, t, h-1});
                }
            }
        } else {
            for (int d = 0; d <= 3; d++) {
                int xx = x + dx4[d];
                int yy = y + dy4[d];
                if (check(xx, yy) && !vis[id(xx, yy)]) {
                    if (arr[id(xx, yy)]) {
                        Q.push_back((node){xx, yy, t+1, k-1});
                    } else {
                        Q.push_front((node){xx, yy, t, 0});
                    }
                }
            }
        }
    }
}