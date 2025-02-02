#include<bits/stdc++.h>

using namespace std;

int T;
int n;
int fa[30001];
int front[30001];
int num[30001];
int ans;

int find(int n) {
    if(fa[n] == n)
        return fa[n];
    int fn = find(fa[n]);                 
    front[n] += front[fa[n]];
    return fa[n] = fn;
}

inline void init() {
    for(int i = 1; i <= 30000; ++i) {               
        fa[i] = i;
        front[i] = 0;
        num[i] = 1;
    }
}

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

inline char readchar() {
    char ch = getchar();
    while(ch < 'A' || ch > 'Z') {
        ch = getchar();
    }
    return ch;
}

inline void write(int x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(int x) {
    write(x);
    putchar('\n');
}

int main() {

    cin >> T;

    init();

    while(T--) {
        char op;
        int x, y;
        op = readchar();
        x = read();
        y = read();
        int fx = find(x);
        int fy = find(y);
        if(op == 'M') {
            front[fx] += num[fy];
            fa[fx] = fy;                  
            num[fy] += num[fx];
            num[fx] = 0;
        }
        else
            if(fx != fy)
                writeln(-1);
            else
                writeln(abs(front[x] - front[y]) - 1);
    }
    
    return 0;
}