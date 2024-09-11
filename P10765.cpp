#include <iostream>
using namespace std;

int T;
long long n;
int k;
int op;
long long a, b;

int main() {

    cin >> T;
    
    for(int ttt = 1; ttt <= T; ++ttt) {
        a = 1;
        b = 0;
        cin >> n >> k;
        for(int i = 1; i <= k; ++i) {
            cin >> op;
            if(op == 1) {
                a = a * 2;
            }
            else {
                b += a;
                a = a * 2;
            }
        }
        cout << ((n + b) / a * a - b) << endl;
    }
    return 0;
}