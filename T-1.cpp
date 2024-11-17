#include <bits/stdc++.h>

#define N 200010
#define M 200010

using namespace std;

int n, m;
int s[N], t[N];
int tmp[N * 2];
vector<int> out[M];

struct node {
    int st, ed;
    int index;
}a[N];

bool cmp(node a, node b) {
    return a.st < b.st;
}

int main() {

    cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        cin >> s[i] >> t[i];
        s[i] += t[i];
        tmp[(i << 1) - 1] = s[i];
        tmp[i << 1] = t[i];
    }

    sort(tmp + 1, tmp + 2 * n + 1);
    int p = unique(tmp + 1, tmp + 2 * n + 1) - (tmp + 1);
    for(int i = 1; i <= n; ++i) {
        s[i] = lower_bound(tmp + 1, tmp + p + 1, s[i]) - tmp;
        t[i] = lower_bound(tmp + 1, tmp + p + 1, t[i]) - tmp;
    }

    for(int i = 1; i <= n; ++i) {
        a[i].st = t[i];
        a[i].ed = s[i];
        a[i].index = i;
    }

    sort(a + 1, a + n + 1, cmp);
    priority_queue<pair<int, int> > q;

    for(int i = 1; i <= m; ++i) {
        q.push(make_pair(0, i));
    }

    for(int i = 1; i <= n; ++i) {
        pair<int, int> x = q.top();
        q.pop();
        
    }

    return 0;
}