#include <bits/stdc++.h>

#define N 1000010

using namespace std;

int n, q;
int a[N];

struct node {
    int l, r;
}qry[N];

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

bool cmp(node a, node b) {
    return a.r < b.r;
}

int main() {

    n = read();
    q = read();

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    for(int i = 1; i <= q; ++i) {
        qry[i].l = read();
        qry[i].r = read();
    }

    sort(qry + 1, qry + q + 1, cmp);

    return 0;
}