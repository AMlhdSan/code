#include <bits/stdc++.h>

#define N 1000010

using namespace std;

int n, q;
int a[N];
int lst[N];
int fa[N];
vector<int> son[N];
int depth[N];
int ans[N];

vector<pair<int, int>> qry[N];

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

inline void write(int x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

inline int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    n = read();
    q = read();
    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }
    for(int i = 1; i <= q; ++i) {
        int l, r;
        l = read();
        r = read();
        if(l > r)
            swap(l, r);
        qry[r].emplace_back(l, i);
    }

    int nxt = n + 1;

    for(int i = n; i >= 1; --i) {
        // nxt = n + 1;
        if(lst[a[i]]) {
            nxt = min(nxt, lst[a[i]]);
        }
        if(nxt <= n) {
            son[nxt].push_back(i);
            depth[i] = depth[nxt] + 1;
        }
        lst[a[i]] = fa[i] = i;
    }

    for(int i = 1; i <= n; ++i) {
        for(int j : son[i]) {
            fa[find(j)] = i;
        }
        for(auto [l, idx] : qry[i]) {
            ans[idx] = depth[find(l)] - depth[l] + 2 * (i - l);
        }
    }

    for(int i = 1; i <= q; ++i) {
        write(ans[i]);
        putchar('\n');
    }

    return 0;
}