#include<bits/stdc++.h>

using namespace std;

long long n, k, m, ans, minn = 0x7fffffff, t[500010];
int a[500010];

inline long long read() {
    long long x = 0, f = 1;
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

inline void write(long long x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(long long x) {
    write(x);
    putchar('\n');
}

int main() {
    n = read();
	k = read();
	m = read();

	for(int i = 1; i <= k; i++){
		int b;
		a[i] = read();
		b = read();
		if(b==1){
			t[i] = a[i] - n;
		}
		else{
			t[i] = n - a[i];
		}
	}
	sort(t + 1, t + k + 1);
	t[0] = t[k];
	writeln(2 * (n - 1) * (m / k) + t[m % k]);
	return 0;
}