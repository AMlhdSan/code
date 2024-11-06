#include <bits/stdc++.h>

#define N 200001
#define MOD 10007

using namespace std;

int n;
vector<int> edges[N];
int w[N];
int tmpu, tmpv;
int maxx = -0x7fffffff;
int tmp1, tmp2;
int max1, max2;
int sum = 0;

void add_edges(int u, int v) {
    edges[u].push_back(v);
    edges[v].push_back(u);
}

int main() {

    cin >> n;

    for(int i = 1; i <= n - 1; ++i) {
        cin >> tmpu >> tmpv;
        add_edges(tmpu, tmpv);
    }

    for(int i = 1; i <= n; ++i) {
        cin >> w[i];
    }

    for(int i = 1; i <= n; ++i) {
        tmp1 = 0; tmp2 = 0;
        max1 = -0x7fffffff; max2 = -0x7fffffff;
        if(edges[i].size() != 1) {
            for(int v : edges[i]) {
                tmp1 += w[v] % MOD;
                tmp2 += (w[v] % MOD * w[v] % MOD) % MOD;
                if(w[v] >= max1) {
                    max2 = max1;
                    max1 = w[v];
                }
                else if(w[v] >= max2) {
                    max2 = w[v];
                }
            }
        }
        maxx = max(maxx, max1 * max2);
        sum = (sum + tmp1 * tmp1 % MOD - tmp2) % MOD;
    }

    cout << maxx << ' ' << sum;

    return 0;
}