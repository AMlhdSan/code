#include <iostream>
#include <vector>
#include <iomanip>
// #include <bits/stdc++.h>

using namespace std;

bool flag = 0;
int n;
long double a0;

struct node {
    double l, r;
};

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') 
            f = -1;
        ch = getchar();
    }
    while(ch <= '9' && ch >= '0') {
        x = x * 10 + (ch ^ 48);
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

inline bool cmp(node x, node y) {
    return x.l < y.l || (x.l == y.l && x.r < y.r);
}

int main() {

    ios::sync_with_stdio(false);
    

    cin >> n >> a0;

    vector<double> a(n + 2);
    vector<int> r(n + 2);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> r[i];
        a[i] - r[i] <= 0 ? flag = 1 : a[i] -= r[i];
    }

    a[n + 1] = 1.0; // 顶级掠食者需要 1 单位能量

    vector<double> need(n + 2, 0.0);
    need[n + 1] = 1.0;

    for (int i = n; i >= 0; --i) {
        need[i] = a[i];
        for (int j = i + 1; j <= n + 1; ++j) {
            if (r[j] >= i) {
                need[i] += need[j] / 5.0;
            }
        }
        if(need[i] * 3.0 > a0) {
            flag = 1;
        }
    }

    if(flag) {
        puts("-1");
        return 0;
    }

    // for(int)

    if (need[0] > a0) {
        cout << -1 << endl;
    } else {
        cout << fixed << setprecision(7) << need[n + 1] / 5.0 << endl;
    }

    return 0;
}