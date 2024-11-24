#include <bits/stdc++.h>

#define N 100005

using namespace std;

int n, k;
struct node {
    int x, v;
    bool operator < (const node &t) const {
        return x < t.x;
    }
}a[N];

long double stk[N];

bool check(long double mid) {
    int m = 0; stk[0] = -1e20;
    for(int i = 1; i <= n; ++i) {
        long double now = a[i].x + mid * a[i].v; 
        if(stk[m] < now) 
            stk[++m] = now;
        else 
            stk[lower_bound(stk + 1, stk + 1 + m, now) - stk] = now;
    }
    return (n - m <= k);
}

int main() {
    
    cin >> n >> k;

    char tmp;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i].x >> a[i].v >> tmp;
        if(tmp == 'L')
            a[i].v = -a[i].v;
    }

    sort(a + 1, a + 1 + n);

    long double l = 0, r = 2e9;
    for(int T = 0; T <= 50; ++T) {
        long double mid = (l + r) * 0.5;
        if(check(mid))
            l = mid; 
        else 
            r = mid;
    }
    
    if(check(l + 1)) 
        cout << "Infinity\n";
    else 
        printf("%.15Lf\n", l);
    return 0;
}