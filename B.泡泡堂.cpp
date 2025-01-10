#include <bits/stdc++.h>

#define N 100010

using namespace std;

int a[2][N];
int n;

int find(int i, int j) {
    int l = 1, r = n;
    int ans = 0, h = 1, e = n;
    while(h <= e && l <= r) {
        if(a[i][l] > a[j][h])
            ans += 2, ++h, ++l;
        else if(a[i][l] == a[j][h]) {
            if(a[i][r] <= a[j][e]){
                if(a[i][l] == a[j][e]) 
                    ++ans;
                --e;
                ++l;
            }
            else {
                --e;
                --r;
                ans += 2;
            }
        }
        else {
            ++l;
            --e;
        }
    }
    return ans;
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[0][i];
    for(int i = 1; i <= n; ++i)
        cin >> a[1][i];
    sort(a[0] + 1, a[0] + 1 + n);
    sort(a[1] + 1, a[1] + 1 + n);
    cout << find(0, 1) << ' ' << 2 * n - find(1, 0) << endl;
    return 0;
}