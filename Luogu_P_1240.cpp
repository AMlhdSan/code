#include <bits/stdc++.h>
using namespace std;

inline long long read() {
    long long x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') { x = x * 10 + (ch ^ 48); ch = getchar(); }
    return x * f;
}

inline void write(__int128 x) {
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(__int128 x) {
    write(x);
    putchar('\n');
}

__int128 floor_sqrt(__int128 x) {
    __int128 l = 0, r = x;
    while(l <= r) {
        __int128 mid = (l + r) >> 1;
        if(mid * mid <= x) l = mid + 1;
        else r = mid - 1;
        if(l >= r) 

    }
    return r;
}

int main() {
    long long n64 = read();
    n64--;
    __int128 n = n64, n2 = n * n;
    __int128 ans = 0;

    __int128 t = n;
    while(t >= 0) {
        // Solve x^2 <= n^2 - t^2 <=> x <= sqrt(n^2 - t^2)
        __int128 l2 = n2 - (t + 1) * (t + 1) + 1;
        __int128 r2 = n2 - t * t;
        __int128 l = floor_sqrt(max(l2, (__int128)0));
        if(r2 < 0) { t--; continue; }
        __int128 lx = floor_sqrt(max(l2, (__int128)0));
        __int128 rx = floor_sqrt(r2);
        if(lx > rx) { t--; continue; }
        __int128 cnt = rx - lx + 1;
        ans += cnt * (2 * t + 1);
        t--;
    }

    ans = ans * 4 - 3; // 4象限，对称，减去重复原点
    writeln(ans);
    return 0;
}
