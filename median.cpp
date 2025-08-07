#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

    freopen("median.in", "r", stdin);
    // freopen(""
    freopen("median.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<ll> a(n), b(n);
    ll mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        mx = max(mx, max(a[i], b[i]));
    }
    const int pos = (n + 1) / 2; 

    auto ok = [&](ll T) -> bool {
        ll base = 0, cur = 0, mxSum = LLONG_MIN;
        for (int i = 0; i < n; ++i) {
            int ca = (a[i] >= T);
            int cb = (b[i] >= T);
            base += ca;
            int d = cb - ca;                  // -1,0,1
            cur = (i == 0) ? d : max<long long>(d, cur + d);
            mxSum = max(mxSum, cur);
        }
        if (base >= pos) return true;
        ll need = pos - base;                 // 需要的额外+计数
        return mxSum >= need;
    };

    ll lo = 0, hi = mx;
    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        if (ok(mid)) lo = mid;
        else          hi = mid - 1;
    }
    cout << lo << '\n';
    return 0;
}


