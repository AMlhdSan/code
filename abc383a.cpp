#include <bits/stdc++.h>

#define N 1010

using namespace std;

int n;
int t[N], v[N];
long long now = 0;

int main() {

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> t[i] >> v[i];
        now -= (t[i] - t[i - 1]);
        if(now < 0)
            now = 0;
        now += v[i];
    }
    cout << now << endl;

    return 0;
}