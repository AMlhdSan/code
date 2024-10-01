#include <bits/stdc++.h>
using namespace std;

int n, l;
int x, y;
int op;
int t[100001];
int sum1 = 0;
int sum2 = 0;
bool tt[100001];

int main() {

    cin >> l >> n;

    memset(t, -1, sizeof(t));

    for(int i = 1; i <= n; ++i) {
        cin >> op >> x >> y;
        if(op == 0) {
            for(int j = x; j <= y; ++j) {
                t[j] = 0;
            }
        }
        else {
            for(int j = x; j <= y; ++j) {
                t[j] = 1;
                tt[j] = true;
            }
        }
    }

    for(int i = 0; i <= l; ++i) {
        if(t[i] == true) {
            ++sum1;
        }
        if(t[i] == false && tt[i] == true) {
            ++sum2;
        }
    }
    cout << sum1 << " " << sum2 << endl;
    return 0;
}