#include <bits/stdc++.h>
using namespace std;

int T;
int n, x;
int a[100010];

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

int main() {

    T = read();
    while(T--) {
        n = read();
        x = read();
        bool flag = false;
        int ft, lt;
        for (int i = 1; i <= n; i++) {
            a[i] = read();
            if(a[i] == 1) {
                if(!flag) {
                    ft = i;
                    flag = true;
                }
                lt = i;
            }
        }
        if(lt - ft + 1 > x) {
            puts("NO");
        }
        else {
            puts("YES");
        }
    }

    return 0;
}