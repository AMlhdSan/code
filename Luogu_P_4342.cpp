#include <bits/stdc++.h>

#define N 51

using namespace std;

int n;
int ta;
int t[N << 1];
int a[N << 1][N << 1];
int b[N << 1][N << 1];

int main() {

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        char tmp;
        cin >> tmp;
        cin >> ta;
        a[i][i] = a[i + n][i + n] =  ta;
        b[i][i] = b[i + n][i + n] = ta;

        if(tmp == 'x') {
            t[i] = t[i + n] = 1;
        }
        else {
            t[i] = t[i + n] = 0;
        }
    }

    for(int l = 1; l <= n; ++l) {
        for(int i = 1; i <= (n << 1) - l + 1; ++i) {
            int j = i + l - 1;
            for(int k = i; k <= j - 1; ++k) {
                if(t[k + 1]) { // *
                    a[i][j] = max(a[i][j], max(a[i][k] * b[k + 1][j], max(b[i][k] * a[k + 1][j], max(a[i][k] * a[k + 1][j], b[i][k] * b[k + 1][j]))));
                    b[i][j] = min(b[i][j], min(a[i][k] * b[k + 1][j], min(b[i][k] * a[k + 1][j], min(a[i][k] * a[k + 1][j], b[i][k] * b[k + 1][j]))));
                }
                else { // +
                    a[i][j] = max(a[i][j], a[i][k] + a[k + 1][j]);
                    b[i][j] = min(b[i][j], b[i][k] + b[k + 1][j]);
                }
            }
        }
    }

    int ans = -0x7fffffff;

    for(int i = 1; i <= n; ++i) {
        ans = max(ans, a[i][i + n - 1]);
    }

    cout << ans << endl;

    for(int i = 1; i <= n; ++i) {
        if(a[i][i + n - 1] == ans) {
            cout << i << ' ';
        }
    }


    return 0;
}