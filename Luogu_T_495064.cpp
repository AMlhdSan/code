#include <bits/stdc++.h>

#define N 200001

using namespace std;

int n, k;
int a[N];
int ans[N];
bool flag = 1;

int main() {
    cin >> n >> k;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    while(flag) {
        flag = 0;
        sort(a + 1, a + 1 + n);
        
    }


    return 0;
}