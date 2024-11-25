#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 20;

int n, L, R, k;
vector<int> tree[MAXN];
int a[MAXN];
int sub[MAXN];

void dfs(int u) {
    sub[u] = (1 << (u - 1));
    for (int v : tree[u]) {
        dfs(v);
        sub[u] |= sub[v];
    }
}

int solve(int msk) {

    int summ = 0;

    for (int i = 1; i <= n; ++i) {
        if ((msk & (1 << (i - 1))) == 0) continue;

        map<int, int> freq;
        for (int j = 1; j <= n; ++j) {
            if ((sub[i] & (1 << (j - 1))) && (msk & (1 << (j - 1)))) {
                freq[a[j]]++;
            }
        }

        if (freq[a[i]] >= k) {
            summ++;
        }
    }

    return summ;
}

int main() {

    freopen("occur.in", "r", stdin);
    freopen("occur.out", "w", stdout);

    cin >> n >> L >> R >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        tree[p].push_back(i);
    }

    dfs(1);

    int tot = 0;
    for (int msk = 0; msk < (1 << n); ++msk) {
        int summ = solve(msk);
        if (L <= summ && summ <= R) {
            tot = (tot + 1) % MOD;
        }
    }

    cout << tot << endl;

    return 0;
}
