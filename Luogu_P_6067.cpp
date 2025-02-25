#include <bits/stdc++.h>

#define int long long
#define N 1000010

using namespace std;

int n;
int a[N], sum[N];
int tot;

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
    if(x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(int x) {
    write(x);
    putchar('\n');
}

signed main() {
	n = read();
	
	for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }
	
	sort(a + 1, a + 1 + n);
	
	for(int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + a[i];
    }
	
	for(int i = 1; i <= n; ++i) {
		tot += a[i] * (i - 1) - sum[i - 1];
    }
	
	writeln(tot * 2);

	return 0;
}