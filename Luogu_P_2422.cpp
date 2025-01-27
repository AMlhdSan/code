#include <bits/stdc++.h>

#define N 100010
#define int long long
#define PII pair<int, int>

using namespace std;

int n;
int a[N];
PII stk1[N], stk2[N];
int sum[N];
int index1[N], index2[N];

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

signed main() {

    n = read();
    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    for(int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + a[i];
    }

    // 右边第一个比自己小的数

    int top1 = 0;
    for(int i = 1; i <= n; ++i) {
        if(top1 == 0) {
            ++top1;
            stk1[top1] = make_pair(a[i], i);
        }
        else if(stk1[top1].first > a[i]) {
            while(stk1[top1].first > a[i] && top1 >= 1) {
                index1[stk1[top1].second] = i;
                --top1;
            }
            ++top1;
            stk1[top1] = make_pair(a[i], i);
        }
        else {
            ++top1;
            stk1[top1] = make_pair(a[i], i);
        }
    }

    int top2 = 0;
    for(int i = n; i >= 1; --i) {
        if(top2 == 0) {
            ++top2;
            stk2[top2] = make_pair(a[i], i);
        }
        else if(stk2[top2].first > a[i]) {
            while(stk2[top2].first > a[i] && top2 >= 1) {
                index2[stk2[top2].second] = i;
                --top2;
            }
            ++top2;
            stk2[top2] = make_pair(a[i], i);
        }
        else {
            ++top2;
            stk2[top2] = make_pair(a[i], i);
        }
    }

    int maxx = 0;

    for(int i = 1; i <= n; ++i) {
        maxx = max(maxx, a[i] * (sum[index1[i]] - sum[index2[i] - 1]));
    }

    cout << maxx << endl;

    return 0;
}