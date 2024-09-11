#include <bits/stdc++.h>
using namespace std;

int n, d;
int v[100001];
int a[100001];
long long sum = 0;
int fee = 0x7fffffff;
int noww;
int s;

int main() {

    cin >> n >> d;

    v[1] = 0;

    for(int i = 1; i <= n - 1; ++i)
        cin >> v[i];

    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    
    fee = a[1];

    for(int i = 1; i <= n - 1; ++i) {
        s += v[i];
        if(fee >= a[i]) {
            fee = a[i];
        }
        if(s <= 0) {
            continue;
        }
        sum += (s + d - 1) / d * fee;
        s -=  (s + d - 1) / d * d;
    }

    cout << sum << endl;

    return 0;
}