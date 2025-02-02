#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

// 快速幂计算 a^b % mod
long long power(long long a, long long b, long long mod) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    long long total_A = power(1 << k, n, MOD);
    long long total_H = power(2, n, MOD);
    long long inv_total_A = power(total_A, MOD - 2, MOD);
    
    long long answer = total_H * inv_total_A % MOD;
    cout << answer << endl;
    
    return 0;
}
