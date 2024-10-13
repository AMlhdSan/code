#include <bits/stdc++.h>
#define N 100001
using namespace std;

int v[10];

int main() {
    int t;
    cin >> t;
    cin >> t;
    
    while (t--) {
        char n[N];
        long long sum = 0;
        cin >> n + 1;
        int len = strlen(n + 1);
        for(int i = 1; i <= 9; i++) {
            cin >> v[i];
        }
        for(int i = 1; i <= len; i++) {
            sum += v[n[i] - '0'];
        }
        for(int i = 1; i <= len; ++i) {
            
        }
    }
    
    return 0;
}
