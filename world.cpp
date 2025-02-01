#include <bits/stdc++.h>

#define N 10010

using namespace std;

int n, k;
bool flag = false;
bool tu[N][N];

int p[N];
int tmp;

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

inline void write(int x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x > 9) {
        write(x / 10);
    }
    putchar(x % 10 + '0');
}

inline void ENDL() {
    putchar('\n');
}

int main() {

    freopen("world.in", "r", stdin);
    freopen("world.out", "w", stdout);

    n = read();
    k = read();

    if(k <= 2) {
        for(int i = 1; i <= n; ++i) {
            p[i] = read();
            if(p[i]) {
                flag = true;
            }
        }
        if(flag) {
            cout << "2" << endl;
        } 
        else {
            cout << "1" << endl;
        }
    }
    else {
        for(int i = 1; i <= n; ++i) {
            cin >> p[i];
            if(p[i]) 
                flag = true;
            for(int j = 1; j <= p[i]; ++j) {
                cin >> tmp;
                tu[i][tmp + 1] = true;
            }
        }
        for(int i = 1; i <= n; ++i)
            for(int j = i + 1; j <= n; ++j)
                if(tu[i][j])
                    for(int k = j + 1; k <= n; ++k)
                        if(tu[i][k] && tu[j][k]) {
                            cout << "3" << endl;
                            return 0;
                        }
        if(flag)
            cout << "2" << endl;
        else {
            cout << "1" << endl;
        }                                                                                           
    }
    return 0;
}