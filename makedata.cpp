#include <bits/stdc++.h>

#define N 100005
#define ll long long
#define uint64_t unsigned long long

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

inline void write(uint64_t x) {
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(uint64_t x) {
    write(x);
    putchar('\n');
}

int n;
int a[N], pos[N];
vector<uint64_t> rands;

uint64_t inv_rand(uint64_t y) {
    y ^= y >> 17;
    y ^= y >> 17;
    y ^= (y << 7) & 0x9d2c5680ULL;
    y ^= (y << 7) & 0x9d2c5680ULL;
    y ^= (y << 7) & 0x9d2c5680ULL;
    y ^= (y << 7) & 0x9d2c5680ULL;
    y ^= (y << 15) & 0xefc60000ULL;
    y ^= (y << 15) & 0xefc60000ULL;
    y ^= y << 13;
    y ^= y << 13;
    y ^= y << 13;
    return y;
}

int main() {
    n = read();
    
    for(int i = 1; i <= n; i++) {
        a[i] = read();
        pos[a[i]] = i;
    }
    
    for(int i = n; i >= 1; i--) {
        int cur_pos = pos[i];
        if(cur_pos != i) {
            swap(pos[a[i]], pos[a[cur_pos]]);
            swap(a[i], a[cur_pos]);
        }
        uint64_t r = (cur_pos - 1) % i;
        rands.push_back(r);
    }
    
    reverse(rands.begin(), rands.end());
    
    uint64_t x = 0;
    for(int i = 0; i < 64; i++) {
        uint64_t test = x | (1ULL << i);
        uint64_t tmp = test;
        bool ok = true;
        
        for(int j = 0; j < (int)rands.size() && ok; j++) {
            tmp ^= tmp << 13;
            tmp ^= tmp >> 7;
            tmp ^= tmp << 17;
            
            if(tmp % (j + 1) != rands[j]) {
                ok = false;
            }
        }
        
        if(ok) x = test;
    }
    
    writeln(x);
    
    return 0;
}