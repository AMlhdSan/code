#include <bits/stdc++.h>
#define ll long long
using namespace std;

int T;
ll n, k, d;
ll t;

int main() {
    cin >> T;
    while(T--) {
        cin >> n >> k >> d;
        if(d % 2 == 0) {
            cout << (n + 1) * n / 2 << endl;
        }
        else {
            if(n % 2 == 1) {
                t = (n - 1) / 2;
                cout << (t + 1) * (t + 2) / 2 + (t + 1) * t / 2 << endl;
            }
            else {
                t = n / 2;
                cout << (t + 1) * t << endl;
            }
        }
    }
    return 0;
}