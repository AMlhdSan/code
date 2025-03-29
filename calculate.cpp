#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int MAXN = 500005, MAXQ = 500005;
int n, q, V;
ull seed;
unsigned long long a[MAXN], b[MAXN], x[MAXQ], v[MAXQ];
bool op[MAXQ];
void gen(int n, int q, int V, ull seed){
    std::mt19937_64 rnd(seed);
    for(int i = 1; i <= n; i++) a[i] = rnd() % (V + 1);
    for(int i = 1; i <= n; i++) b[i] = rnd() % (V + 1);
    for(int i = 1; i <= q; i++){
        op[i] = rnd() & 1;
        x[i] = rnd() % n + 1;
        v[i] = rnd() % (V + 1);
    }
}
inline ull readseed() {
    ull x = 0;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x;
}
inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * f;
}
void write(__int128 x){
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x == 0){
        putchar('0');
        return;
    }
    char buf[50];
    int idx = 0;
    while(x){
        buf[idx++] = char('0' + (x % 10));
        x /= 10;
    }
    for(int i = idx - 1; i >= 0; i--) putchar(buf[i]);
}
int main(){
    // freopen("calculate.in", "r", stdin);
    // freopen("calculate.out", "w", stdout);
    n = read(), q = read();
    V = read(), seed = readseed();
    gen(n, q, V, seed);
    __int128 totalA = 0, totalB = 0, totalAB = 0, ans;
    for(int i = 1; i <= n; i++){
        totalA += a[i];
    }
    for(int i = 1; i <= n; i++){
        totalB += b[i];
        totalAB += a[i] * b[i];
    }
    ans = n * totalAB - totalA * totalB;
    write(ans); putchar('\n');
    for(int i = 1; i <= q; i++){
        int pos = x[i];
        if(op[i] == 0){
            totalA = totalA - a[pos] + v[i];
            totalAB = totalAB - a[pos] * b[pos] + v[i] * b[pos];
            a[pos] = v[i];
        }
        else{
            totalB = totalB - b[pos] + v[i];
            totalAB = totalAB - a[pos] * b[pos] + a[pos] * v[i];
            b[pos] = v[i];
        }
        ans = n * totalAB - totalA * totalB;
        write(ans); putchar('\n');
    }
    return 0;
}