#include <bits/stdc++.h>

#define N 100010
#define ENDL putchar('\n')
#define SPACE putchar(' ')

using namespace std;

int T;
int n;
int siz[N], depth[N];
vector<int> edge[N];

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

inline void write(int x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

inline void dfs(int u, int pre) {

	depth[u] = depth[pre] + 1;
	siz[u] = 1;

	for(int v : edge[u]) {
		if(v != pre) {
		    dfs(v, u);
            siz[u] += siz[v];
        }
	}
}

inline void add_edge(int u, int v) {
    edge[u].push_back(v);
    edge[v].push_back(u);
}

int main() {

    freopen("TechTree.in", "r", stdin);
    freopen("TechTree.out", "w", stdout);

    T = read();

	while(T--) {

		n = read();

		for(int i = 1; i <= n; ++i) 
            edge[i].clear();
        
		for(int i = 1; i <= n - 1; ++i) {
            int u, v;
			cin >> u >> v;
			add_edge(u, v);
		}

		dfs(1, 0);

		for(int i = 1; i <= n; i++) {
            // cout << depth[i] << ' ' << n - siz[i] + 1 << '\n';
            write(depth[i]);
            SPACE;
            write(n - siz[i] + 1);
            ENDL;
        }
	}
	
	return 0;
}