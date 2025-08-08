      
#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010, mod = 998244353;
int T, n, a[maxn], pw[maxn], cnt[maxn], f[maxn];
class BinaryLinearSpace {
public:
    BinaryLinearSpace() { memset(bas, 0, sizeof bas), r = 0; }
    inline void insert(int x) {
      for(int i = 19; i >= 0; --i) if(x >> i & 1) {
        if(bas[i]) x ^= bas[i];
        else {
          bas[i] = x, ++r;
          break;
        }
      }
    }
    int bas[20], r;
}bls[maxn];
inline void solve() {
  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= n; ++i) cnt[i] = 0;
  for(int i = 1; i <= n; ++i) ++cnt[a[i]];

  for(int i = 0; i <= n; ++i) bls[i] = BinaryLinearSpace();
  for(int i = 1; i <= n; ++i) bls[0].insert(a[i]);
  int ans = pw[n - bls[0].r];
  for(int i = 1; i <= n; ++i) f[i] = 0;
  for(int i = 1; i <= n; ++i) if(cnt[i]) for(int j = i; j <= n; j += i) if(cnt[j]) bls[j].insert(i), f[j] += cnt[i];
  for(int i = 1; i <= n; ++i) if(cnt[i]) ans = (ans + pw[f[i] - bls[i].r]) % mod;
  ans = (ans + mod - 1) % mod;
  cout << ans << '\n';
}
int main() {
	// freopen("xor.in", "r", stdin);
	// freopen("xor.out", "w", stdout);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  pw[0] = 1;
  for(int i = 1; i <= 200000; ++i) pw[i] = (pw[i - 1] << 1) % mod;
  cin >> T;
  while(T--) solve();
  return 0;
}

    