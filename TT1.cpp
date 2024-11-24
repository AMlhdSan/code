#include <bits/stdc++.h>

#define INF 1e6
#define NO pair<int, pair<int, int> >
#define E 0.0001
#define N 100010

using namespace std;

struct BALL {
    int x;
    int v;
};

bool cmp(BALL p, BALL q) {
    return p.x < q.x;
}

int n, k;
BALL a[N];
bool vis[N];
priority_queue<NO, vector<NO >, greater<NO > > q;
priority_queue<NO, vector<NO >, greater<NO > > tmp;

double time(int i, int j) {
    if (a[i].v == a[j].v) {
        return INF;
    }
    if ((a[j].x - a[i].x) * (a[i].v - a[j].v) < 0) {
        return INF;
    }
    return 
        1.0 * (a[j].x - a[i].x) / (a[i].v - a[j].v);
}

bool check(double t) {
    memset(vis, false, sizeof(vis));
    tmp = q;
    int cnt = 0;
    while(!tmp.empty() && tmp.top().first - t < -E) {
        vis[tmp.top().second.first] = true;
        vis[tmp.top().second.second] = true;
        tmp.pop();
    }
    for(int i = 1; i <= n; ++i) {
        if(vis[i]) {
            ++cnt;
        }
    }
    return cnt <= k;
}

int main() {

    // freopen("ball.in", "r", stdin);
    // freopen("ball.out", "w", stdout);

    cin >> n >> k;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i].x >> a[i].v;
    }
//  cout << fixed << setprecision(4) << time(1, 3) << endl;

    sort(a + 1, a + n + 1, cmp);

    for(int i = 1; i <= n; ++i) {
        for(int j = i + 1; j <= n; ++j) {
            q.push(make_pair(time(i, j), make_pair(i, j)));
        }
    }

    double l = 0.0, r = INF, mid;
    while (r - l > E) {
        mid = 1.0 * (l + r) / 2.0;
        if(check(mid)) {
            r = mid;
        } 
        else {
            l = mid;
        }
    }
    if(l >= INF) {
        cout << "Forever" << endl;
    }
    else 
        cout << fixed << setprecision(4) << l << endl;

    return 0;
}
