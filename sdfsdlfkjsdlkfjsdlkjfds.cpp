#include <bits/stdc++.h>

#define N 110

using namespace std;

int T;
int n;
int a[N];
int sta[N];

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

inline void dfs(int now, int x) {
    if(now == n + 1) {
        int sum = 0;
        for(int i = 1; i <= n; ++i) {
            sum += a[i] * i;
        }
        if(sum == x) {
            
        }
    }
    for(int i = -1; i <= 1; ++i) {
        a[now] = i;
        dfs(now + 1);
    }
}

inline bool find(int x) {
    dfs(1, x);
}

inline void solve() {
    n = read();
    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }
    for(int i = 1; i <= n; ++i) {
        if(find(i)) {
            puts("YES");
            return;
        }
    }
    puts("NO");
}

int main() {

    T = read();
    while(T--) {
        solve();
    }

    return 0;
}