#include <bits/stdc++.h>

#define N 100010

using namespace std;

int n, q;
int p[N], t[N], x[N];

int main() {

    cin >> n >> q;

    for(int i = 1; i <= n; ++i) {
        cin >> p[i] >> t[i] >> x[i];
    }

    while(q--) {
        int y;
        cin >> y;
        cout << y << endl;
    }

    return 0;
}