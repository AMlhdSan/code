#include <bits/stdc++.h>
using namespace std;

int n;

int x_0, y_0, x_1, y_1;
int x[7], y[7];

int xx[7];
int yy[7];
int r[7]; // 半径
int cnt = 0; // 记录放的个数

double dis(int t1, int t2) {
    return sqrt((xx[t1] - x[t2]) * (xx[t1] - x[t2]) + (yy[t1] - y[t2]) * (yy[t1] - y[t2]));
}

int pd(int t) {
    int returnn = 1001;
    // 点
    for(int i = 1; i <= cnt; ++i) {
        if(dis(i, t) <= r[i]) {
            return 0;
        }
        else {
            returnn = min(returnn, (int)dis(i, t) - r[i]);
        }
    }
    // 边界
    returnn = min(returnn, abs(x_0 - x[t]));
    returnn = min(returnn, abs(x_1 - x[t]));
    returnn = min(returnn, abs(y_0 - y[t]));
    returnn = min(returnn, abs(y_1 - y[t]));

    return returnn;
}

void dfs(int t) {
    int temp = pd(t);
    if(temp == 0) // 如果放不了
        return ;
    // 能放
    ++cnt;
    r[cnt] = temp;
    xx[cnt] = x[t];
    yy[cnt] = y[t];
    for(int i = t + 1 ; i <= n; ++i) {
        dfs(i);
    }
    --cnt;
    return;
}

int main() {

    memset(xx, -1001, sizeof(xx));
    memset(yy, -1001, sizeof(yy));

    cin >> x_0 >> y_0 >> x_1 >> y_1;

    for(int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }

    for(int i = 1; i <= n; ++i) {
        dfs(i);
    }
    return 0;
}