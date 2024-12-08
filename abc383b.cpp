#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

int H, W, D;
string tmp;
vector<pair<int, int>> t;

bool pd(int x1, int y1, int x2, int y2, int D) {
    return abs(x1 - x2) + abs(y1 - y2) <= D;
}

int main() {
    cin >> H >> W >> D;

    for (int i = 0; i < H; ++i) {
        cin >> tmp;
        for (int j = 0; j < W; ++j) {
            if (tmp[j] == '.') {
                t.emplace_back(i, j);
            }
        }
    }

    int maxx = 0;
    int n = t.size();

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            pair<int, int> p1 = t[i];
            pair<int, int> p2 = t[j];
            int x1 = p1.fi, y1 = p1.se;
            int x2 = p2.fi, y2 = p2.se;
            int count = 0;

            for (pair<int, int> p : t) {
                int x = p.fi, y = p.se;
                if (pd(x, y, x1, y1, D) || pd(x, y, x2, y2, D)) {
                    ++count;
                }
            }
            maxx = max(maxx, count);
        }
    }

    cout << maxx << endl;
    return 0;
}
