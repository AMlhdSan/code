#include <bits/stdc++.h>

#define N 3000001
#define int long long

using namespace std;

int n;
char s[N];
char a[N];
char b[N];

signed main() {

    cin >> n;

    cin >> s;

    for(int i = 0; i < n; ++i) {
        a[i] = s[i];
    }

    for(int i = 0; i < n; ++i) {
        b[i] = b[i + n] = s[2 * n - i - 1];
    }

    int lo = strstr(b, a) - b;

    if(lo < 0) {
        cout << -1 << endl;
        return 0;
    }

    lo = n - lo;

    for(int i = 0; i < lo; ++i) {
        cout << s[i];
    }

    for(int i = n + lo; i < n * 2; ++i) {
        cout << s[i];
    }

    cout << endl << lo << endl;

    return 0;
}