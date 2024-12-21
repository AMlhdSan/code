#include <bits/stdc++.h>
using namespace std;

int T;
int n, k;

int main() {

    cin >> T;

    while(T--) {
        cin >> n >> k;
        if(k & 1) {
            cout << (n / k) * (n / k) * (n / k) << endl;
        }
        else {
            cout << (n / (k / 2)) * (n / (k / 2)) * (n / (k / 2)) << endl;
        }
    }

    return 0;
}