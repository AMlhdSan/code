#include <bits/stdc++.h>
using namespace std;

int T;
int a, b, c, d;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {

    cin >> T;

    while(T--) {
        cin >> a >> b >> c >> d;
        if(gcd(abs(a - c), abs(b - d)) != 1) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }

    return 0;
}