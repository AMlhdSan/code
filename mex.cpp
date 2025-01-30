#include <bits/stdc++.h>

#define N 1500100
#define int long long

using namespace std;

int n, m;
int a[N];
int ans;
int t[N];

inline int read() {
    int x = 0, t = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            t = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * t;
}

signed main() {

    // freopen("mex.in", "r", stdin);
    // freopen("mex.out", "w", stdout);
	
    n = read();
    m = read();

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    for(int i = 1; i <= m; ++i) {
        ++t[a[i]];
    }

    for(int i = 0; i <= n; ++i) {
        if(!t[i]) {
            ans = i;
            break;
        }
    }
    for(int i = m + 1; i <= n; ++i) {
        --t[a[i - m]];
        ++t[a[i]];
        if(!t[a[i - m]]) {
            ans = min(ans, a[i - m]);
        }
    }
	
    cout << ans << endl;
	return 0;
}