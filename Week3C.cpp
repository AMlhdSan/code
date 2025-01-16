#include <bits/stdc++.h>

#define N 100010

using namespace std;

int s[N], t[N];
int q;
string ss, tt;
int a, b, c, d;

inline void init() {
	for(int i = 0; i < ss.size(); ++i) {
		if(ss[i] == 'A') {
			s[i + 1] = s[i] + 1;
		}
		else {
			s[i + 1] = s[i] + 2;
		}
	}
	for(int i = 0; i < tt.size(); ++i) {
		if(tt[i] == 'A') {
			t[i + 1] = t[i] + 1;
		}
		else {
			t[i + 1] = t[i] + 2;
		}
	}
}

int main() {

	cin >> ss;
	cin >> tt;

	init();

	cin >> q;
	while(q--) {
		cin >> a >> b >> c >> d;
		if((s[b] - s[a - 1]) % 3 == (t[d] - t[c - 1]) % 3) {
			puts("YES");
		}
		else {
			puts("NO");
		}
	}

	return 0;
}