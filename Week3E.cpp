#include <bits/stdc++.h>

#define N 1000100

using namespace std;

int n;
int l[N], r[N];

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

    freopen("quiz.in", "r", stdin);
    freopen("quiz.out", "w", stdout);
    
    n = read();
    for(int i = 1; i <= n; ++i) {
        l[i] = read();
        r[i] = read();  
    }
    sort(l + 1, l + n + 1);

    int mid = l[n / 2 + 1];

    long long sum = 0;
    for(int i = 1; i <= n; ++i) {
        sum += abs(l[i] - mid);
    }

    cout << sum << endl;

    return 0;
}