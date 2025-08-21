#include <bits/stdc++.h>

#define ll long long
#define MOD 998244353

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

map<int, ll> cnt;

int main() {
    freopen("xortree.in","r",stdin);
    freopen("xortree.out", "w", stdout);
    int k = read(), q = read();
    
    cnt[k] = 1;
    
    while (q--) {
        int op = read();
        
        if (op == 1) {
            int x = read();
            map<int, ll> ncnt = cnt;
            
            for (auto& p : cnt) {
                int val = p.first;
                ll c = p.second;
                
                int lval = val;
                int rval = val ^ x;
                int nval = val ^ lval ^ rval;
                
                ncnt[lval] = (ncnt[lval] + c) % MOD;
                ncnt[rval] = (ncnt[rval] + c) % MOD;
                ncnt[nval] = (ncnt[nval] + c) % MOD;
                ncnt[val] = (ncnt[val] - c + MOD) % MOD;
                if (ncnt[val] == 0) ncnt.erase(val);
            }
            
            cnt = ncnt;
        } else {
            int x = read();
            writeln(cnt[x]);
        }
    }
    
    return 0;
}