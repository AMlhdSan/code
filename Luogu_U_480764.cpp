#include <bits/stdc++.h>

#define N 200001

using namespace std;

int n;
struct node {
    int x, y, z;
}d[N];

int a[N];
int b[N];
int c[N];

bool cmp(int t1, int t2) {
    return t1 > t2;
}

int main() {

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        scanf("%d %d %d", &d[i].x, &d[i].y, &d[i].z);
        a[i] = d[i].x;
        b[i] = d[i].y;
        c[i] = d[i].z;
    }

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    sort(c + 1, c + n + 1);

    for(int i = 1; i <= n; ++i) {
        int aa = n - (upper_bound(a + 1, a + n + 1, d[i].x) - a - 2);
        int bb = n - (upper_bound(b + 1, b + n + 1, d[i].y) - b - 2);
        int cc = n - (upper_bound(c + 1, c + n + 1, d[i].z) - c - 2);
        cout << min(aa, min(bb, cc)) << endl;
    }

    return 0;
}