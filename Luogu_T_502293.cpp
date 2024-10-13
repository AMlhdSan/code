#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 判断一个字符串是否为回文串
bool iff(const string &s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

int main() {
    int c;
    cin >> c; 
    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n; 
        string s;
        cin >> s; 

        if (n == 1 || iff(s, 0, n - 1)) {
            cout << "Shuiniao" << endl;
            continue;
        }

        cout << "Huoyu" << endl;

        if (n % 2 == 0) {
            cout << n / 2 << endl;
            for (int i = 0; i < n; i += 2) {
                cout << 2 << " " << i + 1 << " " << i + 2 << endl;
            }
        } else {
            cout << n / 2 + 1 << endl;
            for (int i = 0; i < n - 1; i += 2) {
                cout << 2 << " " << i + 1 << " " << i + 2 << endl;
            }
            cout << 1 << " " << n << endl;
        }
    }

    return 0;
}
