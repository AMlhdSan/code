#include <bits/stdc++.h>

#define N 200010

using namespace std;

int n, q;
int a[100010];

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

int main() {

    n = read();
    q = read();

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    while(q--) {
        int l, r;
        l = read();
        r = read();
    }
    
    return 0;
}