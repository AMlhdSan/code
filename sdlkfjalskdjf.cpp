#include <bits/stdc++.h>

#define N 55
#define INF 0x3f3f3f3f

using namespace std;

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

struct point {
    int x, y;
} p[N];

struct node {
    int x1, y1, x2, y2;
    int c;
} r[5];

int n, k, ans;

int calc(int i) {
    if (r[i].c <= 1) return 0;
    return (r[i].x2 - r[i].x1) * (r[i].y2 - r[i].y1);
}

bool chk() {
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (r[i].c > 0 && r[j].c > 0) {
                if (!(r[i].x2 < r[j].x1 || r[j].x2 < r[i].x1 || 
                      r[i].y2 < r[j].y1 || r[j].y2 < r[i].y1)) {
                    return false;
                }
            }
        }
    }
    return true;
}

void dfs(int u) {
    if (u == n + 1) {
        int s = 0;
        for (int i = 0; i < k; i++) {
            s += calc(i);
        }
        ans = min(ans, s);
        return;
    }
    
    for (int i = 0; i < k; i++) {
        node t = r[i];
        
        if (r[i].c == 0) {
            r[i].x1 = r[i].x2 = p[u].x;
            r[i].y1 = r[i].y2 = p[u].y;
            r[i].c = 1;
        } else {
            r[i].x1 = min(r[i].x1, p[u].x);
            r[i].y1 = min(r[i].y1, p[u].y);
            r[i].x2 = max(r[i].x2, p[u].x);
            r[i].y2 = max(r[i].y2, p[u].y);
            r[i].c++;
        }
        
        if (chk()) {
            dfs(u + 1);
        }
        
        r[i] = t;
    }
}

int main() {
    n = read();
    k = read();
    
    for (int i = 1; i <= n; i++) {
        p[i].x = read();
        p[i].y = read();
    }
    
    ans = INF;
    dfs(1);
    
    writeln(ans);
    
    return 0;
}