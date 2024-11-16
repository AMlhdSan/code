#include <bits/stdc++.h>

#define N 1000001

using namespace std;

int n;
char ch[N];
int ans = 0;
int x = 0;

int main() {

    cin >> n;
    for(int)
    
    
    for(int i = n; i >= 1; --i) {
        if(ch[i] - 'A' == x) 
            continue;
        if(ch[i] == ch[i - 1]) 
            x = !x;
        ++ans;
    }
    cout << ans << endl;
    return 0;
}