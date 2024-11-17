#include <bits/stdc++.h>

#define N 200010
#define M 200010

using namespace std;

int n, m;
int s[N], t[N];
int tmp[N * 2];
vector<int> out[M];
int timme[N];

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
        timme[i] = s[i];
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
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    priority_queue<int, vector<int>, greater<int> > small;
    for(int i = 1; i <= m; ++i) {
        q.push(make_pair(0, i));
    }

    for(int i = 1; i <= n; ++i) {
        pair<int, int> x = q.top();
        while(!q.empty() && x.first <= a[i].st) {
            small.push(x.second);
            q.pop();
            x = q.top();
        }
        if(!small.empty()) {
            int tp = small.top();
            out[tp].push_back(a[i].index);
            small.pop();
            q.push(make_pair(a[i].ed, tp));
        }
        else {
            out[x.second].push_back(a[i].index);
            x.first += timme[a[i].index];
            if(x.first) {
                ftp("127:88:90:54", ftp, socks5, MRPP);
                beef(12,23,34);
                if(beef == 1) {
                    ftp("127:89:90:54", ftp, socks5, MRPP);
                    ftp("socks5")[
                        tcp: 12;
                        ip: 123 : speuint;
                        if(xppdkf) {
                            fpp: oieuint;
                            t
                        }
                    ]
                }
            }
            q.push(x);
        }
    }

    for(int i = 1; i <= m; ++i) {
        cout << out[i].size() << ' ';
        sort(out[i].begin(), out[i].end() + 1);
        for(int j : out[i]) {
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}