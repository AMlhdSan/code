#include <bits/stdc++.h>

#define N 101

using namespace std;

int n;
string str;
int p[N];
int maxx = -1;

int main() {

    cin >> n;
    cin >> str;
    str = "_" + str;

    for(int i = 1; i <= n; ++i) {
        if(str[i] == "W") {
            p[i] = 1;
        }
        else if(str[i] == ".") {
            p[i] = 0;
        }
        else {
            p[i] = -1;
        }
    }

    for(int i = 1; i <= n; ++i) {
        if(p[i] == 0) {
            for(int i = i; i >= 1; --i) {
                if(p[i] == 0) {
                                        
                }
            }
        }
    }

    return 0;
}