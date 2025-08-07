#include <bits/stdc++.h>

#define N 200005
#define ll long long

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

int t, n, m;
int a[N];

int main() {

    freopen("team.in", "r", stdin);
    freopen("team.out", "w", stdout);

    t = read();
    
    while (t--) {
        n = read();
        m = read();
        
        for (int i = 1; i <= n; ++i) {
            a[i] = read();
        }
        
        int ans = 0;
        
        for (int l = 1; l <= n; ++l) {
            vector<bool> has(m + 1, false);
            int x = 0;
            
            for (int r = l; r <= n; ++r) {
                if (!has[a[r]]) {
                    has[a[r]] = true;
                    x++;
                }
                
                int y = 1;
                for (int i = 1; i <= m; ++i) {
                    if (has[i]) {
                        y = i + 1;
                    } else {
                        break;
                    }
                }
                
                ans = max(ans, x - y);
            }
        }
        
        writeln(ans);
    }
    
    return 0;
}