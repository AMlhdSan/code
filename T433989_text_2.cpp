#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int maxM;

void dp(int m, int n, vector<int>& gg) {
    vector<int> q;
    int g = gg[1];

    if (m >= n) {
        gg[0] = gg[1];
    }

    for (int i = 1; i * i <= maxM; ++i) {
        q.push_back(i * i); 
    }
    for (int m = 1; m <= maxM; ++m) {
        vector<bool> seen(101, false);

        if (m >= n) {
            seen[gg[m - n]] = true; 
        }
        for (int square : q) {
            if (m >= square) {
                int newG = gg[1] - gg[(m - square) / square]; 
                if (newG > gg[0]) { 
                    gg[0] = newG;
                }
            } 
            else {
                break;
            }
            
        }
        int g = 0;
        while (seen[g]) {
            ++g;
        }
        gg[m] = g;
    }

    int tt = gg[1];
    gg[1] = gg[0];
    gg[0] = tt;
}

int main() {
    int T, n;
    cin >> T >> n;

    vector<int> m(T);
    maxM = 0;
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
