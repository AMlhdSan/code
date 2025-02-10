#include <bits/stdc++.h>

#define N 100010

using namespace std;

int n, q;
char s[N];
int sum = 0;
int trie[N][30];

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

inline void in(char str[]) {
    for(int i = 1; i <= strlen(str); ++i) {
        if(trie[i][str[i] - 'a']) {
            ++trie[i][str[i] - 'a'];
        }
        else {
            while(trie[i][str[i]])
        }
    }

}

int main() {

    n = read();
    q = read();

    for(int i = 1; i <= n; ++i) {
        cin >> s + 1;
        in(s);
    }

    while(q--) {
        sum = 0;
        string str;
        cin >> str;
        str = ' ' + str;

    }

    return 0;
}