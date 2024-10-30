#include <bits/stdc++.h>

#define N 500010

using namespace std;

char ch[N];
int n;
vector<int> edges[N];
int dp1[N], dp2[N];
int s = 0;

void add(int u, int v) {
    edges[u].push_back(v);
}

void build(int p, int fa) {
    ++s;
    if(ch[p] == '0') {
        return;
    }
    else if(ch[p] == '1') {
        add(p, p + 1);
        build(p + 1, p);
        return;
    }
    else if(ch[p] == '2') {
        add(p, p + 1);
        build(p + 1, p);
        add(p, s + 1);
        build(s + 1, p);
    }
}

int main() {

    cin >> ch + 1;

    n = strlen(ch + 1);

    build(1, 1);

    for(int i = n; i >= 1; --i) {
        int tmp = edges[i].size();
        if(tmp == 0) {
            dp1[i] = 1;
            dp2[i] = 0;
        }
        else if(tmp == 1) {
            dp1[i] = dp2[edges[i][0]] + 1;
            dp2[i] = dp1[edges[i][0]];
        }
        else {
            dp1[i] = dp2[edges[i][0]] + dp2[edges[i][1]] + 1;
            dp2[i] = max(dp1[edges[i][0]] + dp2[edges[i][1]], dp1[edges[i][1]] + dp2[edges[i][0]]);
        }
    }

    cout << max(dp1[1], dp2[1]) << ' ';

    memset(dp1, 0x3f, sizeof(dp1));
    memset(dp2, 0x3f, sizeof(dp2));

    for(int i = n; i >= 1; --i) {
        int tmp = edges[i].size();
        if(tmp == 0) {
            dp1[i] = 1;
            dp2[i] = 0;
        }
        else if(tmp == 1) {
            dp1[i] = dp2[edges[i][0]] + 1;
            dp2[i] = min(dp1[edges[i][0]], dp2[edges[i][0]]);
        }
        else {
            dp1[i] = dp2[edges[i][0]] + dp2[edges[i][1]] + 1;
            dp2[i] = min(dp1[edges[i][0]] + dp2[edges[i][1]], dp1[edges[i][1]] + dp2[edges[i][0]]);
        }
    }

    cout << min(dp1[1], dp2[1]);

    return 0;
}