#include <bits/stdc++.h>

#define int long long

using namespace std;

inline int calc(int cnt_0, int cnt_1) {
    return cnt_0 * cnt_1;
}

bool pd(const string &s, int k, int maxx) {
    int n = s.size();
    int cnt_0 = 0, cnt_1 = 0, seg = 1;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '0')
            ++cnt_0;
        else
            ++cnt_1;

        if (calc(cnt_0, cnt_1) > maxx) {

            ++seg;
            cnt_0 = (s[i] == '0');
            cnt_1 = (s[i] == '1');
            if (seg > k) return false;
        }
    }

    return true;
}

signed main() {
    int n, k;
    string s;

    cin >> n >> k;
    cin >> s;

    int l = 0, r = n * n, ans = r;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (pd(s, k, mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1; 
        }
    }

    cout << ans << endl;
    return 0;
}
