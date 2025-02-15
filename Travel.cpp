#include <bits/stdc++.h>

#define N 200010

using namespace std;

int n, k, xx[N], yy[N], d[N], tot, head[N];

struct edge {
    int to, w, next;
} e[N << 2];

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

inline void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(int x) {
    write(x);
    putchar('\n');
}


struct data {
    int x, y;
    inline void readt() {
        int a, b;
        a = read(), b = read();
        x = a, y = b;
    }
} a[N];

inline bool cmpx(int i, int j) {
    return a[i].x < a[j].x;
}

inline bool cmpy(int i, int j) {
    return a[i].y < a[j].y;
}

inline void addege(int x, int y, int z) {
    e[++tot] = {y, z, head[x]};
    head[x] = tot;
}

inline void add(int x, int y, int z) {
    addege(x, y, z);
    addege(y, x, z);
}

struct node {
    int x, d;
    inline bool operator<(const node &rhs) const {
        return d > rhs.d;
    }
    node(int x_, int d_) : x(x_), d(d_) {}
};

priority_queue<node> Q;

inline void dijk() {
    for (int i = 0; i <= n; i++) d[i] = 0x7fffffff;
    d[0] = 0;
    Q.emplace(0, 0);
    while (!Q.empty()) {
        node t = Q.top();
        Q.pop();
        if (d[t.x] != t.d) continue;
        for (int i = head[t.x]; i; i = e[i].next) {
            int v = e[i].to, w = e[i].w;
            if (d[v] > d[t.x] + w) {
                d[v] = d[t.x] + w;
                Q.emplace(v, d[v]);
            }
        }
    }
}

int main() {
    // freopen("Travel.in", "r", stdin);
    // freopen("Travel.out", "w", stdout);
    n = read();
    for (int i = 0; i < n; i++) {
        a[i].readt();
        xx[i] = yy[i] = i;
    }
    sort(xx, xx + n, cmpx);
    for (int i = 0; i < n - 1; i++) {
        int x1 = xx[i], x2 = xx[i + 1];
        int dx = a[x2].x - a[x1].x, dy = abs(a[x1].y - a[x2].y);
        if (dx <= dy) add(x1, x2, dx);
    }
    sort(yy, yy + n, cmpy);
    for (int i = 0; i < n - 1; i++) {
        int y1 = yy[i], y2 = yy[i + 1];
        int dy = a[y2].y - a[y1].y, dx = abs(a[y1].x - a[y2].x);
        if (dy <= dx) add(y1, y2, dy);
    }
    dijk();
    writeln(d[n - 1]);
    return 0;
}
