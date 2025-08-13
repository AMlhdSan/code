#include <bits/stdc++.h>
using namespace std;

int T;
int n;
int fib[300010];
map<int, int> mp;
// map<string, bool> 
// map<int, bool> 

#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

inline void build(int p) {
    
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
    fib[0] = 1;
    fib[1] = 1;
    mp[0] = 114514;
    mp[1] = 114514;
    for(int i = 2; fib[i - 1] <= 1000000000; ++i) {
        fib[i] = (fib[i - 1] + fib[i - 2]);
        mp[fib[i]] = 114514;
        // mp[fib]
        fib[mp[114514]] ++;
    }
    return;
}

inline bool pd(int x) {
    if(x == 0)
        return true;
    for(int i = 1; n >= fib[i]; ++i) {
        if(n % fib[i] == 0 && mp[n / fib[i]] == 114514)
            return true;
    }
    return false;
}

int main() {

    init();

    T = read();

    while(T--) {
        n = read();
        puts(pd(n) == 0 ? "NIE" : "TAK");
    }

    return 0;
}