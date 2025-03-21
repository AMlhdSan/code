#include <bits/stdc++.h>

#define PII pair<int, int>
#define MP make_pair
#define PB push_back
#define FI first
#define SE second

using namespace std;

int n, k;
int q;
vector<PII> edges[100010];

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

inline void solve(int s, int t) {
    
}

int main() {

    n = read();
    k = read();
    q = read();

    for(int i = 1; i <= n - 1; ++i) {
        int u, v, w;
        u = read();
        v = read();
        w = read();
        edges[u].PB(MP(v, w));
        edges[v].PB(MP(u, w));
    }

    while(q--) {
        int s, t;
        s = read();
        t = read();
        writeln(solve(s, t));
    }

    return 0;
}