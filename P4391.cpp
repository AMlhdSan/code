#include <bits/stdc++.h>

#define N 1000001

using namespace std;

char s[N];
int l;
int kmp[N];

int main() {

    cin >> l;
    cin >> s + 1;
    
    int j = 0;

    for(int i = 1; i <= l; ++i) {
        if(j && s[j + 1] != s[i + 1])
            j = kmp[j];
        if(s[j + 1] == s[i + 1])
            kmp[i + 1] = ++j;
    }

    cout << l - kmp[l] << endl;

    return 0;
}