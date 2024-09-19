#include <bits/stdc++.h>
using namespace std;

int n;
int a[100010];
int b[100010];
int ans[100010];
bool iff[100010];
int cnt1 = 0;
int cnt2 = 0;

int main() {

    cin >> n;
    memset(iff, false, sizeof(iff));

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    bool flag = false;

    for(int i = 1; i <= n; ++i) {
        if(a[i] == 0) {
            ++cnt;
        }
    }

    for(int i = 1; i <= cnt1; ++i) {
        cout << a[i] << " ";
    }
    return 0;
}