#include <bits/stdc++.h>


#define int long long

using namespace std;

int n;
int sum = 0;
int a, b;
int xo[100010][50];

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

signed main() {

    n = read();

    for(int i = 1; i <= n; ++i) {
        int x = read();
        for(int j = 0; j <= 31; ++j) {
            xo[i][j] = xo[i - 1][j] ^ ((x >> j) & 1);
        }
    }

    for(int i = 0; i <= 31; ++i) {
        a = 0;
        for(int j = 0; j <= n; ++j) {
            if(xo[j][i] == 0)
                ++a;
        }
        sum += a * (n - a + 1) * (1 << i);
    }

    cout << sum << endl;
    return 0;
}