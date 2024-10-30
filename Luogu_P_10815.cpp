#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;
ll sum = 0;

inline ll read() {
    ll w = 0, f = 1;
    char ch = getchar_unlocked();
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = getchar_unlocked();
    }
    while(ch >= '0' && ch <= '9') {
        w = (w << 3) + (w << 1) + (ch - '0');
        ch = getchar_unlocked();
    }
    return w * f;
}

int main() {

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        sum += read();
    }

    cout << sum << endl;

    return 0;
}