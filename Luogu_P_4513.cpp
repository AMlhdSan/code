#include <bits/stdc++.h>

#define N 500005

using namespace std;

int n, m;
int a[N];

inline int read() {
    int f = 1, x = 0;
    char ch = 0;
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch - '0');
        ch = getchar();
    }
    return x * f;
}

int main() {

    cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    build();

    return 0;
}