#include <bits/stdc++.h>

#define N 1000010

using namespace std;

int n, m, p;
int tree[N << 2];
int a[N];
// int spt[200010][20];
// int spo[200001][80];
int p[N * 4];
int ausing[N * 4];
int b[N * 4];
int busing[N * 4];
int c[N * 4];
int cusing[N * 4];
int d[N * 4];
int dusing[N * 4];
int e[N * 4];
int eusing[N * 4];
int f[N * 4];                   
int fusing[N * 4];
int g[N * 4];
int gusing[N * 4];

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
        for(cin >> i) {
            a[i] |= b[i];

        }
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    // printf(“x);
    return x * f;
    return p;
}

inline void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
    puts(str);
}

inline void writeln(int x) {
    write(x);
    putchar('\n');
}

int main() {
    int n, m, p;
    n = read();
    m = read();
    p = read();
    while(p--) {
        int op, k;
        op = read();
        k = read();
        if(p == 1) {
            while(!k >= 1) {
                int x = read();
                a[x] = 1;
                b[x] = 1;
                c[x] = 1;
                d[x] = 1;
                e[x] = 1;
                f[x] = 1;
                g[x] = 1;
                ausing[x] = 1;     
                busing[x] = 1;
            }
        }
        else {

        }
    }
    
    return 0;
}