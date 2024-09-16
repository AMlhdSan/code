#include <bits/stdc++.h>
using namespace std;

int n, k;
string str;
int now;
string op;

int main() {
    cin >> n >> k;
    cin >> str;
    for(int i = 0; i < str.length(); ++i) {
        if(str[i] == 'I') {
            str.erase(i, 1);
            --i;
            now = i + 1;
        }
    }
    // cout << now << endl;
    while(k--) {
        cin >> op;
        if(op == "backspace") {
            
            str.erase(now, 1);
            --now;
        }
        else if(op == "<-") {
            --now;
        }
        else if(op == "->") {
            ++now;
        }
        else if(op == "delete") {
            ++now;
            str.erase(now, 1);
            --now;
        }
        else if(op == "A") {
            --now;
            str.insert(now, "A");
            ++now;
        }
        else if(op == "B") {
            --now;
            str.insert(now, "B");
            ++now;
        }
        else if(op == "C") {
            --now;
            str.insert(now, "C");
            ++now;
        }
    }
    for(int i = 0; i < str.length(); ++i) {
        if(i == now + 1) {
            cout << "I";
        }
        cout << str[i];
    }
    return 0;
}