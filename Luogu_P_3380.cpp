#include <bits/stdc++.h>

#define int long long
#define N 50010

using namespace std;

int n, m;
int a[N];

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

inline void op1() {
    int l, r, k;
    l = read();
    r = read();
    k = read();

}

inline void op2() {
    int l, r, k;
    l = read();
    r = read();
    k = read();

}

inline void op3() {
    int pos, k;
    pos
}

inline void op4() {

}

inline void op5() {

}

signed main() {

    n = read();
    m = read();

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    while(m--) {
        int op;
        op = read();
        if(op == 1) {

        }
        else if(op == 2) {

        }
        else if(op == 3) {

        }
        else if(op == 4) {
            
        }
        else if(op == 5) {

        }
    }

    return 0;
}