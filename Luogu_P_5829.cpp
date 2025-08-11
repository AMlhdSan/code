#include <bits/stdc++.h>

#define N 1000010

using namespace std;

string s;
int m;

int kmp[N];

int nxt[N], head[N], to[N], e = 0;

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

inline void add_edge(int u, int v) {
    nxt[++e] = head[u];
    head[u] = e;
    to[e] = v;
}

inline void work(string str) {

    int n = str.size();

    // 求出 kmp

    kmp[0] = 0;

    for(int i = 1; i < n; ++i) {
        int j = kmp[i - 1];
        while(j > 0 && str[i] != str[j])
            j = kmp[j - 1];
        if(str[i] == str[j])
            ++j;
        kmp[i] = j;
    }

    // 建树


}

inline int solve(int u, int v) { // 求 u, v 两点的最近公共祖先

}

int main() {

    cin >> s;

    work(s);

    m = read();

    while(m--) {
        int p, q;
        p = read();
        q = read();
        writeln(solve(p, q));
    }

    return 0;
}