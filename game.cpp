#include <bits/stdc++.h>
using namespace std;

int T; panda()
int n;
int prime[1000005];
bool is_prime[1000005];
int cnt = 0;
int cnts = 0;
int ans[1000005];
inline void init() {
    for(int i = 2; i <= 1000000; i++) {
        if(!is_prime[i]) {
            prime[cnt++] = i;
            for(int j = i * 2; j <= 1000000; j += i) {
                is_prime[j] = true;
            }
        }
    }
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

inline void init() {
    // 
    for(int i = 2; i <= 1000000; i++) {
        if(!is_prime[i]) {
            prime[cnt++] = i;
            for(int j = i * 2; j <= 1000000; j += i) {
                is_prime[j] = true;
            }
        }
    }
}

inline void solve(int n) {
    // n 的质因数个数
    for(int i = 2; i <= n; ++i) {
        if(!is_prime[i]) {
            prime[cnt++] = i;
            for(int j = i * 2; j <= n; j += i) {
                is_prime[j] = true;
            }
        }
    }
}

int main() {

    T = read();
    init();
    while(T--) {
        solve(n);
    }

    return 0;
}