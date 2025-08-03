#include <bits/stdc++.h>

#define ll long long

using namespace std;
char buf[1 << 23], *p1 = buf, *p2 = buf;
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)

int n;
int m, p;
int p;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng2(chrono::steady_clock::now().time_since_epoch().count() ^ 0x5a5a5a5a5a5a5a5a);

int p1 = rng() % (1e9 + 7);
int p2 = rng2() % (1e9 + 7);
int p3 = rng() % (1e9 + 7);
int p4 = rng2() % (1e9 + 7);

inline ll read() {
    ll x = 0, f = 1;
    char c = gc();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = gc();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = gc();
    }
    return x * f;
}

inline void write(ll x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(ll x) {
    write(x);
    putchar('\n');
}

int main() {

    n = read();

    return 0;
}