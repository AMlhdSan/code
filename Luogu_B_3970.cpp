#include <bits/stdc++.h>
using namespace std;

char ch[5];
int mod;
bool flag = 0;

int main() {

    cin >> ch + 1;
    cin >> mod;
    int len = strlen(ch + 1);
    for(int i = 1; i <= len; ++i) {
        if((ch[i] - '0') % mod != 0 || flag) {
            cout << (ch[i] - '0') % mod;
            flag = 1;
        }
    }

    if(!flag) {
        cout << 0;
    }

    return 0;
}