#include <bits/stdc++.h>
#define N 10
#define K 85
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

int n, k;
long long f[N][1 << N][K];
vector<int> state;
vector<pair<int,int>> trans;

int main() {
    n = read();
    k = read();
    
    for(int i = 0; i < (1 << n); i++) {
        if(!(i & (i << 1)) && !(i & (i >> 1)))
            state.push_back(i);
    }
    
    for(int i : state)
        for(int j : state)
            if(!(i & j) && !(i & (j << 1)) && !(i & (j >> 1)) && 
               !(j & (i << 1)) && !(j & (i >> 1)))
                trans.push_back({i, j});
    
    f[0][0][0] = 1;
    
    for(int i = 0; i < n; i++)
        for(auto [s1, s2] : trans)
            for(int p = 0; p <= k; p++) {
                int cnt = __builtin_popcount(s2);
                if(p + cnt <= k)
                    f[i + 1][s2][p + cnt] += f[i][s1][p];
            }
    
    long long ans = 0;
    for(int s = 0; s < (1 << n); s++)
        ans += f[n][s][k];
        
    cout << ans << endl;
    return 0;
}