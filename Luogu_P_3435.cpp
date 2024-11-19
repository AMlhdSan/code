#include <bits/stdc++.h>

#define N 1000001

using namespace std;

long long kmp[N];
int n;
char a[N];
long long sum = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> a + 1;

    int j = 0;

    for(register int i = 1; i <= n; ++i) {     
	    while(j && a[i + 1] != a[j + 1])
            j = kmp[j];
        if(a[j + 1] == a[i + 1])
            kmp[i + 1] = ++j;
    }

    for(register int i = 1; i <= n; ++i) {
        j = i;
        while(kmp[j])
            j = kmp[j];
        if(kmp[j]) 
            kmp[i] = j;
        sum += i - j;
    }

    cout << sum << endl;
    return 0;
}