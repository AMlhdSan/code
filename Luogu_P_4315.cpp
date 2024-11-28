// 策略：一条边的权值赋给儿子节点。
#include <bits/stdc++.h>

#define N 100010
#define ENDL putchar('\n')
#define pc putchar
#define il inline

using namespace std;

int n;
int nxt[N], head[N], ww[N], to[N], w[N];
int top[N], son[N], id[N], wt[N];
int e = 0, cnt = 0;
int dep[N], fa[N], si[N];

il int read() {
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

il void write(int x) {
    if(x < 0) {
        x = -x;
        pc('-');
    }
    if(x >= 10) {
        write(x / 10);
    }
    pc(x % 10 + '0');
}

il void add_edge(int u, int v, int c) {
    nxt[++e] = head[u];
    head[u] = e;
    to[e] = v;
    ww[e] = c;
}

il void dfs1(int p, int pre, int depth) {
    fa[p] = pre;
    dep[p] = depth;
    si[p] = 1;

    int maxx = -1;

    for(int i = head[p]; i; i = nxt[i]) {
        int v = to[i];
        if(v != pre) {
            dfs1(v, p, depth + 1);
            w[v] = ww[i];
            si[p] += si[v];
            if(si[v] > maxx) {
                maxx = si[v];
                son[p] = v;
            }
        }
    }
}

il void dfs2(int p, int topp) {
    id[++cnt] = p;
    wt[cnt] = w[p];
    top[p] = topp;
    if(!son[p]) {
        return;
    }
    dfs2(son[p], topp);

    for(int i = head[p]; i; i = nxt[i]) {
        int v = to[i];
    }
}

int main() {

    n = read();

    for(int i = 1; i <= n - 1; ++i) {
        int u, v, c;
        u = read();
        v = read();
        add_edge(u, v, c);
        add_edge(v, u, c);
    }



    return 0;
}