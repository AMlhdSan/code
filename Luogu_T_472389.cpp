#include <bits/stdc++.h>

#define N 100001

using namespace std;

int k;
int a;
int s[N];
int sum = 0;
int maxx = -1;

int main() {

    cin >> k;

    for(int i = 1; i <= k; ++i) {
        cin >> a;
        ++s[a];
        maxx = max(maxx, a);
    }

    for(int i = 1; i < maxx; ++i) {
        sum += s[i] + 1;
    }
    sum += s[maxx];

    cout << sum << endl;

    return 0;
}