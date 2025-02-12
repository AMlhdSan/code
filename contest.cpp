#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

inline ll add_mod(ll a, ll b) {
    a += b;
    if(a >= MOD) a -= MOD;
    return a;
}

vector<ll> getDistribution(const vector<int>& Pvec) {
    int cnt = Pvec.size();
    if(cnt == 0) {
        return vector<ll>(1, 1);
    }
    vector<ll> cur(1, 1);
    int curMin = 0, curMax = 0;
    for (int cap : Pvec) {
        int nxtMin = curMin + 1, nxtMax = curMax + cap;
        vector<ll> nxt(nxtMax + 1, 0);
        for (int x = curMin; x <= curMax; x++) {
            if(cur[x] == 0) continue;
            for (int d = 1; d <= cap; d++) {
                nxt[x + d] = (nxt[x + d] + cur[x]) % MOD;
            }
        }
        cur = move(nxt);
        curMin = nxtMin, curMax = nxtMax;
    }
    return cur;
}

int main(){
    freopen("contest.in", "r", stdin);
    freopen("contest.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> P(m+1);
    for (int j = 1; j <= m; j++) cin >> P[j];
    vector<string> submit(n+1);
    for (int i = 1; i <= n; i++) cin >> submit[i];

    vector<vector<ll>> f(n+1);
    vector<int> L(n+1, 0), R(n+1, 0);
    for (int i = 1; i <= n; i++) {
        vector<int> Pvec;
        for (int j = 0; j < m; j++) {
            if(submit[i][j] == '1') Pvec.push_back(P[j+1]);
        }
        vector<ll> dist = getDistribution(Pvec);
        L[i] = Pvec.empty() ? 0 : Pvec.size();
        R[i] = dist.size() - 1;
        f[i] = move(dist);
    }

    int M = 0;
    for (int i = 1; i <= n; i++) M = max(M, R[i]);
    for (int i = 1; i <= n; i++) {
        if ((int)f[i].size() < M+1) f[i].resize(M+1, 0);
    }

    vector<vector<ll>> dp(n+1, vector<ll>(M+1, 0));
    for (int s = L[1]; s <= R[1]; s++) dp[1][s] = f[1][s] % MOD;
    for (int i = 2; i <= n; i++) {
        vector<ll> cum(M+2, 0);
        for (int t = M; t >= 0; t--) cum[t] = (dp[i-1][t] + cum[t+1]) % MOD;
        for (int s = L[i]; s <= R[i]; s++) dp[i][s] = (f[i][s] * cum[s+1]) % MOD;
    }

    ll ans_no_tie = 0;
    for (int s = L[n]; s <= R[n]; s++) ans_no_tie = (ans_no_tie + dp[n][s]) % MOD;

    vector<vector<ll>> dp_rev(n+2, vector<ll>(M+1, 0));
    for (int s = L[n]; s <= R[n]; s++) dp_rev[n][s] = f[n][s] % MOD;
    for (int i = n-1; i >= 1; i--) {
        vector<ll> cum(M+2, 0);
        for (int x = M; x >= 0; x--) cum[x] = (dp_rev[i+1][x] + cum[x+1]) % MOD;
        for (int s = L[i]; s <= R[i]; s++) {
            int low_bound = L[i+1], high_bound = min(R[i+1], s - 1);
            ll sum_val = (s > low_bound && high_bound >= low_bound) ? (cum[low_bound] - cum[high_bound+1] + MOD) % MOD : 0;
            dp_rev[i][s] = (f[i][s] * sum_val) % MOD;
        }
    }

    vector<ll> tie_ans(n+1, 0);
    for (int i = 1; i <= n - 1; i++) {
        ll cur_tie = 0;
        int lower_bound = max(L[i], L[i+1]), upper_bound = min(R[i], R[i+1]);
        for (int s = lower_bound; s <= upper_bound; s++) {
            ll ways = (dp[i][s] * f[i+1][s]) % MOD;
            ll suffix = 1;
            if (i+1 < n) {
                vector<ll> cum_suffix(M+2, 0);
                for (int x = M; x >= 0; x--) cum_suffix[x] = (dp_rev[i+2][x] + cum_suffix[x+1]) % MOD;
                int lb = L[i+2], ub = min(R[i+2], s - 1);
                ll sum_suffix = (s > lb && ub >= lb) ? (cum_suffix[lb] - cum_suffix[ub+1] + MOD) % MOD : 0;
                suffix = sum_suffix;
            }
            cur_tie = (cur_tie + ways * suffix) % MOD;
        }
        tie_ans[i] = cur_tie;
    }

    for (int i = 1; i <= n - 1; i++) cout << tie_ans[i] << " ";
    cout << ans_no_tie << "\n";

    return 0;
}