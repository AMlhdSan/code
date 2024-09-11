#include <iostream>
using namespace std;

int n;
int day;

int main() {
    cin >> n;

    int i = 0;
    bool flag = false;

    while(n > 0) {
        ++i;
        if((n - 1) % 3 == 0 && flag == false) {
            day = i;
            flag = true;
        }
        n -= ((n - 1) / 3 + 1);
    }
    cout << i << ' ' << day;
    return 0;
}