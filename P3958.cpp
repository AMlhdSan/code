#include <bits/stdc++.h>
using namespace std;

int T;
int n, h, r;
int x[1001],y[1001],z[1001];
int lin[1001][1001];
bool on[1001], under[1001];
int de[1001];
bool book[1001];
int if_can[1001];
int cnt;
bool flag = false;

double dis(int a, int b) {
    return sqrt(pow(x[a] - x[b], 2) + pow(y[a] - y[b], 2) + pow(z[a] - z[b], 2));
}

bool dfs(int x) {
    if(on[x]) {
        return true;
    }
    if(if_can[x] == 1) {
        return true;
    }
    else if(if_can[x] == -1) {
        return false;
    }
    for(int i = 1; i <= de[x]; ++i) {
        if(book[lin[x][i]]) {
            continue;
        }
        if(on[lin[x][i]]) {
            if_can[x] = 1;
            return true;
        }
        else {
            book[lin[x][i]] = true;
            if(dfs(lin[x][i])) {
                if_can[x] = 1;
                return true;
            }
            book[lin[x][i]] = false;
        }
    }
    if_can[x] = -1;
    return false;
}


int main() {
    std::ios::sync_with_stdio(0);
    cin >> T;
    while (T--) {
        flag = false;
        memset(on, false, sizeof(on));
        memset(under, false, sizeof(under));
        memset(book, false, sizeof(book));
        memset(if_can, 0, sizeof(if_can));
        cin >> n >> h >> r;
        for (int i = 1; i <= n; i++) {
            cin >> x[i] >> y[i] >> z[i];
            if(z[i] + r >= h) {
                on[i] = true;
            }
            if(z[i] - r <= 0) {
                under[i] = true;
            }
        }
        for(int i = 1; i <= n; ++i) {
            cnt = 1;
            for(int j = 1; j <= n; ++j) {
                if(i != j)
                    if(dis(i, j) <= 2 * r) {
                        lin[i][cnt] = j;
                        ++cnt;
                    }
            }
            de[i] = cnt - 1;
        }
        for(int i = 1; i <= n; ++i) {
            if(under[i]) {
                if(dfs(i)) {
                    flag = true;
                    break;
                }
            }
        }
        if(flag) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}