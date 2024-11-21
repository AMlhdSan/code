#include <bits/stdc++.h>
using namespace std;

int T;

void add(int d, int a, int b) {

}

void del(int d, int a, int b) {

}

void minn() {
    
}

int main() {

    cin >> T;

    while(T--) {
        int opt, d, a, b;
        cin >> opt >> d >> a >> b;
        if(opt == 1) {
            add(d, a, b);
        }
        else {
            del(d, a, b);
        }
        cout << minn() << endl;
    }

    return 0;
}