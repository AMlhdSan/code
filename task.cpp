#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2000005;
int n, m, b[N], c[N], cnt[N];
ll V, a[N];
bool check(ll x) {
    ll s = 0;
    for (int i = 1; i <= n; i++)
        cnt[i] = max(0LL, min((ll)b[i], (x - a[i]) / c[i]));
    nth_element(cnt + 1, cnt + m, cnt + n + 1, greater<int>());
    for (int i = 1; i <= m; i++)
        s += cnt[i];
    return s >= V;
}
void gen(int n, ull seed) {
    mt19937_64 rnd(seed);
    for (int i = 1; i <= n; i++) {
        a[i] = rnd() % (ll(1e18)) + 1;
        b[i] = rnd() % (int(1e9)) + 1;
        c[i] = rnd() % (int(1e9)) + 1;
    }
}
int main() {
    // freopen("task.in", "r", stdin);
    // freopen("task.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> V;
    if(n > 100000){
        ull seed;
        cin >> seed;
        gen(n, seed);
    }
    else{
        for (int i = 1; i <= n; i++)
            cin >> a[i] >> b[i] >> c[i];
    }
    ll l = 0, r = 2000000000000000000LL, ans = -1;
    while(l <= r){
        ll mid = (l + r) >> 1;
        if(check(mid))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    cout << ans;
    return 0;
}
