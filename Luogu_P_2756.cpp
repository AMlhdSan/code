#include <bits/stdc++.h>

#define INF 0x7fffffff
#define ll long long
#define N 10010

using namespace std;

int n, m;
int s, t;
long long ans;
vector<pair<int, ll> > edges[N];
int dis[N], now[N];
int tmpu, tmpv;

void add(int u, int v, ll w) {
    edges[u].push_back(make_pair(v, w));
    edges[v].push_back(make_pair(u, 0));
}

bool bfs() {
    fill(dis, dis + t + 1, INF);
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    now[s] = 0;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(pair<int, ll> v : edges[x]) {
            if(v.second > 0 && dis[v.first] == INF) {
                q.push(v.first);
                dis[v.first] = dis[x] + 1;
                now[v.first] = 0;
                if(v.first == t) {
                    return true;
                }
            }
        }
    }
    return false;
}

ll dfs(int x, ll flow) {
    if(x == t) {
        return flow;
    }
    ll res = 0;
    for(int i = now[x]; i < edges[x].size(); ++i) {
        pair<int, ll> &v = edges[x][i];
        if(v.second > 0 && dis[v.first] == dis[x] + 1) {
            ll k = dfs(v.first, min(flow, v.second));
            if(k == 0) {
                dis[v.first] = INF;
            }
            v.second -= k;
            for(pair<int, ll> &u : edges[v.first]) {
                if(u.first == x) {
                    u.second += k;
                    break;
                }
            }
            res += k;
            flow -= k;
            if(flow == 0) break;
        }
    }
    return res;
}

int main() {

    cin >> m >> n;

    s = 0;
    t = n + 1;

    //x-apple-health://HearingAppPlugin.healthplugin/HearingTest


    
    cin >> tmpu >> tmpv;
    while(tmpu != -1 && tmpv != -1) {
        add(tmpu, tmpv, 1);
        cin >> tmpu >> tmpv;
    }

    for(int i = 1; i <= m; ++i) {
        add(s, i, 1);
    }

    for(int i = m + 1; i <= n; ++i) {
        add(i, t, 1);
    }

    while(bfs()) {
        ans += dfs(s, INF);
    }

    cout << ans << endl;

    return 0;
}