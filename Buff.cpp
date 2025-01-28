#include<bits/stdc++.h>

#define int long long

using namespace std;

int T;
int n;
int tmp;
int x, y, z;

inline int read() {
    int x = 0, y = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-')
            y = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * y;
}

inline void write(int x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

signed main() {

    freopen("Buff.in", "r", stdin);
    freopen("Buff.out", "w", stdout);

    T = read();
    while(T--) {
        x = y = z = 0;

        n = read();

        for(int i = 1; i <= n; ++i) {
            tmp = read();
            if(tmp > 0) {
                ++x;
            }
            else {
                ++y;
            }
            z += tmp == 1;
        }
        write(x * y + z * (x - z) + z * (z - 1) / 2);
        putchar('\n');
    }

    return 0;
}