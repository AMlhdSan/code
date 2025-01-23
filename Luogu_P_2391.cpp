#include<bits/stdc++.h>

#define N 1000010

using namespace std;

int n, m, p, q;
int fa[N];
int a[N];

inline int find(int x) { 
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

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

int main() {

    n = read();
    m = read();
    p = read();
    q = read();
    for(int i = 1; i <= n; ++i) {
        fa[i] = i;
    }

    for(int i = m; i >= 1; --i) {
        int l = (i * p + q) % n + 1;
        int r = (i * q + p) % n + 1;
        if(l > r) 
            swap(l, r);
        for(int j = r; j >= l;) {
            int t = find(j);
            if(t == j) {
                a[j] = i;
                fa[j] = find(j - 1);
            }
            j = fa[j];
        }
    }

    for(int i = 1; i <= n; ++i) {
        write(a[i]);
        putchar('\n');
    }

    return 0;
}