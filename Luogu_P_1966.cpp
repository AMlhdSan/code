#include <bits/stdc++.h>

#define N 100001
#define MOD 99999997 
#define mid ((l + r) >> 1)

using namespace std;

int n;
int a[N];
int b[N];
int loa[N];
int lob[N];
int t[N];
int p[N];
long long sum = 0;

bool cmpa(int x, int y) {
    return a[x] < a[y];
}

bool cmpb(int x, int y) {
    return b[x] < b[y];
}

void merge(int l, int r) {
    if(l == r) {
        return;
    }
    merge(l, mid);
    merge(mid + 1, r);
    int i = l, j = mid + 1, cnt = l;
    while(i <= mid && j <= r) {
        if(p[i] > p[j]) {
            t[cnt++] = p[j++];
            sum += mid - i + 1;
            sum %= MOD;
        }
        else {
            t[cnt++] = p[i++];
        }
    }
    while(i <= mid) {
        t[cnt++] = p[i++];
    }
    while(j <= r) {
        t[cnt++] = p[j++];
    }
    for(i = l; i <= r; ++i) {
        p[i] = t[i];
    }
}

int main() {

    cin >> n;
    
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        loa[i] = i;
    }
    for(int i = 1; i <= n; ++i) {
        cin >> b[i];
        lob[i] = i;
    }

    sort(loa + 1, loa + n + 1, cmpa);
    sort(lob + 1, lob + n + 1, cmpb);

    for(int i = 1; i <= n; ++i) {
        p[loa[i]] = lob[i];
    }

    merge(1, n);

    cout << sum << endl;

    return 0;
}