#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N = 1e5 + 5;
int a[N], n, m, f[N];
ll ans;

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

int main () {
    freopen("shopping.in", "r", stdin);
    freopen("shopping.out", "w", stdout);
    n = read();
    m = read();
    for(int i = 1; i <= n; i++) {   
        a[i] = read();
        ans += a[i];
    }
    priority_queue<int> q;
    for(int i = 1; i <= n; i++) {
        int t = a[i];
        while(t > 0) {
            q.push (t - t / 2);
            t /= 2;
        }
    }

    while(!q.empty () && m --) {
        ans -= q.top ();
        q.pop ();
    }
    cout << ans;
    return 0;
}