#include <bits/stdc++.h>

#define N 150000
#define int long long

using namespace std;

struct node {
    int st, ed;
};

int n;
node a[N];
int sum = 0;
priority_queue<int> q;

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
inline void write(int x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

inline bool cmp(node a, node b) {
    return a.ed < b.ed;
}

signed main() {

    n = read();
    for(int i = 1; i <= n; ++i) {
        a[i].st = read();
        a[i].ed = read();
    }

    sort(a + 1, a + 1 + n, cmp);
    int now = 0;
    for(int i = 1; i <= n; ++i) {
        now += a[i].st;
        ++sum;
        q.push(a[i].st);
        if(now > a[i].ed) {
            now -= q.top();
            q.pop();
            --sum;
        }
    }

    write(sum);
    putchar('\n');

    return 0;
}