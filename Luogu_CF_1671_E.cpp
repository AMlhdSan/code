#include <bits/stdc++.h>
#define int long long
#define ls (x << 1)
#define rs (x << 1 | 1)
#define MOD 998244353
#define N 900005
using namespace std;

char buf[1 << 20], *p1 = buf, *p2 = buf;
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) ? EOF : *p1++)
inline int read() {
    int x = 0, f = 0;
    char c = gc();
    while (!isdigit(c)) f |= (c == '-'), c = gc();
    while (isdigit(c)) x = x * 10 + (c ^ 48), c = gc();
    return f ? -x : x;
}

char obuf[1 << 20], *o1 = obuf;
#define pc(x) (*o1++ = (x))
inline void write(int x) {
    if (x < 0) pc('-'), x = -x;
    char stk[20];
    int top = 0;
    do stk[top++] = x % 10 + '0'; while (x /= 10);
    while (top) pc(stk[--top]);
}
inline void flush() { fwrite(obuf, o1 - obuf, 1, stdout); }

int n, m;
int a[N], f[N], dep[N];
string s[N];

void dfs(int x) {
    if (ls > m) {
        s[x] = a[x] + '0';
        f[x] = 1;
        return;
    }
    dep[ls] = dep[rs] = dep[x] + 1;
    dfs(ls), dfs(rs);
    
    if (s[ls] == s[rs]) f[x] = f[ls] * f[rs] % MOD;
    else f[x] = f[ls] * f[rs] % MOD * 2 % MOD;
    
    s[x] = a[x] + '0';
    if (s[ls] < s[rs]) s[x] += s[ls] + s[rs];
    else s[x] += s[rs] + s[ls];
}

signed main() {
    n = read();
    m = (1LL << n) - 1;
    for (int i = 1; i <= m; i++) {
        char z;
        do z = gc(); while (z != 'A' && z != 'B'); 
        a[i] = (z == 'A');
    }
    dfs(1);
    write(f[1]), pc('\n');
    flush();
    return 0;
}
