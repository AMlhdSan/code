#include <bits/stdc++.h>
using namespace std;

int a[6][6];

int main() {

    for(int i = 1; i <= 5; ++i) {
        for(int j = 1; j <= 5; ++j) {
            cin >> a[i][j];
        }
    }
    bool flag = true;
    for(int i = 1; i <= 5; ++i) {
        flag = true;
        for(int j = 1; j <= 5; ++j) {
            if(a[i][j] == 0) {
                flag = false;
                break;
            }
        }
        if(flag == true) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    for(int i = 1; i <= 5; ++i) {
        flag = true;
        for(int j = 1; j <= 5; ++j) {
            if(a[j][i] == 0) {
                flag = false;
                break;
            }
        }
        if(flag == true) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    flag = true;
    for(int i = 1; i <= 5; ++i) {
        if(a[i][i] == 0) {
            flag = false;
            break;
        }
    }
    if(flag == true) {
        cout << "Yes" << endl;
        return 0;
    }
    flag = true;
    for(int i = 1; i <= 5; ++i) {
        if(a[i][6 - i] == 0) {
            flag = false;
            break;
        }
    }
    if(flag == true) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}