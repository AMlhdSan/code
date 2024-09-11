#include <bits/stdc++.h>
using namespace std;

int a[9];
char tmp;
int T;

int main() {
    cin >> T;
    while (T--) {
        for(int i = 1; i <= 8; ++i) {
            cin >> tmp;
            if(tmp == '-')
                a[i] = -1;
            else
                a[i] = tmp - '0';
        }
        if(a[8] % 2 == 0) {
            cout << 0 << endl;
        }
        
    }
    return 0;
}