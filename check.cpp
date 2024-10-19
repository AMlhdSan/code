#include <bits/stdc++.h>

#define N 1000001

using namespace std;

int n, q;
int x[N];
int a, b;

inline int read() {
    int w = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        w = (w << 3) + (w << 1) + (ch - '0');
        ch = getchar();
    }
    return w * f;
}

int main() {

    freopen("function.in", "r", stdin);

    cin >> n >> q;

    for(int i = 1; i <= n; ++i) {
        x[i] = read();
    }

    for(int i = 1; i <= n; ++i) {
        freopen("function.in", "r", stdin);
        a = read();
        b = read();
        freopen("function.out", "r", stdin);
        int tmp;
        tmp = read();
        if(tmp != -1) {
            if(((x[tmp] ^ a) - b) * ((x[tmp + 1] ^ a) - b) <= 0) {
                putchar('O');
                continue;
            }
            else {
                cout << "WA" << endl;
                return 0;
            }
        }
        else {
            freopen("function.ans", "r", stdin);
            for(int k = 1; k < i; ++k) {
                tmp = read();
            }
            tmp = read();
            if(tmp == -1) {
                putchar('O');
                continue;
            }
            else {
                cout << "WA" << endl;
                return 0;
            }
        }
    }

    

    return 0;
}