#include<bits/stdc++.h>

#define INF 0x7fffffff
#define N 1000010
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

int T, n;
int opt[N], d[N], a[N], b[N];
int c[N], tmp[N];
multiset<int> s[N][4];
long long minn[N << 2][4];
long long tree[N << 2];

inline int read() {
    int x = 0, f = 1;
    char ch = getchar_unlocked();
    while(ch < '0' || ch > '9') {
        if(ch == '-')
            f = -1;
        ch = getchar_unlocked();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar_unlocked();
    }
    return x * f;
}

inline void write(int x)
{
    if(x < 0)
        putchar_unlocked('-'), x = -x;
    if(x > 9)
        write(x / 10);
    putchar_unlocked(x % 10 + '0');
    return;
}

void build(int p, int l, int r){
	tree[p] = INF;
	for(int i = 0;i < 4; ++i) 
        minn[p][i] = INF;
	if(l == r) {
		for(int i = 0; i < 4; ++i)
			s[l][i].insert(INF);
		return;
	}
	build(ls, l, mid);
    build(rs, mid + 1, r);
}

void upd(int p, int l, int r, int pos, int x){

	if(l == r) {
		if(opt[x] && d[x]) {
			s[l][0].insert(a[x]);
			s[l][1].insert(b[x]);
		}
        else if(opt[x] && !d[x]) {
			s[l][2].insert(a[x]);
			s[l][3].insert(b[x]);
		}
        else if(!opt[x] && d[x]) {
			s[l][0].erase(s[l][0].find(a[x]));
			s[l][1].erase(s[l][1].find(b[x]));
		}
        else if(!opt[x] && !d[x]) {
			s[l][2].erase(s[l][2].find(a[x]));
			s[l][3].erase(s[l][3].find(b[x]));
		}

		for(int i = 0;i < 4; ++i) 
            minn[p][i] = *s[l][i].begin();

		tree[p] = min(minn[p][0] + minn[p][2], minn[p][1] + minn[p][3]);
		
        return;
	}

	if(pos <= mid) 
        upd(ls, l, mid, pos, x);
	else 
        upd(rs, mid + 1, r, pos, x);

	for(int i = 0; i < 4; ++i)
		minn[p][i] = min(minn[ls][i], minn[rs][i]);

	tree[p] = min(tree[ls], tree[rs]);

	tree[p] = min(tree[p], minn[ls][2] + minn[rs][0]);

	tree[p] = min(tree[p], minn[ls][1] + minn[rs][3]);
}

int main() {

	// freopen("a.in", "r", stdin);
	// freopen("a.out", "w", stdout);
    
	T = read();

	for(int i = 1; i <= T; ++i) {

		opt[i] = read();
        d[i] = read();
        a[i] = read();
        b[i] = read();

		if(d[i]) 
            c[i] = a[i] - b[i];
		else 
            c[i] = b[i] - a[i];
        
		tmp[i] = c[i];
	}

	sort(tmp + 1,tmp + T + 1);
    
	n = unique(tmp + 1,tmp + T + 1) - (tmp + 1);

	build(1, 1, n);

	for(int i = 1; i <= T; ++i) {
		c[i] = lower_bound(tmp + 1, tmp + n + 1, c[i]) - tmp;
		upd(1, 1, n, c[i], i);
		if(tree[1] >= INF)
            write(-1), putchar_unlocked('\n');
		else 
            write(tree[1]), putchar_unlocked('\n');
	}
    return 0;
}