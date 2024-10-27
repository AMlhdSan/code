#include <bits/stdc++.h>

#define N 1000001

using namespace std;

char s1[N], s2[N];
int la, lb;
int j = 0;
int kmp[N];

int main() {
    cin >> s1 + 1;
    cin >> s2 + 1;

    la = strlen(s1 + 1);
    lb = strlen(s2 + 1);

    for(int i = 1; i <= lb; ++i) {
        while(j && s2[i + 1] != s2[j + 1]) {
            j = kmp[j];
        }
        if(s2[i + 1] == s2[j + 1]) {
            ++j;
            kmp[i + 1] = j;
        }
    }

    j = 0;

    for(int i = 1; i <= la; ++i) {
        while(j && s1[i] != s2[j + 1]) {
            j = kmp[j];
        }
        if(s1[i] == s2[j + 1]) {
            ++j;
        }
        if(j == lb) {
            cout << i - lb + 1 << endl;
            j = kmp[j];
        }
    }

    for(int i = 1; i <= lb; ++i) {
        cout << kmp[i] << ' ';
    }
    return 0;
}