#include<bits/stdc++.h>

#define N 1010

using namespace std;
int n,  m;
int a[N][N];
int f[N][N];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int fa[N * N];
int s[N * N];
int ans = 0;
struct node {
	int x, y, val;
}b[1000005];

inline void write(int x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
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

inline bool cmp(node a,  node b) {
    return a.val < b.val;
}

inline int find(int x) {
    return fa[x] == x ? x : fa[x]  =  find(fa[x]);
}

inline void merge(int x, int y) {
	x = find(x);
    y = find(y);
    if(x !=  y) {
	    fa[x]  =  y;
        s[y] |=  s[x];
    }
}

int id(int x, int y) {
    return (x - 1) * m + y;
}

signed main() {

	n = read();
    m = read();

    memset(a, 0x3f, sizeof(a));

	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			a[i][j] = read();
			if(a[i][j] < 0)
                a[i][j] = abs(a[i][j]);
			else f[i][j] = 1;
			b[id(i, j)] = (node){i, j, a[i][j]};
			fa[id(i, j)] = id(i, j);
		}
	sort(b + 1, b + id(n, m) + 1, cmp);

	for(int i = 1; i <= n * m; ++i) {
		for(int j = 0; j < 4; ++j) {
			int tx = b[i].x + dx[j], ty = b[i].y + dy[j];
			if(a[tx][ty] <= b[i].val)
                merge(id(tx, ty), id(b[i].x, b[i].y));
		}
		if(b[i].val != b[i + 1].val) {
			for(int j = i;; --j) {
				if(b[j].val != b[i].val)
                    break;
				if(f[b[j].x][b[j].y]) {
					int h = find(id(b[j].x, b[j].y));
					if(!s[h]) {
                        s[h] = 1;
                        ++ans;
                    }
				}
			}
		}
	}
	cout << ans << endl;
 	return 0;
}