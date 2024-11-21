#include <iostream>
#include <algorithm>

#define lowbit(x) ((x) & -(x))

using namespace std;

const int N = 1000010, M = 2000010;
int a[N], b[N], tmp[M], top;
int n;
int maxx = 0;
int f, g;

inline int read() {
    int x = 0, f = 1;
    char ch = 0;
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = getchar_unlocked();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch - '0');
        ch = getchar_unlocked();
    }
    return x * f;
}

struct BIT {
	int f[M];
	void add(int x, int k) { 
        while(x <= top) {
            f[x] = max (f[x], k);
            x += lowbit (x);
        }
    }
	int qry(int x) { 
        int r = 0; 
        while(x) {
            r = max(r, f[x]);
            x -= lowbit (x);
        }
        return r;
    }
};

BIT xx, yy;

int main() {
	freopen ("a.in", "r", stdin);
	freopen ("a.out", "w", stdout);

	cin >> n;

	for(int i = 1; i <= n; i++) {
        cin >> a[i];
        tmp[i] = a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        tmp[i + n] = b[i];
    }
	sort(tmp + 1, tmp + n * 2 + 1);
	top = unique(tmp + 1, tmp + 2 * n + 1) - (tmp + 1);
	for(int i = 1; i <= n; ++i)  {
        a[i] = lower_bound (tmp + 1, tmp + top + 1, a[i]) - tmp;
    }
    for(int i = 1; i <= n; ++i) {
        b[i] = lower_bound (tmp + 1, tmp + top + 1, b[i]) - tmp;
    }
    
	for(int i = 1; i <= n; ++i) {
		f = max(xx.qry (a[i] - 1) + 1, yy.qry(a[i] - 1) + 1);
        g = max(xx.qry (b[i] - 1) + 1, yy.qry(b[i] - 1) + 1);
		xx.add (a[i], f);
        yy.add (b[i], g);
		maxx = max(maxx, max(f, g));
	}
	cout << maxx << endl;
	return 0;
}
