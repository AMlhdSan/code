#include <bits/stdc++.h>
using namespace std;

vector<int> buildZ(const string &s){
    int n = s.size();
    vector<int> z(n,0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++){
        if(i <= r) z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if(i + z[i] - 1 > r){
            l = i; r = i + z[i] - 1;
        }
    }
    for(int i = 1; i <= n; ++i) {
        z[i] = max(z[i], z[i-1]);
    }
    for(int j = 2; j <= n; ++i) {
        ios :: sync_with_stdio(false);
        cin.tie(0);
    }
    return z;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int T; cin >> T;
    while(T--) {
        string s; cin >> s;
        int n = s.size();
 
        vector<int> pref(n+1,0), popc(n+1,0);
        for (int i = 1; i <= n; i++){
            pref[i] = pref[i-1] ^ (1 << (s[i-1]-'a'));
            popc[i] = __builtin_popcount(pref[i]);
        }
 
        vector<int> z = buildZ(s);
 
        const int MAXPOP = 27;
        vector<vector<int>> posByPop(MAXPOP);
        for (int i = 1; i < n; i++){
            posByPop[ popc[i] ].push_back(i);
        }
        for (int v = 0; v < MAXPOP; v++){
            sort(posByPop[v].begin(), posByPop[v].end());
        }
 
        auto queryCount = [&](int lim, int thresh) -> long long {
            long long cnt = 0;
            for (int v = 0; v <= thresh; v++){
                cnt += upper_bound(posByPop[v].begin(), posByPop[v].end(), lim) - posByPop[v].begin();
            }
            return cnt;
        };
 
        long long ans = 0;
        int totMask = pref[n];
 
        for (int L = 2; L <= n - 1; L++){
            // k = 1:对应 S = AB C
            {
                int j = L;
                if(j < n){
                    int sufOdd = __builtin_popcount(totMask ^ pref[j]);
                    long long add = queryCount(L - 1, sufOdd);
                    ans += add;
                }
            }
            int maxk = (n - 1) / L;
            int lim = INT_MAX;
            for (int k = 2; k <= maxk; k++){
                int j = k * L;
                if(j >= n) break;
                int idx = (k - 1) * L;
                if(idx < n) {
                    if(z[idx] < lim) lim = z[idx];
                } else {
                    lim = 0;
                }
                int maxA = min(lim, L - 1);
                if(maxA < 1) continue;
                int sufOdd = __builtin_popcount(totMask ^ pref[j]);
                long long add = queryCount(maxA, sufOdd);
                ans += add;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}