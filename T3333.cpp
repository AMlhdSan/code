#include <bits/stdc++.h>

#define MOD 998244353

using namespace std;

long long n;
int tmp;
long long ans = 1;

int main() {

    cin >> n;

    for(int i = 2; i <= n - 1; ++i) {
        ans = ans * i % MOD;
    }

    cout << ans << endl;

    return 0;
}