#include <iostream>
#include <vector>
using namespace std;
 
const long long MOD = 1000000007;

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

long long modexp(long long a, long long b) {
    long long res = 1;
    while(b){
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
 
int main(){

    freopen("chess.in", "r", stdin);
    freopen("chess.out", "w", stdout);
    
    int n;
    n = read();
    // 因为树有 n 个顶点和 n-1 条边
    // 输入第二行有 n-1 个数，第 i 个数为 f_i 表示有边 (f_i, i+1)
    vector<int> deg(n+1, 0);
    for (int i = 1; i <= n - 1; i++){
        int f;
        f = read();
        // f 与 i+1 之间有边
        deg[f]++;
        deg[i+1]++;
    }
    
    // 统计满足 N(S)=单元素 的方案数
    long long ans = 0;
    for (int y = 1; y <= n; y++){
        if(deg[y] >= 1){
            long long ways = (modexp(2, deg[y]) - 2) % MOD;
            if(ways < 0) ways += MOD;
            ans = (ans + ways) % MOD;
        }
    }
    
    writeln(ans % MOD);
    return 0;
}
