#include <bits/stdc++.h>
using namespace std;
int T;
long long a;
long long b, c, d;
int main() {
    cin >> T;
    while(T--) {
        // a + b + c + d = gcd(a, b) + lcm(a, b);
        cin >> a;
        if(a <= 5 * 100000000)
            b = a, c = 2 * a, d = 3 * a;
        else {
            
        }
        cout << b << " " << c << " " << d << endl;
    }
    return 0;
}