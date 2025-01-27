#include <bits/stdc++.h>

#define N 1010
#define int long long

using namespace std;

int n, m;
int a[N][N];
int h[N][N]; // 表示第i行第j列向上全是 1 的最大高度.
char tmp;
int maxx = 0;

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
    m = read();
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            tmp = getchar();
            while(tmp != 'F' && tmp != 'R') {
                tmp = getchar();
            }
            a[i][j] = tmp == 'F' ? 1 : 0;
        }
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(a[i][j] == 1) {
                h[i][j] = h[i - 1][j] + 1;
            }
            else {
                h[i][j] = 0;
            }
        }
    }

    for(int i = 1; i <= n; ++i) {
        // 当前在第 i 行.
        // 求第 i 行的最大矩形.
        // 即求min(h[i][j]) * (j - k + 1)的最大值.
        // 其中k是第一个比h[i][j]小的位置.
        // 使用数组模拟单调栈进行操作.
        int s[N], top = -1;
        int l[N], r[N];
        for(int j = 1; j <= m; ++j) {
            while(top != -1 && h[i][s[top]] >= h[i][j]) {
                top--;
            }
            l[j] = top == -1 ? 1 : s[top] + 1;
            s[++top] = j;
        }
        top = -1;  // 重置栈顶指针
        for(int j = m; j >= 1; --j) {
            while(top != -1 && h[i][s[top]] >= h[i][j]) {
                top--;
            }
            r[j] = top == -1 ? m : s[top] - 1;
            s[++top] = j;
        }

        int ans = 0;
        for(int j = 1; j <= m; ++j) {
            ans = max(ans, h[i][j] * (r[j] - l[j] + 1));
        }
        maxx = max(maxx, ans);
    }

    cout << maxx * 3 << endl;

    return 0;
}
