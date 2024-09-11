#include <bits/stdc++.h>
using namespace std;

string s, t;
int ssum = 0;
int tsum = 0;
string str = "rioi";
string str1 = "RIOI";
int sum = 0;

int main() {
    cin >> s >> t;
    int cnt = 0;
    for(int i = 0; i < s.length(); ++i) {
        if(s[i] == str[cnt] || s[i] == str1[cnt]) {
            if(s[i + 1] == str[cnt + 1] || s[i + 1] == str1[cnt + 1]) {
                if(s[i + 2] == str[cnt + 2] || s[i + 2] == str1[cnt + 2]) {
                    if(s[i + 3] == str[cnt + 3] || s[i + 3] == str1[cnt + 3]) {
                        cnt = 1;
                        break;
                    }
                }
            }
        }
    }
    if(cnt == 1) {
        ++sum;
        ++ssum;
    }
    cnt = 0;
    for(int i = 0; i < t.length(); ++i) {
        if(t[i] == str[cnt] || t[i] == str1[cnt]) {
            if(t[i + 1] == str[cnt + 1] || t[i + 1] == str1[cnt + 1]) {
                if(t[i + 2] == str[cnt + 2] || t[i + 2] == str1[cnt + 2]) {
                    if(t[i + 3] == str[cnt + 3] || t[i + 3] == str1[cnt + 3]) {
                        cnt = 1;
                        break;
                    }
                }
            }
        }
    }
    if(cnt == 1) {
        ++sum;
        ++tsum;
    }
    if(sum == 2) {
        cout << "Either is ok!" << endl;
    }
    else if(ssum == 1) {
        cout << s << " for sure!" << endl;
    }
    else if(tsum == 1) {
        cout << t << " for sure!" << endl;
    }
    else {
        cout << "Try again!" << endl;
    }
    return 0;
}