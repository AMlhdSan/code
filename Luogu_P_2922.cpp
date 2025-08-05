#include <bits/stdc++.h>
using namespace std;

int m, n;
// int cnt1[50010];
// int inf1[50010];
int tnxt[10010][2];
int exi[500100];
int fa[500100];
int tot = 1;
int ansup[500100];
int ansdown[500100];

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

inline void dfs1(int p, int pre) {
    // fa[p] = pre;
    ansup[p] += ansup[pre];
    for(int i = 0; i <= 1; ++i) {
        if(tnxt[p][i]) {
            dfs1(tnxt[p][i], p);
        }
    }
}

inline void dfs2(int p, int pre) {
    // fa[p] = pre;
    ansdown[pre] += ansdown[p];
    for(int i = 0; i <= 1; ++i) {
        if(exi[tnxt[p][i]]) {
            dfs2(tnxt[p][i], p);
        }
    }
}

int main() {

    m = read();
    n = read();

    for(int i = 1; i <= m; ++i) {
        int b, c;
        b = read();
        int u = 1;
        for(int j = 1; j <= b; ++j) {
            c = read();
            if(!tnxt[u][c]) {
                tnxt[u][c] = ++tot;
            }
            u = tnxt[u][c];
        }
        ++exi[u];
    }
    for(int i = 1; i <= tot; ++i) {
        ansup[i] = exi[i];
        write(ansup[i]);
        putchar(' ');
    }

    dfs1(1, 0);
    dfs2(1, 0);

    while(n--) {
        int uu = 1;
        int b, c, u;
        b = read();
        for(int i = 1; i <= b; ++i) {
            c = read();
            uu = tnxt[uu][c];
            if(!uu) {
                u = uu;
            }
        }
        if(uu)
            u = uu;
        writeln(ansup[u] + ansdown[u] - exi[u]);
    }

    return 0;
}