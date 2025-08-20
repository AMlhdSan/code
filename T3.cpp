#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>
#include <climits>
#include <functional>

using namespace std;

using ll = long long;

int m, q, k, t;
int n;
vector<ll> c;
vector<pair<ll, ll>> p1;
vector<pair<ll, ll>> v;
ll z = LLONG_MIN;
vector<int> s;

void f(int a, int b) {
    if (b == m) {
        vector<ll> x, y;
        for (const auto& i : p1) {
            x.push_back(i.first);
            y.push_back(i.second);
        }
        for (int i : s) {
            x.push_back(v[i].first);
            y.push_back(v[i].second);
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        ll res = 0;
        for (int i = 0; i < n; ++i) {
            res += c[i + 1] * x[i];
        }
        for (int i = 0; i < n; ++i) {
            res += c[i + 1] * y[i];
        }
        z = max(z, res);
        return;
    }

    for (int i = a; i < v.size(); ++i) {
        s.push_back(i);
        f(i + 1, b + 1);
        s.pop_back();
    }
}

int main() {

    freopen("net.in", "r", stdin);
    freopen("net.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> q >> k >> t;

    n = m + t;
    c.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        c[i] = 2LL * i - n - 1;
    }

    p1.resize(t);
    for (int i = 0; i < t; ++i) {
        ll x, y = 0;
        cin >> x;
        if (k == 2) {
            cin >> y;
        }
        p1[i] = {x, y};
    }

    vector<pair<ll, ll>> p2;
    for (int i = 0; i < m; ++i) {
        ll x, y = 0;
        cin >> x;
        if (k == 2) {
            cin >> y;
        }
        p2.push_back({x, y});
    }
    for (int i = 0; i < q; ++i) {
        ll x, y = 0;
        cin >> x;
        if (k == 2) {
            cin >> y;
        }
        p2.push_back({x, y});
    }

    set<pair<ll, ll>> cand;
    
    vector<pair<ll, ll>> sx = p2;
    sort(sx.begin(), sx.end());
    for (int i = 0; i < min(m, (int)p2.size()); ++i) {
        cand.insert(sx[i]);
    }
    reverse(sx.begin(), sx.end());
    for (int i = 0; i < min(m, (int)p2.size()); ++i) {
        cand.insert(sx[i]);
    }

    vector<pair<ll, ll>> sy = p2;
    sort(sy.begin(), sy.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
        return a.second < b.second;
    });
    for (int i = 0; i < min(m, (int)p2.size()); ++i) {
        cand.insert(sy[i]);
    }
    reverse(sy.begin(), sy.end());
    for (int i = 0; i < min(m, (int)p2.size()); ++i) {
        cand.insert(sy[i]);
    }

    v.assign(cand.begin(), cand.end());

    f(0, 0);

    cout << z << endl;

    return 0;
}