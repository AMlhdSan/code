#include <bits/stdc++.h>
using namespace std;


inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

inline void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(int x) {
    write(x);
    putchar('\n');
}

struct Node{
    int child[2];
    int subtree;
    int end;
};
const int MAX_NODES = 500005;
Node trie[MAX_NODES];
int tot = 1;
void initTrie(){
    trie[0].subtree = 0;
    trie[0].end = 0;
    trie[0].child[0] = trie[0].child[1] = -1;
    trie[0].subtree = 0;
    for(int i = 1; i < MAX_NODES; i++){
        trie[i].child[0] = trie[i].child[1] = -1;
        trie[i].subtree = 0;
        trie[i].end = 0;
        trie[i].subtree = 0;
    }
}
void insertMessage(int len){
    int cur = 0;
    trie[cur].subtree++;
    for(int i = 0; i < len; i++){
        int d = read();
        if(trie[cur].child[d] == -1){
            trie[cur].child[d] = tot;
            trie[tot].child[0] = trie[tot].child[1] = -1;
            trie[tot].subtree = 0;
            trie[tot].end = 0;
            tot++;
        }
        cur = trie[cur].child[d];
        trie[cur].subtree++;
    }
    trie[cur].end++;
}
int queryCipher(int len){
    int cur = 0;
    for(int i = 0; i < len; i++){
        int d = read();
        if(trie[cur].child[d] == -1) return trie[cur].end;
        cur = trie[cur].child[d];
    }
    return trie[cur].subtree;
}
int main(){
    initTrie();
    int M = read(), N = read();
    for(int i = 0; i < M; i++){
        int len = read();
        insertMessage(len);
    }
    for(int j = 0; j < N; j++){
        int len = read();
        int ans = queryCipher(len);
        writeln(ans);
    }
    return 0;
}