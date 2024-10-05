#include <bits/stdc++.h>

#define N 1000001

using namespace std;

int kmp[N];

int la,lb,j; 

char a[N], b[N];

int main() {

    cin >> a + 1;
    cin >> b + 1;

    la = strlen(a + 1);
    lb = strlen(b + 1);

    for(int i = 1; i <= lb; ++i) {     
	    while(j && b[i + 1] != b[j + 1])
            j = kmp[j];
        if(b[j + 1] == b[i + 1])
            kmp[i + 1] = ++j;
    }

    j = 0;
    
    for(int i = 1; i <= la; ++i) {
        while(j > 0 && b[j + 1] != a[i])
            j = kmp[j];
        if(b[j + 1] == a[i]) 
            ++j;
        if(j == lb) {
            cout << i - lb + 1 << endl;
            j = kmp[j];
        }
    }
    for(int i = 1; i <= lb; ++i)
        cout << kmp[i] << " ";
    return 0;
}