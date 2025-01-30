#include <bits/stdc++.h>

#define N 50010

using namespace std;

int n, d;
int top;
int stk[N];
int sum = 0;
int flag[N];

struct node {
    int x, h;
}a[N];

inline bool cmp(node a, node b) {
    return a.x < b.x;
}

int main() {

    cin >> n >> d;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i].x >> a[i].h;
    }

    sort(a + 1, a + n + 1, cmp);

    // find the first one bigger than 2 * a[i].h

    int l;
    int r;

    l = r = 0;

    for(int i = 1; i <= n; i++) {
        while(a[i].x - d > a[stk[l]].x && l <= r) 
            ++l; 
        if(a[stk[l]].h >= (a[i].h << 1)) 
            flag[i] = 1;
        while(a[i].h > a[stk[r]].h && l <= r) 
            --r;
        stk[++r] = i;
    }

    // find the last one bigger than 2 * a[i].h

    l = r = 0;
    memset(stk, 0, sizeof(stk));
    a[n + 1].h = a[n + 1].x = 0;
    for(int i = n; i >= 1; i--) {
        while(a[i].x + d < a[stk[l]].x && l <= r) 
            ++l; 
        flag[i] &= (a[stk[l]].h >= (a[i].h << 1));
        if(flag[i]) 
            ++sum;
        while(a[i].h > a[stk[r]].h && l <= r) 
            --r;
        stk[++r] = i;
    }

    cout << sum << endl;
    
    return 0;
}