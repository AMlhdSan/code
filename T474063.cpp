#include <bits/stdc++.h>
using namespace std;

int x, y, p, q;

int main() {

    cin >> x >> y >> p >> q;

    cout << min(min(p, x - p), min(q, y - q));
    return 0;
}