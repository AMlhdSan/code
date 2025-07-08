#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;
ll sum = 0;

inline ll read() {
    ll w = 0, f = 1;
    char ch = getchar_unlocked();
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = getchar_unlocked();
    }
    while(ch >= '0' && ch <= '9') {
        w = (w << 3) + (w << 1) + (ch - '0');
        ch = getchar_unlocked();
    }
    return w * f;
}

inline void write(ll x) {
    if(x < 0) {
        putchar_unlocked('-');
        x = -x;
    }
    if(x > 9) {
        write(x / 10);
    }
    putchar_unlocked(x % 10 + '0');
}

inline void writeln(ll x) {
    write(x);
    putchar_unlocked('\n');
}

int main() {

    n = read();

    for(int i = 1; i <= n; ++i) {
        sum += read();
    }

    writeln(sum);

    return 0;
}