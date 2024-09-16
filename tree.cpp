#include <bits/stdc++.h>
using namespace std;

long long a, k, l, r;

int main() {

    cin >> a >> k >> l >> r;
    if((r - l) % k == 0) {
        cout << (r - l) / k + 1;
        return 0;
    }
    else 
        cout << (r - l) / k;

    return 0;
}