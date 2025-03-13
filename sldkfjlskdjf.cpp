      
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e6 + 3;
int n, m, k, f[N], a[N], b[N], c[N];
int main() {
    // freopen("in.txt", "r", stdin);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> c[i];
        if(c[i] > 0)a[c[i]]++;
        if(c[i] < 0)b[-c[i]]++;
    }
    for(int i = 1;i <= n;i++) {
        if(c[i] > 0)a[c[i]]--;
        if(c[i] < 0)b[-c[i]]--;
        k += c[i] == 0;
        if(c[i] == 0)for(int i = k;i >= 0;i--)
            f[i] = max(f[i - 1] + a[i], f[i] + b[k - i]);
    }
    int as = 0;
    for(int i = 0; i <= m; ++i) as = max(as, f[i]);
    cout << as << endl;
}

    