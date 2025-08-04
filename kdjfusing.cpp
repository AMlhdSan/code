#include <bits/stdc++.h>
using namespace std;

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
    int T = read();
    while (T--) {
        string s;
        cin >> s;
        int c0 = 0, c1 = 0;
        for (char ch : s) {
            if (ch == '0') c0++;
            else if (ch == '1') c1++;
        }
        for (char ch : s) {
            if (ch == '2') {
                if (c0 < c1) c0++;
                else c1++;
            }
        }
        writeln(abs(c0 - c1));
    }
    return 0;
}
