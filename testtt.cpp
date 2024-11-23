#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vint;

ll read() {
	ll a = 0, b = 0; char c = getchar();
	while (c < '0' || c > '9') b ^= (c == '-'), c = getchar();
	while (c >= '0' && c <= '9') a = a * 10 - 48 + c, c = getchar();
	return b ? -a : a;
}

const ll N = 200005;
ll n, k, c[N], l[N];
ll su[N];

vint e1;
vint cl[N];
vint pa[N];
ll p3[N];
vint ans;

int main() {
	// freopen("people.in", "r", stdin);
	// freopen("people.out", "w", stdout);
	n = read(), k = read();
	
	for (ll i = 0; i < n; ++i) {
		c[i] = read(), l[i] = read();
		su[c[i]]++;
		su[(c[i] + l[i]) % k]--;
		su[0] += (c[i] + l[i]) / k;
		cl[c[i]].push_back(i);
	}
	for (ll i = 1; i < k; ++i) su[i] += su[i - 1];
	ll mn = *min_element(su, su + k);
	ll st = 0, slen = 0;
	for (ll i = 0; i < k; ++i) if (su[i] == mn) {
		ll j = (i + 1) % k, le = 0;
		while (su[j] != mn) j = (j + 1) % k, ++le;
		if (le > slen) st = (i + 1) % k, slen = le;
	}
	for (ll i = 0; i < k; ++i) su[i] -= mn;
	for (ll i = 0; i < slen; ++i) su[(st + i) % k] --;
	
	if (slen) {
		vint df(k);
		for (ll i = 0; i < k; ++i) if (su[i] == 0 && su[(i + 1) % k] != 0) {
			ll j = (i + 1) % k;
			ll p = j % k, curle = 0;
			while (su[p] != 0) p = (p + 1) % k, ++curle;
			//cerr << i << ' ' << j << ' ' << p << " ??\n";
			ll cur = 0;
			while (j != p) {
				cur += df[j];
				su[j] += cur;
				while (su[j] != 0) {
					assert(cl[j].size() != 0);
					ll ii = cl[j].back(); cl[j].pop_back();
					ll le = min(l[ii], curle);
					//cerr << "del " << ii << ' ' << le << ' ' << l[ii] << ' ' << c[ii] << '\n';
					c[ii] = (c[ii] + le) % k;
					l[ii] -= le;
					assert(pa[ii].size() == 0);
					pa[ii].push_back(le);
					cl[c[ii]].push_back(ii);
					su[j]--; cur--;
					df[c[ii]]++;
				}
				j = (j + 1) % k;
				curle--;
			}
			// [j, p]
			if (p <= i) break;
			i = p;
		}
	}
	for (ll i = 0; i < n; ++i) e1.push_back(i);
	ll e = (st + slen) % k;
	cout << st << ' ' << mn * k + slen << '\n';
	//cerr << e << '\n';
	while (1) {
		if (cl[st].size()) {
			ll ii = cl[st].back(); cl[st].pop_back();
			if (!l[ii]) continue;
			pa[ii].push_back(l[ii]);
			ans.push_back(l[ii]);
			st = (st + l[ii]) % k;
			//cerr << "? " << st << ' ' << c[ii] << ' ' << l[ii] << ' ' << ii << '\n';
			c[ii] = (c[ii] + l[ii]) % k;
			l[ii] = 0;
		} else if (st == (e) % k) {
			ll fg = 0;
			while (1) {
				if (e1.size() == 0) {
					fg = 1;
					break;
				}
				ll ii = e1.back(); e1.pop_back();
				ll le;
				if (c[ii] < st) le = st - c[ii];
				else le = k - c[ii] + st;
				if (le < l[ii]) {
				//cerr << ii << ' ' << c[ii] << ' ' << l[ii] << ' ' << le << '\n';
					ans.push_back(l[ii] - le);
					st = (st + l[ii] - le + k) % k;
					p3[ii] = l[ii] - le;
					l[ii] = le;
					break;
				}
			}
			if (fg) break;
		} else assert(0);
	}
	for (ll i = 0; i < n; ++i) if (p3[i]) pa[i].push_back(p3[i]);
	
	for (ll i = 0; i < n; ++i) {
		cout << pa[i].size() << ' ';
		for (ll j : pa[i]) cout << j << ' '; cout << '\n';
	}
	cout << ans.size() << ' ';
	for (ll i : ans) cout << i << ' '; cout << '\n';
	
	
	
	
	
	return 0;
}