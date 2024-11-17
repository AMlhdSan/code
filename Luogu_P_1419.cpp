#include <bits/stdc++.h>

#define N 100010
#define mid ((l + r) >> 1)

using namespace std;

int n;
int s, t;
int a[N];

bool check(double p) {
    int sum = 0;
    for(int i = s; i <= t; ++i) {
        for(int j = 1; j + i <= n; ++i) {
            sum = ...;
        }
    }
    if(1.0 * sum >= p) {
        return 1;
    }
    else
}

int main() {

    cin >> n;

    cin >> s >> t;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    double l = 1, r = n;
    while(l <= r) {
        if(check(mid)) {
            l = mid;
        }
        else {
            r = mid;
        }
    }

    return 0;
}