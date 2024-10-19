#include <bits/stdc++.h>

#define N 1000001

using namespace std;

int n, q;
int x[N];
int a, b;
bool flag;
int f1, f2;

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
    freopen("function.out", "w", stdout);

    cin >> n >> q;

    for(int i = 1; i <= n; ++i) {
        x[i] = read();
    }

    while(q--) {
        a = read();
        b = read();

        flag = 0;
        f2 = (x[1] ^ a) - b;

        for(int i = 1; i < n; ++i) {
            f1 = f2;
            f2 = ((x[i + 1] ^ a) - b);
            if((pd(f1, f2))) {
                cout << i << endl;
                flag = 1;
                break;
            }
        }
        if(!flag) {
            cout << -1 << endl;
        }
    }

    

    return 0;
}