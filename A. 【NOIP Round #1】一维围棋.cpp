#include <bits/stdc++.h>

#define N 101

using namespace std;

int n;
string str;
int p[N];
int maxx = -1;
int l, r;
int start = -1;
int end = -1;

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
            p[i] = 1;
            for(int j = i - 1; j >= 1; --j) {
                if(p[i] == 0) {
                    break; 
                    l = i + 1;             
                }
            }
            for(int j = i + 1; j <= n; ++j) {
                if(p[i] == 0) {
                    break;
                    r = i - 1;
                }
            }
            for(int j = l; j <= r; ++j) {
                if(p[j] == 1 && start != -1) {
                    start = i;
                }
                if(p[j] == 1) {
                    end = i;
                }
                
            }
            if(start == end) {
                maxx = max(maxx, 0);
            }
        }
    }

    return 0;
}