#include <bits/stdc++.h>

#define N 301

using namespace std;

int n, m;
int fa[N];
int k, s[N];
vector<int> edges[N];



int main() {

    cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        cin >> k >> s[i];
        if(k == 0) {
            fa[i] = i;
        }
        else {
            fa[i] = k;
            edges[i].push_back(k);
            edges[k].push_back(i);
        }
    }

    return 0;
}