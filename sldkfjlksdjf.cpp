#include <bits/stdc++.h>

#define N 1000010

using namespace std;

int n, m, p;
int tree[N << 2];
int a[N];
// int spt[200010][20];
// int spo[200001][80];

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    // printf(“x);
    return x * f;
    
}

inline void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
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

    
    return 0;
}