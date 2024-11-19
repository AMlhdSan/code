#include <bits/stdc++.h>

#define N 1000001

using namespace std;

char s[N], t[N];
int kmp[N];
int top = 0;
char stack[N];
int ls, lt;

int main() {

    cin >> s + 1;
    cin >> t + 1;
    ls = strlen(s + 1);
    lr = strlen(t + 1);
    
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
        if(j == lt) {
            if()
        }
    }

    return 0;
}