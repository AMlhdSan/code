#include <bits/stdc++.h>

#define N 200001

using namespace std;

int n;
int a, b;
int len[N << 1];
long long maxx, cmaxx;

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
        x = (x << 3) + (x << 1) + (ch - '0');
        ch = getchar();
    }
    return x * f;
}

int main() {

    n = read();

    for(int i = 1; i <= n; ++i) {
        a = read();
        b = read();
        len[i] = a - b;
        len[i + n] = b;
    }

    maxx = len[1], cmaxx = len[2];
    if(maxx < cmaxx) {
        swap(maxx, cmaxx);
    }

    for(int i = 3; i <= (n << 1); ++i) {
        if(len[i] >= maxx) {
            cmaxx = maxx;
            maxx = len[i];
        }
        else if(len[i] >= cmaxx) {
            cmaxx = len[i];
        }
    }

    long long ans = maxx + cmaxx;
    
    cout << ans << endl;

    return 0;
}