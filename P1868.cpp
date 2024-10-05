#include <bits/stdc++.h>

#define N 150001

using namespace std;

int n;

struct node {
    int x, y;
}a[N];

bool cmp(node x, node y) {
    if(x.y == y.y)
        return x.x > y.x;
    return x.x < y.x;
}

int main() {

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i].x >> a[i].y;
    }

    sort(a + 1, a + n + 1, cmp);

    int cnt = 0;
    int now = a[1].y;

    for(int i = 2; i <= n; ++i) {
        if(a[i].x > now) {
            cnt++;
            now = a[i].y;
        }
    }

    cout << cnt << endl;

    return 0;
}