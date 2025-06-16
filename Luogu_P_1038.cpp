#include <bits/stdc++.h>

using namespace std;

const int N = 110, M = 30010;
int n, p, cnt, head[M], c[N], u[N], in[N], out[N];
bool vis[N];
struct Edge {
    int to, w, nxt;
} e[M];
queue<int> q;

struct Node {
    int id;
    bool operator < (const Node &b) const {
        return id > b.id;
    }
};
priority_queue<Node> ans;

void add(int x, int y, int w) {
    e[++cnt] = {y, w, head[x]};
    head[x] = cnt;
}

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
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

int main() {
    
    n = read();
    p = read();

    for (int i = 1; i <= n; i++) {
        c[i] = read();
        u[i] = read();
        if (c[i] != 0) {
            q.push(i);
            vis[i] = 1;
        }
        else {
            c[i] -= u[i];
        }
    }
    for (int i = 1; i <= p; i++) {
        int x, y, w;
        x = read();
        y = read();
        w = read();
        add(x, y, w);
        in[y]++;
        out[x]++;
    }

    while (!q.empty()) {
        int x = q.front(); q.pop();
        vis[x] = 0;
        if (c[x] < 0) continue;
        for (int i = head[x]; i; i = e[i].nxt) {
            int y = e[i].to;
            c[y] += e[i].w * c[x];
            if (!vis[y]) q.push(y), vis[y] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (out[i] == 0 && c[i] > 0) {
            ans.push({i});
        }
    }

    if (ans.empty())
        puts("NULL");

    else while (!ans.empty()) {
        int x = ans.top().id; ans.pop();
        write(x);
        putchar(' ');
        writeln(c[x]);
    }
    return 0;
}