#include <bits/stdc++.h>

#define N 500010
#define int long long
#define PII pair<int, int>

using namespace std;

int n, m, k;
int a[N], b[N];
int sum = 0;
PII c[N], cntc = 0;
PII d[N], cntd = 0;

inline bool cmpc(PII x, PII y) {
    return x.first < y.first;
}

inline bool cmpd(PII x, PII y) {
    return x.first > y.first;
}

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

signed main() {

    n = read();
    k = read();
    m = read();

    for(int i = 1; i <= k; ++i) {
        a[i] = read();
        b[i] = read();
        if(a[i] == 0) {
            
        }
    }
    
    return 0;
}