#include <bits/stdc++.h>

#define N 100010
#define int long long

using namespace std;

int n;
int a[N];
int stk[N];
int sum[N];
int l[N], r[N];

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-')
            f = -1;
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

    for(int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + a[i];
    }

    int top = 0;

    stk[0] = 0;

    for(int i = 1; i <= n; ++i) {
        while(top && a[stk[top]] >= a[i]) {
            --top;
        }
        l[i] = stk[top];
        stk[++top] = i;
    }

    top = 0;
    stk[0] = n + 1;

    for(int i = n; i >= 1; --i) {
        while(top && a[stk[top]] >= a[i]) {
            --top;
        }
        r[i] = stk[top] - 1;
        stk[++top] = i;
    }

    int maxx = 0;

    for(int i = 1; i <= n; ++i) {
        maxx = max(maxx, a[i] * (sum[r[i]] - sum[l[i]]));
    }

    cout << maxx << endl;

    return 0;
}