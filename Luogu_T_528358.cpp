#include <bits/stdc++.h>
using namespace std;

int n, w, d;
int ans = 0x7fffffff;

int main() {

    cin >> n;

    while(n--) {
        cin >> w >> d;
        ans = min(w + (d - 1) * 7 + 1, ans);
    }

    cout << ans << endl;

    return 0;
}