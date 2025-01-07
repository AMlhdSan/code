#include <bits/stdc++.h>

#define N 300010

using namespace std;

int n, k;
int num = 0;
int a[N];
int maxx[N]/*最大的*/, maxxx[N]/*次大的*/;

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

    num = pow(2, n) - 1;
    k = num;

    for(int i = 0; i <= num; ++i) {
        a[i] = read();
    }

    for(int i = 0; i < n; ++i) {
        for(int i = 1; i <= k; ++i) {
            
        }
    }

    return 0;
}