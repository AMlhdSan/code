#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int solve(int x) {
    int cnt[10];
    memset(cnt, 0, sizeof(cnt));

    while (x > 0) {
        cnt[x % 10]++;
        x /= 10;
    }

    int maxx = 0, maxxx = 0;
    for (int i = 0; i < 10; i++) {
        if (cnt[i] > maxx || (cnt[i] == maxx && i > maxxx)) {
            maxx = cnt[i];
            maxxx = i;
        }
    }

    return maxxx;
}

int main() {

    freopen("gift.in", "r", stdin);
    freopen("gift.out", "w", stdout);

    long long n;
    cin >> n;

    long long sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += solve(i);
        sum %= MOD;
    }

    cout << sum << endl;

    return 0;
}
