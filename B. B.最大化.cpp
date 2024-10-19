#include <bits/stdc++.h>

#define N 100001

using namespace std;
int T, n, m;
long long sum = 0;
int t[N];
int x, y, c, d;

inline int read() {
    int w = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        w = (w << 3) + (w << 1) + (ch - '0');
        ch = getchar();
    }
    return w * f;
}

int main() {

    freopen("max.in", "r", stdin);
	freopen("max.out", "w", stdout); 
    
    cin >> T;

    while (T--) {
        memset(t, 0, sizeof(t));
        sum = 0;
        cin >> n >> m;
        for(int i = 1; i <= m; ++i) {
            x = read();
            c = read();
            y = read();
            d = read();
            if(t[x] == 0) {
                sum += c;
                t[x] = c;
            }
            else if(t[x] == 1) {
                if(c == 2) {
                    t[x] = 2;
                    sum += 1;
                }
            }

            if(t[y] == 0) {
                sum += d;
                t[y] = d;
            }
            else if(t[y] == 1) {
                if(d == 2) {
                    t[y] = 2;
                    sum += 1;
                }
            }
        }
        cout << sum << endl;
    }

    return 0;
}