#include <bits/stdc++.h>

#define N 10000001

using namespace std;

int n, m;
long long c[N];
int l, r, s, e;
long long maxx = 0, ans = 0;
long long a = 0, b = 0;

inline int read() {
    int x = 0, f = 1;
    char ch = 0;
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch - '0');
        ch = getchar();
    }
    return x * f;
}

int main() {

    cin >> n >> m;

    while(m--) {
        l = read();
        r = read();
        s = read();
        e = read();

        int d = (e - s) / (r - l);

        c[l] += s;
        c[l + 1] += d - s;
        c[r + 1] -= d + e;
        c[r + 2] += e;
    }

    for(int i = 1; i <= n; ++i) {
        maxx = max(maxx, a += (b += c[i]));
        ans ^= a;
    }

    cout << ans << ' ' << maxx << endl;

    return 0;
}