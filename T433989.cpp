#include <bits/stdc++.h>
using namespace std;

int n, m;
int l[100001], r[100001];
bool flag = true;
bool flag2 = true;

int main() {

    cin >> n >> m;
    r[0] = -0x7fffffff;
    for(int i = 1; i <= m; ++i) {
        cin >> l[i] >> r[i];
        if(l[i] != 1) {
            flag = false;
        }
        if(r[i - 1] >= l[i]) {
            flag2 = false;
        }
    }
    if(flag) {
        cout << 1 << endl;
        cout << 1 << ' ' << n - 1 << endl;
        return 0;
    }
    else if(flag2) {
        cout << m << endl;
        for(int i = 1; i <= m; ++i) {
            if(r[i] == n) {
                cout << 1 << ' ' << n - 1 << endl;
            }
            else 
                cout << l[i] << ' ' << r[i] + 1 << endl;
        }
        return 0;
    }
    cout << 2 << endl;
    cout << 1 << ' ' << n - 1 << endl;
    cout << 2 << ' ' << n << endl;

    
    return 0;
}