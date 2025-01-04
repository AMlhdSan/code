#include <bits/stdc++.h>
#include <string>

#define ll long long
#define ENDL putchar('\n')

using namespace std;

int n, k, m, s;
int T;
vector<pair<int,int> > ans;

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

int faa(int x) {
    string ss = to_string(x);
    int mx = 0;
    for(int i = 0; i < ss.length(); i++) {
        mx = max(mx, (int)(ss[i] - '0'));
    }
    return mx;
}

void solve() {
    int l1, l2, r1, r2;
    l1 = read();
    r1 = read();
    l2 = read();
    r2 = read();
    if(r1 - l1 + 1 >= 10 || r2 - l2 + 1 >= 10) {
        cout << 9 << endl;
    } 
    else {
        int mx = 0;
        for(int i = l1; i <= r1; i++) {
            for(int j = l2; j <= r2; j++) {
                mx = max(mx, faa(i + j));
            }
        }
        cout << mx << endl;
    }
}

int main() {

    freopen("digit.in", "r", stdin);
    freopen("digit.out", "w", stdout);

    T = read();

    while(T--) {
        solve();
    }

    return 0;
}