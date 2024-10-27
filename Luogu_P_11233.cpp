#include <bits/stdc++.h>
#define N 1001
using namespace std;

int T;
int n;
int a[N];
bool ch[N];
int maxx = -1;

void dfs(int s) {
    if(s == n) {
        int sum = 0;
        for(int i = 2; i <= n; ++i) {
            for(int j = i - 1; j >= 1; --j) {
                if(ch[i] == ch[j]) {
                    if(a[i] == a[j]) {
                        sum += a[i];
                    }
                    break;
                }
            }
        }
        maxx = max(maxx, sum);
        return;
    }
    ++s;
    ch[s] = 1;
    dfs(s);
    ch[s] = 0;
    dfs(s);
}

int main() {

    cin >> T;
    while(T--) {
        maxx = -1;
        cin >> n;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        dfs(0);
        cout << maxx << endl;
    }

    return 0;
}