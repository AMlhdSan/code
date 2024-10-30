#include <bits/stdc++.h>

#define N 100000010
#define M 5761456

using namespace std;

int n, q, k, cnt;
bool t[N];
int a[M];

int main() {

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> q;

    memset(t, true, sizeof(t));

    t[1] = false;
    cnt = 0;

    for(int i = 2; i <= n; ++i) {
        if(t[i]) {
            ++cnt;
            a[cnt] = i;
        }
        for(int j = 1; j <= cnt && i * a[j] <= n; ++j) {
            t[i * a[j]] = 0;
        }
    }

    while(q--) {
        cin >> k;
        printf("%d\n", a[k]);
    }

    return 0;
}