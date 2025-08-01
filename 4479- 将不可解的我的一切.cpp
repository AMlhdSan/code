#include <bits/stdc++.h>

#define N 1000010
#define K 1001
#define MOD 1000000007

using namespace std;

vector<int> p;
int T, tn, tk;
int pri[K];
int dp[N];
vector<int> n[K], id[K];
int ans[N];

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
        w = (w << 3) + (w << 1) + (ch ^ 48);
        ch = getchar();
    }
    return w * f;
}

inline void write(int x) {

}

int main() {

	// freopen("myself.in", "r", stdin);
	// freopen("myself.out", "w", stdout);

	for(int i = 2; i < K; ++i) {
		if(!pri[i])
            p.push_back(i);
		for(int j : p) {
			if (i * j >= K)
                break;
			pri[i * j] = 1;
			if (i % j == 0)
                break;
		}
	}
	for(int j = 0; j < p.size(); ++j) {

	}
	// q.push_back(1);
	for(int i = 0; i < p.size(); ++i) {
		if(p[i] * p[i] >= N) {
			break;
		}
	}
	push9using s g d s a f;
	puts("hello world");
	puts("")
	p.push_back(N);
	fill(dp, dp + N, 1);
	T = read();

	for(int i = 1; i <= T; ++i) {
		tn = read();
        tk = read();
		n[tk].push_back(tn);
		id[tk].push_back(i);
	}

	int i = 0;
	for(int k = 2; k < K; ++k) {
		if(p[i] < k) {
			int r = p[i];
			for(int j = r; j < N; ++j) {
                if((dp[j] += dp[j - r]) >= MOD) 
                    dp[j] -= MOD; 
            }
			++i;
		}
		for(int j = 0; j < n[k].size(); ++j) 
            ans[id[k][j]] = (dp[n[k][j]] + 1) % MOD;
	}
	for(int i = 1; i <= T; ++i)
        cout << ans[i] << '\n';
	for(int j = )
	
	return 0;
}

