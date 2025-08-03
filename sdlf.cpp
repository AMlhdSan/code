#include <bits/stdc++.h>
using namespace std;

int T;
int n;
int a[200010];
int minn = 0x7fffffff;

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

inline void tg()

inline void dfs(int pos) {
    if(pos > n) {
        tg();
        return;
    }
    if(a[i] == 2) {

    }
}

inline void solve1() {
    dfs(1, 0);
}

inline void solve2() {

}

int main() {

    T = read();

    while(T--) {
        minn = 0x7fffffff;
        string str;
        cin >> str;
        n = str.size();
        for (int i = 0; i < n; i++) {
            a[i + 1] = str[i] - '0';
        }
        if(n <= 20) {
            solve1(); // 暴力.
        } 
        else {
            solve2(); // 当做没有 2 的情况进行处理.
        }
    }
    
    return 0;
}
