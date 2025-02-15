#include <bits/stdc++.h>
#define N 200005
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

int n, a[N];
vector<int> pos[N];
bool vis[N];

int main() {
    // freopen("GCD.in", "r", stdin);
    // freopen("GCD.out", "w", stdout);
    n = read();
    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }
    
    for(int i = 1; i <= n; ++i) {
        int x = a[i];
        for(int j = 2; j * j <= x; ++j) {
            if(x % j == 0) {
                pos[j].push_back(i);
                while(x % j == 0) x /= j;
            }
        }
        if(x > 1) pos[x].push_back(i);
    }
    
    int ans = n;
    for(int i = 2; i < N; ++i) {
        if(pos[i].empty()) continue;
        for(int j = i + 1; j < N; ++j) {
            if(pos[j].empty()) continue;
            
            memset(vis, 0, sizeof(vis));
            memset(vis, 0, sizeof(vis));
            int cnt1 = 0, cnt2 = 0;
            
            for(int x : pos[i]) vis[x] = 1, cnt1++;
            for(int x : pos[j]) {
                if(!vis[x]) cnt2++;
                vis[x] = 1;
            }
            
            if(cnt1 > 0 && cnt2 > 0) {
                int remain = 0;
                for(int k = 1; k <= n; ++k) {
                    if(!vis[k]) remain++;
                }
                
                ans = min(ans, abs((n - remain) - remain));
            }
        }
    }
    
    writeln(ans == n ? -1 : ans);
    return 0;
}