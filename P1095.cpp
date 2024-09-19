#include <bits/stdc++.h>
using namespace std;

int m, s, t;

int main() {

    cin >> m >> s >> t;
    
    int p = 0, q = 0;

    for(int i = 1; i <= t; ++i) {
        p += 17;
        if(m >= 10) {
            q += 60;
            m -= 10;
        }
        else {
            m += 4;
        }
        p = max(p, q);
        if(p >= s) {
            cout << "Yes" << endl;
            cout << i << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    cout << p << endl;
    return 0;
}