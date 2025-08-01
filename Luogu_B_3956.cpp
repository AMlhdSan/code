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

    int n;
    string T;
    n = read();
    cin >> T;
    T = " " + T; // 1-based indexing


    int sum = 0;

    for(int i = 1; i <= n; ++i) {
        if(T[i] <= 'z' && T[i] >= 'a') {
            sum += T[i] - 'a' + 1;
        } else if(T[i] <= 'Z' && T[i] >= 'A') {
            sum += -T[i];
        }
    }
    cout << sum << endl;
    return 0;
}