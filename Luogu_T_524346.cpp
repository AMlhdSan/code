#include <bits/stdc++.h>

#define MOD 1000000007
#define N 200001

using namespace std;

int n;
int m[N];
long long a;
long long sum = 1;
long long dp[N];

struct p {
    int x, y;
}d[N];

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
        x = (x << 3) + (x << 1) + (ch - '0');
        ch = getchar();
    }
    return x * f;
}

int main() {

    n = read();

    for(int i = 1; i <= n; ++i) {
        m[i] = read();
    }

    for(int i = 1; i <= n; ++i) {
        a = read();
        d[i].x = max(m[i] - a, a[i] - 1);
        d[i].y = min(a - 1, m[i] - a);
    }

    cout << dp[n] << endl;


    return 0;
}