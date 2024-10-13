#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll T, n, k;
ll ans;
ll l, r;

int main() {

    cin >> T;
    while(T--) {
        ans = 0;
        cin >> n >> k;
        l = n / (k + 1) + 1;
        r = n / k;
        if(k == 0) {
            cout << 1 << endl;
            continue;
        }
        if(r < l) {
            cout << 0 << endl;
            continue;
        }
        cout << (r - l + 1) << endl;
    }

    return 0;
}