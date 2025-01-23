#include <bits/stdc++.h>

#define N 100010
#define int long long

using namespace std;

int n;
long long val[N];
int fa[N];
int a[N];
int sum[N];
int ans[N];

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

inline int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

inline void merge(int x, int y, int now) {
    x = find(x);
    y = find(y);
    if(x != y) {
        fa[x] = y;
        sum[y] += sum[x];
        // ans[now] = max(ans[now], sum[y]);
    }
}

signed main() {

    n = read();

    for(int i = 1; i <= n; ++i) {
        val[i] = read();
    }

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    // ans[n] = 0;

    for(int i = n; i >= 1; --i) {
        fa[a[i]] = a[i];
        sum[a[i]] = val[a[i]];
        // ans[i] = ans[i + 1];
        if(fa[a[i] - 1]) {
            merge(a[i] - 1, a[i], i);
        }
        if(fa[a[i] + 1]) {
            merge(a[i] + 1, a[i], i);
        }
        ans[i] = max(ans[i + 1], sum[find(a[i])]);
    }

    for(int i = 2; i <= n; ++i) {
        printf("%d\n", ans[i]);
    }

    puts("0");

    return 0;
}