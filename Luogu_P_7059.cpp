#include <bits/stdc++.h>

#define N 110

using namespace std;

int a[N][N];
int sumn[N], summ[N];
int n, m;

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
    m = read();

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            a[i][j] = read();
            sumn[i] += a[i][j];
            summ[j] += a[i][j];
        }
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            // up:
            bool flag1 = true;
            for(int k = i; k >= 1; --k) {
                if(a[k][j] == 1) {
                    flag1 = false;
                    break;
                }
            }
        }
    }

    return 0;
}