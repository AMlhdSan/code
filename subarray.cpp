#include <bits/stdc++.h>

#define N 100010

using namespace std;

int T;
int n, k;
int a[N];
int c[N];

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

int main() {

    freopen("subarray.in", "r", stdin);
    freopen("subarray.out", "w", stdout);

    T = read();
    while(T--) {
        n = read();
        k = read();
        a[0] = 0;
        int maxx = 0;
        int cnt = 0;
        for(int i = 1; i <= n; ++i) {
            a[i] = read();
        }
        for(int i = 1; i <= n; ++i) {
            c[i] = a[i] - a[i - 1];
        }
        for(int i = 1; i <= n; ++i) {
            if(c[i] == 1) {
                ++cnt;
                maxx = max(maxx, cnt);
            }
            else {
                // maxx = max(maxx, cnt);
                cnt = 0;
            }
        }
        cout << maxx << endl;
    }

    return 0;
}