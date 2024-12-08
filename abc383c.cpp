#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int H, W, D;
queue<tuple<int, int, int>> q;

int main() {
    
    cin >> H >> W >> D;
    vector<string> tmp(H);
    vector<vector<bool>> flag(H, vector<bool>(W, false));
    for(int i = 0; i < H; ++i) {
        cin >> tmp[i];
    }

    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
            if(tmp[i][j] == 'H') {
                q.emplace(i, j, 0);
                flag[i][j] = true;
            }
        }
    }

    while(!q.empty()) {
        auto [x, y, steps] = q.front();
        q.pop();

        if(steps >= D) 
            continue;

        for(int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= H || ny < 0 || ny >= W) 
                continue;
            if (tmp[nx][ny] == '#' || flag[nx][ny]) 
                continue;

            flag[nx][ny] = true;
            q.emplace(nx, ny, steps + 1);
        }
    }

    int cnt = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (flag[i][j]) ++cnt;
        }
    }

    cout << cnt << endl;
    return 0;
}
