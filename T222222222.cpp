#include <bits/stdc++.h>

#define N 100010
#define M 1000100
#define PII pair<int, int> 

using namespace std;

vector<PII > edges[N << 2];
int n, m, s, x;
int e[N], c[N];
int a[N], b[N], t[N];

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
inline void write(int x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

void add_edge(int u, int v, int c) {
    edges[u].push_back(make_pair(c, v));
}

int main() {

    n = read();
    m = read();
    s = read();
    x = read();

    for(int i = 1; i <= n; ++i) {
        e[i] = read();
        add_edge(i + n, i, e[i]);
        add_edge(i, i + n, e[i]);
    }
    for(int i = 1; i <= n; ++i) {
        c[i] = read();
    }

    for(int i = 1; i <= r; ++i) {
        a[i] = read();
        b[i] = read();
        t[i] = read();
        add_edge(a[i], b[i], t[i]);
        add_edge(b[i], b[i], t[i]);
    }

    return 0;
}