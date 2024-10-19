#include <bits/stdc++.h>
using namespace std;

string str;
int n;
int cnt = 0;
bool flag = 1;

int main() {

    cin >> n;

    cin >> str;

    int len = str.length();

    while(flag && len) {
        flag = 0;
        for(int i = 0; i < len - 2; ++i) {
            if(str[i] == 'n' && str[i + 1] == 'o' && str[i + 2] == 't') {
                str.erase(i, 3);
                len -= 3;
                flag = 1;
                --i;
            }
        }
        if(flag) {
            ++cnt;
        }
    }

    cout << str << endl;
    cout << cnt;

    return 0;
}