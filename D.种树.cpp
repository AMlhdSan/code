#include <bits/stdc++.h>

#define int long long
#define PII pair<int, int>
#define N 300010
#define fi first
#define se second

using namespace std;

int n, m;
int ans;
int a[N];
int pre[N], nxt[N];
int maxx;
priority_queue<PII> pq;
bool vis[N];
void wk(int x) {
	pre[nxt[x]] = pre[x];
	nxt[pre[x]] = nxt[x];
}

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

int main() {

	n = read();
	m = read();

	for(int i = 1; i <= n; ++i) {
		a[i] = read();
		pq.push(make_pair(a[i], i));
		pre[i] = i - 1;
		nxt[i] = i + 1;
	}

	while(m--) {
		PII now = pq.top();
		pq.pop();
		while(vis[now.se]) {
			now = pq.top();
			pq.pop();
		}
		
		int x = now.se;
		ans += a[x];

		if(maxx >= ans) {
			write(maxx);
			putchar('\n');
			return 0;
		}
		else 
			maxx = ans;
		
		a[x] = a[pre[x]] + a[nxt[x]] - a[x];

		pq.push(make_pair(a[x],x));

		vis[pre[x]] = vis[nxt[x]] = 1;

		wk(pre[x]);
		wk(nxt[x]);
	}

	write(maxx);
	putchar('\n');

	return 0;
}