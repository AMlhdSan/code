#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    scanf("%d", &n);
    vector<pair<ll, ll>> seg(n);
    for(int i = 0; i < n; i++) {
        scanf("%lld%lld", &seg[i].first, &seg[i].second);
    }
    sort(seg.begin(), seg.end());
    ll ans = 0, l = seg[0].first, r = seg[0].second;
    for(int i = 1; i < n; i++) {
        if(seg[i].first > r) {
            ans += r - l + 1;
            l = seg[i].first;
            r = seg[i].second;
        } else {
            r = max(r, seg[i].second);
        }
    }
    ans += r - l + 1;
    printf("%lld\n", ans);
    return 0;
}