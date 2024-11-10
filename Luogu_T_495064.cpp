#include <iostream>
#include <cstdio>
#include <algorithm>

#define N 200005

using namespace std;

int n, k;
int ans[N];
bool flag = 1;

struct node {
    int val;
    int index;
}a[N];

inline int read() {
    int w = 0, f = 1;
    char ch = getchar_unlocked();
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = getchar_unlocked();
    }
    while(ch >= '0' && ch <= '9') {
        w = (w << 3) + (w << 1) + (ch - '0');
        ch = getchar_unlocked();
    }
    return w * f;
}

bool cmp(node x, node y) {
    return x.val < y.val;
}

bool check(node p, int pos) {
    int l = pos + 1, r = n + 1;
    int mid;
    while(l < r) {
        mid = (l + r) >> 1;
        if(a[mid].val <= p.val) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    if(a[l].val - p.val <= k) {
        return 1;
    }
    else {
        a[pos].val += k;
        return 0;
    }
}

int main() {

    cin >> n >> k;

    for(int i = 1; i <= n; ++i) {
        a[i].val = read();
        a[i].index = i;
    }
    a[n + 1].val = 0x7fffffff;
    a[n + 1].index = n + 1;

    sort(a + 1, a + 1 + n, cmp);

    while(flag) {
        flag = 0;
        for(int i = 1; i <= n; ++i) {
            if(check(a[i], i)) {
                ++ans[a[i].index];
                flag = 1;
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
    }

    return 0;
}