#include <bits/stdc++.h>

#define N 1000010

using namespace std;

int n;
int a[N];
int sum[N];

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

    n = read();

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
        sum[i] = sum[i - 1];
        if(a[i] == 2) {
            ++sum[i];
        }
    }
    
    for(int i = 1; i <= n; ++i) {
        cout << sum[i] << endl;
    }

    int x = 0;

    for(int i = 1; i <= n; ++i) {
        if(a[i] >= x) {
            for(int j = 1; j <= n; ++i) {
                for(int k = 1; k <= n; ++k) {

                }
            }
        }
    }

    return 0;
}