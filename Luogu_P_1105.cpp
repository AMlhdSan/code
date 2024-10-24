#include <bits/stdc++.h>

#define N 1001

using namespace std;

int n;
int t1, t2;
struct node {
    int h, l, r;
}a[N];

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i].h >> a[i].l >> a[i].r;
    }
    for(int i = 1; i <= n; ++i) {
        t1 = 0;
        t2 = 0;
        for(int j = 1; j <= n; ++j) {
            if(a[i].h > a[j].h && a[i].l < a[j].r && a[j].l < a[i].l) {
                if(a[j].h > a[t1].h) {
                    t1 = j;
                }
            }
        }
        for(int j = 1; j <= n; ++j) {
            if(a[i].h > a[j].h && a[i].r < a[j].r && a[j].l < a[i].r) {
                if(a[j].h > a[t2].h) {
                    t2 = j;
                }
            }
        }
        cout << t1 << ' ' << t2 << endl;
    }
    return 0;
}