#include <bits/stdc++.h>

#define N 1000010

using namespace std;

int n, m;
int a[N];
int l, r;

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') 
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar();
    }
    return x * f;
}

inline void write(int x) {
    if(x < 0)
        putchar('-'), x = -x;
    if(x >9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}

int main() {

    n = read(), m = read();

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    while(m--) {
        l = read(), r = read();
        if(l > r) {
            swap(l, r);
        }
        if(l == r) {
            write(0);
            puchar('\n');
            continue;
        }
        
    }

    return 0;
}