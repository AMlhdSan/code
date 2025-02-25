#include <bits/stdc++.h>

#define N 50010

using namespace std;

int n, t;
int a[N];
int b[N];
int l[N], r[N];
int add_tag[N];
int c[N];

inline void print

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar(); 
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
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

inline void add_range(int x, int y, int c) {
    if(b[x] == b[y]) {
        for(int i = x; i <= y; ++i) {
            a[i] += c;
        }
        // 重新修改 c 数组
        int tmp[1000];
        for(int i = l[b[x]]; i <= r[b[x]]; ++i) {
            tmp[i - l[b[x]] + 1] = a[i];
        }
        sort(tmp + 1, tmp + 1 + r[b[x]] - l[b[x]] + 1);
        for(int i = l[b[x]]; i <= r[b[x]]; ++i) {
            c[i] = tmp[i - l[b[x]] + 1];
        }
        return;
    }
    for(int i = x; i <= r[b[x]]; ++i) {
        a[i] += c;
    }
    for(int i = l[b[y]]; i <= y; ++i) {
        a[i] += c;
    }
    for(int i = b[x] + 1; i <= b[y] - 1; ++i) {
        add_tag[i] += c;
    }
}

inline int query(int x, int y, int c) {
    int res = 0;
    if(b[x] == b[y]) {
        for(int i = x; i <= y; ++i) {
            if(a[i] + add_tag[b[i]] < c) {
                ++res;
            }
        }
        return res;
    }
    for(int i = x; i <= r[b[x]]; ++i) {
        if(a[i] + add_tag[b[i]] < c) {
            ++res;
        }
    }
    for(int i = l[b[y]]; i <= y; ++i) {
        if(a[i] + add_tag[b[i]] < c) {
            ++res;
        }
    }
    for(int i = b[x] + 1; i <= b[y] - 1; ++i) {
        int l = l[i], r = r[i];
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(a[mid] + add_tag[i] < c) {
                res += mid - l + 1;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
    }
    return res;
}

int main() {

    n = read();
    t = sqrt(n);

    for (int i = 1; i <= n; ++i) {
        a[i] = read();
        b[i] = (i - 1) / t + 1;
    }

    for (int i = 1; i <= b[n]; ++i) {
        l[i] = (i - 1) * t + 1;
        r[i] = i * t;
    }

    for(int i = 1; i <= b[n]; ++i) {
        int tmp[1000];
        for(int j = l[b[i]]; j <= r[b[i]]; ++j) {
            tmp[j - l[b[i]] + 1] = a[j];
        }
        sort(tmp + 1, tmp + 1 + r[b[i]] - l[b[i]] + 1);
        for(int j = l[b[i]]; j <= r[b[i]]; ++j) {
            c[j] = tmp[j - l[b[i]] + 1];
        }
    }

    for(int i = 1; i <= n; ++i) {
        int op, x, y, c;
        op = read();
        x = read();
        y = read();
        c = read();
        if(op == 0) {
            add_range(x, y, c);
        }
        else {
            writeln(query(x, y, c));
        }
    }

    return 0;
}