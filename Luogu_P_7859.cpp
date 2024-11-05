#include <bits/stdc++.h>

#define M 401

using namespace std;

int n, m;
int x[M], y[M];

int sum = 0;
int p;

int main() {

    cin >> n >> m;

    for(int i = 1; i <= m; ++i) {
        cin >> x[i] >> y[i];
    }

    for(int i = 0; i < (1 << n); ++i) {
        p = 1;
        for(int j = 1; j <= m; ++j) {
            if((i & (1 << (x[j] - 1))) && (i & (1 << (y[j] - 1)))) {
                p = 0;
                break;
            }
        }
        sum += p;
    }

    cout << sum << endl;

    return 0;
}