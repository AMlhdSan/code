#include <iostream>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

void dp(int maxM, int n, vector<int>& gg) {
    vector<int> q;
    for (int i = 1; i * i < n; ++i) {
        q.push_back(i * i);
    }
    
    for (int m = 1; m <= maxM; ++m) {
        set<int> r; 

        if (m >= n) {
            r.insert(gg[m - n]);
        }

        for (int square : q) {
            if (m >= square) {
                r.insert(gg[m - square]);
            }
        }

        int g = 0;
        while (r.count(g)) {
            ++g;
        }
        gg[m] = g;
    }
}

int main() {

    int T, n;
    cin >> T >> n;

    vector<int> m(T);
    int maxM = 0;
    for (int i = 0; i < T; ++i) {
        cin >> m[i];
        maxM = max(maxM, m[i]); 
    }

    vector<int> gg(maxM + 1, 0);

    dp(maxM, n, gg);

    for (int i = 0; i < T; ++i) {
        if (gg[m[i]] == 0) {
            cout << 'B'; 
        } else {
            cout << 'F'; 
        }
    }
    cout << endl;

    return 0;
}
