#include <bits/stdc++.h>
using namespace std;

int n;
map<int, int> sum; // 使用map来处理学号
map<int, int> ans; // 使用map来记录选课次数
int idd;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> p;
        int id[p + 1], sc[p + 1], w[p + 1], scc[p + 1];
        
        for (int j = 1; j <= p; ++j) {
            cin >> id[j];
            ans[id[j]]++;
        }
        sort(id + 1, id + p + 1);
        for (int j = 1; j <= p; ++j) {
            cin >> sc[j];
            scc[j] = sc[j];
        }
        for (int j = 1; j <= p; ++j) {
            cin >> w[j];
        }

        sort(scc + 1, scc + p + 1);


        for (int j = 1; j <= p; ++j) {
            int rank = upper_bound(scc + 1, scc + p + 1, sc[j]) - scc;
            sum[id[j]] += w[p - rank + 2];
        }
    }

    cin >> idd;


    if (sum[idd] % ans[idd] == 0) {
        cout << sum[idd] / ans[idd] << endl;
    } else {
        int g = gcd(sum[idd], ans[idd]);
        int a = sum[idd] / ans[idd];
        sum[idd] -= a * ans[idd];
        cout << a << '+' << (sum[idd] / g) << "/" << (ans[idd] / g) << endl;
    }

    return 0;
}
