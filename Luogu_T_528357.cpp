#include <bits/stdc++.h>
using namespace std;

int n, a, b;
bool flag = 0;

int main() {

    cin >> n >> a >> b;

    for(int i = 0; i <= n; ++i) {
        if(abs(a - i) == b) {
            cout << i << ' ';
            flag = 1;
        }
    }

    if(!flag) {
        cout << "No solution" << endl;
    }

    return 0;
}