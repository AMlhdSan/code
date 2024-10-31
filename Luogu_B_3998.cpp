#include <bits/stdc++.h>
using namespace std;

int n;
string str = "_";
string tmp;
int top = 1;

int main() {

    cin >> n;
    while(n--) {
        cin >> tmp;
        if(tmp == "<bs>") {
            if(top == 1) {
                continue;
            }
            str.erase(top - 1, 1);
            --top;
        }
        else {
            ++top;
            str += tmp;
        }
    }

    cout << str + 1;
    return 0;
}