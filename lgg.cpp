#include <bits/stdc++.h>
using namespace std;

int lg[1000001];
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
    for (int i = 1; i <= n; ++i)
        cout << lg[i] << ' ';
    
    return 0;
}