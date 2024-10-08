#include <bits/stdc++.h>

#define N 6001

using namespace std;

int n;
int r[N];
int k, l;
int fa[N];

int main() {

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> r[i];
    }

    for(int i = 1; i <= n - 1; ++i) {
        cin >> l >> k;
        fa[l] = k;
    }

    return 0;
}