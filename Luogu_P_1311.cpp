#include <bits/stdc++.h>
//#include <iostream>

#define N 200001
#define K 50

using namespace std;

int n, k, p;
int a[N], b[N];
int ans = 0;
int pos = 0;
int sum[K];

int main() {
    
    cin >> n >> k >> p;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
        if(b[i] <= p) {
            for(int j = pos + 1; j <= i; ++j) {
                ++sum[a[j]];
            }
            pos = i;
            ans += sum[a[i]] - 1;
        }
        else 
            ans += sum[a[i]];
    }
    cout << ans << endl;

    return 0;
}