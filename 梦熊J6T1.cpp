#include <bits/stdc++.h>
#define N 101
using namespace std;

int n;
int k;
int a[N];

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; ++i) {
        if(a[upper_bound(a + 1, a + n + 1, a[i] + k) - a - 1] == a[i] + k) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}