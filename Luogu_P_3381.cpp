#include <bits/stdc++.h>
using namespace std;

int n, m, s, t;

int main() {

    cin >> n >> m >> s >> t;

    while(m--) {
        int u, v, w, c;
        cin >> u  >> v >> w >> c;
        add(u, v, w, c);
    }

    return 0;
}