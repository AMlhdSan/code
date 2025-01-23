#include <bits/stdc++.h>

#define N 200010

using namespace std;

struct node {
    int l, r, p;
};

int T;
int t;
int n;
int k;
node a[N];
int b[N * 3];
int sum = 0;
bool flag;
int fa[N];

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

inline void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
        fa[x] = y;
    }
}

int main() {

    T = 1;
    while(T--) {
        n = read();
        k = read();
        memset(b, 0, sizeof(b));
        memset(fa, 0, sizeof(fa));
        memset(a, 0, sizeof(a));
        sum = 0;
        t = 0;
        flag = 0;
        for(int i = 1; i <= n; ++i) {
            a[i].l = read();
            a[i].r = read();
            a[i].p = read();
            b[++sum] = a[i].l;
            b[++sum] = a[i].r;
        }
        sort(b + 1, b + 1 + sum);
        t = unique(b + 1, b + 1 + sum) - b;
        for(int i = 1; i <= n; ++i) {
            a[i].l = lower_bound(b + 1, b + 1 + t, a[i].l) - b;
            a[i].r = lower_bound(b + 1, b + 1 + t, a[i].r) - b;
        }
        for(int i = 1; i <= t; ++i) {
            fa[i] = i;
        }
        sort(a + 1, a + 1 + n, cmp);
        for(int i = 1; i <= n; ++i) {
            if(a[i].p == 1) {
                merge(a[i].l, a[i].r);
            }
            else {
                if(find(a[i].l) == find(a[i].r)) {
                    puts("NO");
                    flag = 1;
                    break;
                }
            }
        }
        if(!flag) {
            puts("YES");
        }
    }

    return 0;
}
