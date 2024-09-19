#include <bits/stdc++.h>
using namespace std;

int n, m;
bool t[1001][1001];
int ans[1001][1001];
int f[1001][1001][3];
bool mark[1001][1001];
int p, q;
char tttmp;

void add(int xx, int yy, int x, int y) {
    while(f[x][y][1] != x && f[x][y][2] != y) {
        x = f[x][y][1];
        y = f[x][y][2];
    }
    f[xx][yy][1] = x;
    f[xx][yy][2] = y;
}

void dfs_pre(int x, int y) {
    int sum = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    f[x][y][1] = x;
    f[x][y][2] = y;
    mark[x][y] = true;
    while(!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        add(xx, yy, x, y);
        q.pop();
        ++sum;
        if(t[xx][yy] == 1) {
            if(xx + 1 <= n && t[xx + 1][yy] == 0 && !mark[xx + 1][yy])
                q.push(make_pair(xx + 1, yy)), mark[xx + 1][yy] = true;
            if(xx - 1 >= 1 && t[xx - 1][yy] == 0 && !mark[xx - 1][yy])
                q.push(make_pair(xx - 1, yy)), mark[xx - 1][yy] = true;
            if(yy + 1 <= n && t[xx][yy + 1] == 0 && !mark[xx][yy + 1])
                q.push(make_pair(xx, yy + 1)), mark[xx][yy + 1] = true;
            if(yy - 1 >= 1 && t[xx][yy - 1] == 0 && !mark[xx][yy - 1])
                q.push(make_pair(xx, yy - 1)), mark[xx][yy - 1] = true;
        }
        else {
            if(xx + 1 <= n && t[xx + 1][yy] == 1 && !mark[xx + 1][yy])
                q.push(make_pair(xx + 1, yy)), mark[xx + 1][yy] = true;
            if(xx - 1 >= 1 && t[xx - 1][yy] == 1 && !mark[xx - 1][yy])
                q.push(make_pair(xx - 1, yy)), mark[xx - 1][yy] = true;
            if(yy + 1 <= n && t[xx][yy + 1] == 1 && !mark[xx][yy + 1])
                q.push(make_pair(xx, yy + 1)), mark[xx][yy + 1] = true;
            if(yy - 1 >= 1 && t[xx][yy - 1] == 1 && !mark[xx][yy - 1])
                q.push(make_pair(xx, yy - 1)), mark[xx][yy - 1] = true;
        }
    }
    ans[x][y] = sum;
}

int main() {

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            ans[i][j] = -1;
        }
    }
    memset(f, 0, sizeof(f));
    memset(mark, false, sizeof(t));

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> tttmp;
            if(tttmp == '1') 
                t[i][j] = true;
            else
                t[i][j] = false;

        }
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(!mark[i][j]) {
                dfs_pre(i, j);
            }
        }
    }

    while(m--) {
        cin >> p >> q;
        cout << ans[f[p][q][1]][f[p][q][2]] << endl;
    }
    return 0;
}