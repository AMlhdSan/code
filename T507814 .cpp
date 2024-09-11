#include <bits/stdc++.h>
using namespace std;

long long n, p;
int a[100001];

int main() {
    cin >> n >> p;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        if(a[i] >= 0) {
            p += a[i];
        }
    }
    cout << p << endl;
    return 0;
}