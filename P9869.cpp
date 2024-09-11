#include <bits/stdc++.h>
#define MAXX 100000
using namespace std;

int T;
int n, m;
int a[100001];
char op;
int p, q;
int cnt;

int main() {
    
    cin >> T >> T;

    while(T--) {
        cin >> n >> m;
        cnt = 0;
        memset(a, 0x7fffffff, sizeof(a));
        while(m--) {
            cin >> op;
            if(op == 'T') {
                cin >> p;
                a[p] = 1;
            }
            else if(op == 'F') {
                cin >> p;
                a[p] = 0;
            }
            else if(op == 'U') {
                cin >> p;
                a[p] = 2;
            }
            else if(op == '+') {
                cin >> p >> q;
                if(a[q] < MAXX && a[q] > -MAXX) { // 是被赋值了的.
                    a[p] = q + MAXX;
                }
                else {
                    a[p] = a[q];
                }
            }
            else if(op == '-') {
                cin >> p >> q;
                if(a[q] < MAXX && a[q] > -MAXX) { // 是被赋值了的.
                    a[p] = -q - MAXX;
                }
                else {
                    a[p] = -a[q];
                }
            }
        }
        
        for(int i = 1; i <= n; ++i) {
            if(a[i] < MAXX && a[i] > -MAXX) {
                
            }
        }
        cout << cnt << endl;
    }
    return 0;
}