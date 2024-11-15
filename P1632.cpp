#include <bits/stdc++.h>

#define N 51

using namespace std;

int n;
int x[N], y[N];
int ans[N];
int maxx[N];

int main() {

    cin >> n;

    fill(ans + 1, ans + n + 1, 0x7fffffff);

    for(int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            for(int k = 1; k <= n; ++k) {
                maxx[k] = abs(x[k] - x[i]) + abs(y[k] - y[j]);
            }
            sort(maxx + 1, maxx + n + 1);
            for(int k = 1; k <= n; ++k) {
                maxx[k] += maxx[k - 1];
                ans[k] = min(ans[k], maxx[k]);
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}