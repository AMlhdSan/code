#include <bits/stdc++.h>

#define N 1000001

using namespace std;

int n, q;
int a[N];
int l, r, k;
int sum[N];
int len;

int main() {

    cin >> n >> q;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    while(q--) {
        cin >> l >> r >> k;
        len = r - l + 1;
        if(k > len - 1) {
            cout << -1 << endl;
        }
        else if(k == len - 1) {
            
        }
    }

    return 0;
}