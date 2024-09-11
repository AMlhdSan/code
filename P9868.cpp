#include <bits/stdc++.h>
using namespace std;

int n, m;
string s[3001];
string minnn = "zzzzzzzzzzzzz", minn = "zzzzzzzzzzzzz";

int main() {

    cin >> n >> m;

    if(n == 1) {
        cout << 1 << endl;
        return 0;
    }

    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        sort(s[i].begin(), s[i].end());
        reverse(s[i].begin(), s[i].end());
        if(s[i] < minn) {
            minnn = minn;
            minn = s[i];
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(s[i] == minn) {
            reverse(s[i].begin(), s[i].end());
            if(s[i] < minnn) {
                cout << 1;
            }
            continue;
        }
        reverse(s[i].begin(), s[i].end());
        if(s[i] < minn) {
            cout << 1;
        }
        else {
            cout << 0;
        }
    }
    return 0;
}