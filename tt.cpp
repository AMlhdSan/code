#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50;
const int MAXM = 1600;
const int INF = 1e9;

struct Cow {
    int x, y; // 当前坐标
    int tx, ty; // 目标坐标
    int id; // 奶牛编号
};

int n, m;
vector<Cow> cows;
set<pair<int, int>> occupied; // 当前被占据的格子
vector<tuple<int, int, int, int>> moves; // 记录所有移动操作

// 检查一个位置是否合法
bool is_valid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= n && !occupied.count({x, y});
}

// 计算曼哈顿距离
int manhattan(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// 贪心移动策略
void move_cow(Cow &cow) {
    // 尝试向目标方向移动
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    sort(directions.begin(), directions.end(), [&](pair<int, int> d1, pair<int, int> d2) {
        int nx1 = cow.x + d1.first, ny1 = cow.y + d1.second;
        int nx2 = cow.x + d2.first, ny2 = cow.y + d2.second;
        return manhattan(nx1, ny1, cow.tx, cow.ty) < manhattan(nx2, ny2, cow.tx, cow.ty);
    });

    for (auto [dx, dy] : directions) {
        int nx = cow.x + dx, ny = cow.y + dy;
        if (is_valid(nx, ny)) {
            // 更新位置
            occupied.erase({cow.x, cow.y});
            occupied.insert({nx, ny});
            moves.emplace_back(cow.x, cow.y, nx, ny);
            cow.x = nx;
            cow.y = ny;
            break;
        }
    }
}

int main() {
    // 输入
    cin >> n >> m;
    cows.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> cows[i].x >> cows[i].y;
        cows[i].id = i;
    }
    for (int i = 0; i < m; ++i) {
        cin >> cows[i].tx >> cows[i].ty;
    }

    // 初始化占据的格子
    for (auto &cow : cows) {
        occupied.insert({cow.x, cow.y});
    }

    // 模拟移动
    while (true) {
        bool all_done = true;
        for (auto &cow : cows) {
            if (cow.x != cow.tx || cow.y != cow.ty) {
                all_done = false;
                move_cow(cow);
            }
        }
        if (all_done) break;
    }

    // 输出结果
    cout << moves.size() << endl;
    for (auto [x, y, nx, ny] : moves) {
        cout << x << " " << y << " " << nx << " " << ny << endl;
    }

    return 0;
}
