#include <bits/stdc++.h>

#define N 100010

using namespace std;

int n;
int l[N], r[N];

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

int main() {

    n = read();
    for(int i = 1; i <= n; ++i) {
        l[i] = read();
        r[i] = read();
        
    }

    return 0;
}