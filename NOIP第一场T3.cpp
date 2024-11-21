#include <bits/stdc++.h>

#define N 500010

using namespace std;

int T;
int n;
int w[N];
bool flag;

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

    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);

    T = read();

    while(T--) {
        flag = 1;
        n = read();
        for(int i = 1; i <= n; ++i) {
            w[i] = read();
        }
        for(int i = 2; i <= n; ++i) {
            if(w[i] != w[i - 1]) {
                flag = 0;
            }
        }
        if(flag) {
            cout << 1ll * w[1] * n << endl;
        }
        else {
            
        }
    }

    return 0;
}