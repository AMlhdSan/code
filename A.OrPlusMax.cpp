#include <bits/stdc++.h>

#define N 300010

using namespace std;

int n, k;
int num = 0;
int a[N];
int maxx[N]/*最大的*/, maxxx[N]/*次大的*/;

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

inline pair<int, int> choose(int x, int y, int p, int q) {
    int tp[5] = {0, x, y, p, q};
    sort(tp + 1, tp + 4 + 1);
    return make_pair(tp[3], tp[4]);
}

inline void write(int x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

int main() {

    n = read();

    num = (1 << n) - 1;
    k = num;

    for(int i = 0; i <= num; ++i) {
        a[i] = read();
        maxx[i] = a[i];
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 1; j <= k; ++j) {
            if(j & (1 << i)) {
                int t = j ^ (1 << i);
                pair<int, int> tmp = choose(maxx[t], maxxx[t], maxx[j], maxxx[j]);
                maxx[j] = tmp.second;
                maxxx[j] = tmp.first;
            }
        }
    }

    int ma = maxx[0] + maxxx[0];

    for(int i = 1; i <= num; ++i) {
        ma = max(ma, maxx[i] + maxxx[i]);
        write(ma);
        putchar('\n');
    }

    return 0;
}