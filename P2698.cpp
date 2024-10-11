#include <bits/stdc++.h>

#define N 100001

using namespace std;

int n, d;
int px[N], pd[N];

struct node {
    int x;
    int y;
}a[N];

bool cmp(node xx, node yy) {
    return xx.x < yy.x;
}

int main() {

    //ios::sync_with_stdio(false);

    cin >> n >> d;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i].x >> a[i].y;
    }

    sort(a + 1, a + n + 1, cmp);
    
    int r = 1;
    int minn = 0x7fffffff;
    int l1 = 1, r1 = 1;
    int l2 = 1, r2 = 1;

    for(int l = 1; l <= n; ++l) {
        while(l1 <= r1 && px[l1] < l) {
            ++l1;
        }
        while(l2 <= r2 && pd[l2] < l) {
            ++l2;
        }

        while(a[px[l1]].y - a[pd[l2]].y < d && r < n) {
            ++r;
            while(l1 <= r1 && a[px[r1]].y < a[r].y) {
                --r1;
            }
            ++r1;
            px[r1] = r;
            while(l2 <= r2 && a[pd[r2]].y > a[r].y) {
                --r2;
            }
            ++r2;
            pd[r2] = r;
        }
        if(r != n) {
            minn = min(minn, a[r].x - a[l].x);
        }
    }

    if(minn == 0x7fffffff) {
        cout << -1 << endl;
    }
    else {
        cout << minn << endl;
    }

    return 0;
}