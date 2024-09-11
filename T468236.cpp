#include <iostream>
using namespace std;

int n;
long long ans = 1;

long long poww(int a, int b) {
    long long res = 1;
    while(b) {
        if(b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int main() {

    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            for(int k = 1; k <= j; k++) {
                ans *= poww(k, k);
                ans %= 998244353;
            }
        }
    }

    cout << ans;
    return 0;
}