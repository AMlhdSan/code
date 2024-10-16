#include <bits/stdc++.h>
using namespace std;

string str;
int len;

int main() {

    cin >> str;
    len = str.length();
    if(str[0] == str[len - 1]) {
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < len - 1; ++i) {
        if(str[i] == str[i + 1]) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}