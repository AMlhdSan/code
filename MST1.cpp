#include <bits/stdc++.h>

#define N 10010

using namespace std;

int n;
int a[N];

int main() {

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    return 0;
}