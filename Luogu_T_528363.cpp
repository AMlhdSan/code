#include <bits/stdc++.h>
using namespace std;

int n, m;
bool a[5001], b[5001];

int main() {

    fill(a + 1, a + 5001 + 1, true);
    fill(b + 1, b + 5001 + 1, true);

    cin >> n >> m;

    while(m--) {
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 1) {
            for(int i = l + 1; i < r; ++i) {
                a[i] = 0;
            }
            for(int i = l; i < r; ++i) {
                b[i] = 0;
            }
        }
        else {
            for(int i = l; i <= r; ++i) {
                a[i] = 0;
            }
            for(int i = l; i < r; ++i) {
                b[i] = 0;
            }
        }
    }

    int cnt = 0;

    for(int i = 1; i <= n; ++i) {
        if(a[i]) {
            ++cnt;
        }
    }

    cout << cnt << ' ';
    cnt = 0;

    for(int i = 1; i <= n - 1; ++i) {
        if(b[i]) {
            ++cnt;
        }
    }
    cout << cnt << endl;
    return 0;
}