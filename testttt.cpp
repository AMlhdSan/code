#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 20;

int n, L, R, k;
vector<int> tree[MAXN];
int a[MAXN];
int subtree_nodes[MAXN];

void dfs(int u) {
    subtree_nodes[u] = (1 << (u - 1));
    for (int v : tree[u]) {
        dfs(v);
        subtree_nodes[u] |= subtree_nodes[v];
    }
}

int count_good_points(int mask) {
    int good_points = 0;

    for (int i = 1; i <= n; ++i) {
        if ((mask & (1 << (i - 1))) == 0) continue;

        map<int, int> freq;
        for (int j = 1; j <= n; ++j) {
            if ((subtree_nodes[i] & (1 << (j - 1))) && (mask & (1 << (j - 1)))) {
                freq[a[j]]++;
            }
        }

        if (freq[a[i]] >= k) {
            good_points++;
        }
    }

    return good_points;
}

int main() {

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

    int total_ways = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int good_points = count_good_points(mask);
        if (L <= good_points && good_points <= R) {
            total_ways = (total_ways + 1) % MOD;
        }
    }

    cout << total_ways << endl;

    return 0;
}
