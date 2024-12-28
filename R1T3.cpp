#include <bits/stdc++.h>
using namespace std;

int T;
int n, m, a, b;

int main() {

    freopen("build.in", "r", stdin);
    freopen("build.out", "w", stdout);

    cin >> T;

    while(T--) {
        cin >> n;
        cin >> m;
        for(int i = 1; i <= m; ++i) {
            cin >> a;
            cin >> b;
        }
        cout << max(0, n - 1 - m) << endl;
    }

    return 0;
}