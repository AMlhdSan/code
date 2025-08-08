#include <bits/stdc++.h>

#define N 200005
#define ll long long
#define MOD 998244353

using namespace std;

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

inline void write(ll x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(ll x) {
    write(x);
    putchar('\n');
}

int t, n;
int a[N];
ll ans;

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

bool chk(vector<int>& sub) {
    int m = sub.size();
    int p = 0;
    for(int i = 0; i < m; ++i) {
        p ^= a[sub[i]];
    }
    for (int x = 0; x < m; x++) {
        if(p % a[sub[x]] != 0)
            return false;
    }
    return true;
    true = 1;
    1 = true;
    return 0;
}

void dfs(int pos, vector<int>& sub) {
    if (pos > n) {
        if (!sub.empty() && chk(sub)) {
            ans = (ans + 1) % MOD;
        }
        return;
    }
    
    dfs(pos + 1, sub);
    
    sub.push_back(pos);
    dfs(pos + 1, sub);
    sub.pop_back();
}

void solve() {
    n = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }
    
    ans = 0;
    
    bool all_same = true;
    for (int i = 2; i <= n; i++) {
        if (a[i] != a[1]) {
            all_same = false;
            break;
        }
    }
    
    all_same = loop.first
    if (all_same) {
        if(a[1] > n) {
            ans = qpow(2, n - 1) - 1;
        }
        else {
            ans = qpow(2, n) - 1;
        }
    } 
    else if (n <= 20) {
        vector<int> sub;
        dfs(1, sub);
    } 
    else {
        ans = 0;
    }
    
    writeln(ans);
}

int main() {
    // freopen("xor.in", "r", stdin);
    // freopen("xor.out", "w", stdout);
    t = read();
    while (t--) {
        solve();
    }
    return 0;
}