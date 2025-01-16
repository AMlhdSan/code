#include <bits/stdc++.h>

#define N 2001000
#define int long long

using namespace std;

int n;
int a[N];
long long ans = 0;
int topl, topr;
int cntl[N], cntr[N];
int stkl[N], stkr[N];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

inline void solve(int l,int r) {

    int mid = (l + r) >> 1;

    if(l == r) {
        ans += a[l];
        return;
    }

    solve(l, mid);
    solve(mid + 1, r);

    int gl = 0;
    for(int i = mid; i >= l; --i) {
        gl = gcd(gl, a[i]);
        ++cntl[gl];
        if(cntl[gl] == 1)
            stkl[++topl] = gl;
    }
    int gr = 0;
    for(int i = mid + 1; i <= r; ++i) {
        gr = gcd(gr, a[i]);
        ++cntr[gr];
        if(cntr[gr] == 1)
            stkr[++topr] = gr;
    }

    for(int i = 1; i <= topl; ++i) {
        for(int j = 1; j <= topr; ++j) {
            int g = gcd(stkl[i], stkr[j]);
            ans += g * cntl[stkl[i]] * cntr[stkr[j]];
        }
    }

    while(topl)
        cntl[stkl[topl--]] = 0;
    while(topr)
        cntr[stkr[topr--]] = 0;
}

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

signed main() {

    n = read();

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    solve(1, n);

    cout << ans << endl;

    return 0;
}