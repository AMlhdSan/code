#include <bits/stdc++.h>

#define N 1000100

using namespace std;

char s[N], t[N];
int kmp[N];
int top = 0;
int stackk[N];
int ls, lt;
int me[N];

int main() {

    cin >> s + 1;
    cin >> t + 1;
    ls = strlen(s + 1);
    lt = strlen(t + 1);
    
    int j = 0;

    for(int i = 1; i <= lt; ++i) {
        while(j && t[j + 1] != t[i + 1]) {
            j = kmp[j];
        }
        if(t[j + 1] == t[i + 1]) {
            ++j;
            kmp[i + 1] = j;
        }
    }

    j = 0;

    for(int i = 1; i <= ls; ++i) {
        while(j && s[i] != t[j + 1]) {
            j = kmp[j];
        }
        if(s[i] == t[j + 1]) {
            ++j;
        }
        me[i] = j;
        stackk[++top] = i;
        if(j == lt) {
            top -= lt;
            j = me[stackk[top]];
        }
    }

    for(int i = 1; i <= top; ++i) {
        cout << s[stackk[i]];
        cout << ' ';
    }

    cout << endl;

    return 0;
}