#include <bits/stdc++.h>
using namespace std;

int n;
int t[100001];
int tmp;

int main() {

    cin >> n;

    memset(t, 0, sizeof(t));

    for(int i = 1; i <= n * 2; ++i) {
        cin >> tmp;
        if(tmp == i) {
            cout << "No" << endl;
            return 0;
        }
        if(t[tmp]) {
            if(t[tmp] == i) {
                continue;
            }
            else {
                cout << "No" << endl;
                return 0;
            }
        }
        else {
            t[tmp] = i;
            t[i] = tmp;
        }
    }

    cout << "Yes" << endl;

    return 0;
}