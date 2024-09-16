#include <bits/stdc++.h>
using namespace std;

int n;
long long ans = 1;

int main() {
    cin >> n;
    if(n == 0) {
        cout << "YES";
    }
    else {
        for(int i = 1; i <= n; i++) {
            ans *= i;
        }
        if(ans % (n + 1) == 0) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
    }
    return 0;
}