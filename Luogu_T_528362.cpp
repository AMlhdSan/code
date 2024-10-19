#include <bits/stdc++.h>
using namespace std;

int n, m, r, k;
int t[10001];


bool isPrime(int p) {
    if (p <= 1) return false; 
    if (p == 2) return true;
    if (p % 2 == 0) return false;
    for (int i = 3; i <= sqrt(p); i += 2) {
        if (p % i == 0) return false;
    }
    return true;
}

int main() {

    int cnt = 0;

    cin >> n >> m >> r >> k;

    for(int i = n; i >= 1; --i) {
        if(isPrime(i) && i % m == r) {
            ++cnt;
            if(cnt == k) {
                cout << i << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;

    return 0;
}