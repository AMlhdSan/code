#include <bits/stdc++.h>
#define N 100001
using namespace std;

int v[10];
int t;
char n[N];
int len;

int main() {
    
    cin >> t;
    cin >> t;
    
    while (t--) {
        cin >> n + 1;

        len = strlen(n + 1);

        for(int i = 1; i <= 9; i++) {
            cin >> v[i];
        }

        for(int i = 1; i <= len; ++i) {
            if(if_can(i)) {
                
            }
        }
    }
    
    return 0;
}
