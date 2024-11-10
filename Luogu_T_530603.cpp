#include <bits/stdc++.h>

#define N 1000001

using namespace std;

int n, q;
int a[N];
int l, r, k;
int sum[N];
int len;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;

    // 输入数组，并计算前缀和
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    while (q--) {
        cin >> l >> r >> k;
        len = r - l + 1;
        
        int now = sum[r] - sum[l - 1];
        
        if (k > len - 1) {
            cout << -1 << endl;
        } 
        else if(k == len - 1) {
            cout << min(abs(len - now), abs(len - 1 - now)) << endl;
        }
        else {
            cout << abs(k - now) << endl;
        }
    }

    return 0;
}
