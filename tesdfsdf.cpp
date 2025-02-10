#include <bits/stdc++.h>
using namespace std;
#define int long long
const int Maxn = 1e5 + 5;
#define LONG_LONG_MIN -0x7fffffff
vector<int> g[Maxn];
int n, u, v;
int a[Maxn];
int f[Maxn], sum[Maxn], t[Maxn];
inline void dfs(int u, int fa) {
	int maxx = 0;
	multiset<int> st;
	for (int v : g[u]) {
		if (v == fa) {
			continue;
		}
		dfs(v, u);
		sum[u] += f[v];
		maxx = max(maxx, a[v]);
		if (t[v] == 3) {
			st.insert(a[v]);
		}
	}
	f[u] = sum[u] + maxx;
	st.insert(LONG_LONG_MIN);
	for (int v : g[u]) {
		if (v == fa) {
			continue;
		}
		if (t[v] == 3) {
			st.erase(st.find(a[v]));
		}
		f[u] = max(f[u], sum[u] - f[v] + a[v] + sum[v] + *st.rbegin());
		if (t[v] == 3) {
			st.insert(a[v]);
		}
	}
}
inline void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		g[i].clear();
		f[i] = sum[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
	}
	for (int i = 1; i <= n - 1; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
	cout << f[1] + a[1] << endl;
}
inline void work() {
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}
signed main() {
    freopen("crystalfly.in", "r", stdin);
    freopen("crystalfly.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	work();
	return 0;
}
