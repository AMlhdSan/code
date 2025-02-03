#include <bits/stdc++.h>
#define RS register
#define N 100005
using namespace std;
typedef long long ll;

template <typename T> void read(T &x) {
	x = 0; RS char c(getchar());
	while(!isdigit(c)) c = getchar();
	for(;isdigit(c);c = getchar())
		x = (x << 3) + (x << 1) + (c ^ 48); 
}

int n; ll a[N];

inline ll max(ll a, ll b) { return a > b ? a : b; }

ll gcd(ll a, ll b) {//不用管这gcd
	if(!a) return b; if(!b) return a;
	if(!(a & 1 || b & 1))
		return gcd(a >> 1, b >> 1) << 1;
	if(!(a & 1)) return gcd(a >> 1, b);
	if(!(b & 1)) return gcd(a, b >> 1);
	return gcd(abs(a - b), min(a, b));
}

ll dfs(int L, int R) {
	if(L == R) return a[L];
	RS int l, r, mid = L + R >> 1;
	l = r = mid;
	RS ll g = a[mid], maxx = a[mid];
	while(L <= l && r < R) {
		g = gcd(a[++r], g);
		while(r <= R) if(a[++r] % g) break; r--;
		while(l >= L) if(a[--l] % g) break; l++;
		maxx = max(maxx, (r - l + 1) * g);
	}
	l = r = mid; g = a[mid];
	while(L < l && r <= R) {
		g = gcd(a[--l], g);
		while(l >= L) if(a[--l] % g) break; l++;
		while(r <= R) if(a[++r] % g) break; r--;
		maxx = max(maxx, (r - l + 1) * g);
	}
	return max(maxx, max(dfs(L, mid), dfs(mid + 1, R)));
}

int main() {
	read(n);
	for(RS int i = 1;i <= n;i++) read(a[i]);
	printf("%lld", dfs(1, n));
	return 0;
}