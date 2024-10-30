#include <bits/stdc++.h>

#define N 1000010

using namespace std;

int n;
struct node {
    int l;
    int r;
}a[N];

bool cmp(node x, node y) {
    return x.r < y.r;
}

int main() {

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i].l >> a[i].r;
    }

    sort(a + 1, a + n + 1, cmp);

    int sum = 0;
    int noww = -1;

    for(int i = 1; i <= n; ++i) {
        if(a[i].l >= noww) {
            ++sum;
            noww = a[i].r;
        }
    }

    cout << sum << endl;

    return 0;
}