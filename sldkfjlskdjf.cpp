#include <bits/stdc++.h>
#define int long long

using namespace std;
signed main() {
    // freopen("cut.in", "r", stdin);
    // freopen("cut.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        int n, S;
        cin >> n >> S;
        
        double sum_initial = 0.0;
        vector<double> deltas;
        
        for (int i = 0; i < n; ++i) {
            int h, w;
            cin >> h >> w;
            double perimeter = 2.0 * (h + w);
            sum_initial += perimeter;
            double delta = 2.0 * sqrt(h * h + w * w);
            deltas.push_back(delta);
        }
        
        if (sum_initial > S) {
            cout << fixed << setprecision(15)<< S << '\n';
            continue;
        }
        
        sort(deltas.rbegin(), deltas.rend());
        double extra = S - sum_initial;
        double res = sum_initial;
        
        for (double d : deltas) {
            if (extra >= d) {
                res += d;
                extra -= d;
            } else {
                break;
            }
        }
        
        cout << fixed << setprecision(15) << res << '\n';
    }
    
    return 0;
}