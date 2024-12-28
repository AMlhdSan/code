#include <bits/stdc++.h>



using namespace std;

int n, m;
char tmp[500010];
int trie[500010][26];
int tot = 1;
int tag[500010];

int main() {

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> tmp + 1;
        int u = 1;
        for(int j = 1; tmp[j]; ++j) {
            int c = tmp[j] - 'a';
            if(!trie[u][c]) {
                trie[u][c] = ++tot;
            }
            u = trie[u][c];
        }
        tag[u] = 1;
    }

    cin >> m;

    while(m--) {
        cin >> tmp + 1;
        int u = 1;
        for(int j = 1; tmp[j]; ++j) {
            int c = tmp[j] - 'a';
            u = trie[u][c];
            if(!u) {
                break;
            }
        }
        if(u && tag[u] == 1) {
            tag[u] = 2;
            puts("OK");
        }
        else if(u && tag[u] == 2) {
            puts("REPEAT");
        }
        else {
            puts("WRONG");
        }
    }
    return 0;
}