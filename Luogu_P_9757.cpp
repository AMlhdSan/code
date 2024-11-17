#include <bits/stdc++.h>

#define N 300005

using namespace std;

int n, q;
int sum = 0;
int a[N], pos[N];
int u, v;

inline int read() {
    int x = 0, f = 1;
    char ch = 0;
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch - '0');
        ch = getchar();
    }
    return x * f;
}

int last(int t) {
    if(t == 1) {
        return n;
    }
    else {
        return t - 1;
    }
}

int main() {

	n = read();
    q = read();

	for(int i = 1; i <= n; ++i) {
		a[i] = read();
		pos[a[i]] = i;
		if(i != 1 && a[i - 1] + 1 != a[i]){
			++sum;
		}
	}

    a[n + 1] = a[1];

    if(1 + a[n] != a[n + 1])
        ++sum;

	while(q--) {

		u = read();
        v = read();

		u = pos[u];
		v = pos[v];

		if(u > v)
            swap(u, v);
		if(1 + a[last(u)] != a[u])
            --sum;
		if(1 + a[u] != a[u + 1] && u != v - 1)
            --sum;
		if(1 + a[v - 1] != a[v])
            --sum;
		if(1 + a[v] != a[v + 1])
            --sum; 
		
		swap(a[u], a[v]);

		pos[a[u]] = u;
		pos[a[v]] = v;

		a[n + 1] = a[1];
		
		if(1 + a[last(u)] != a[u])
            ++sum;
		if(1 + a[u] != a[u + 1] && u != v - 1)
            ++sum;
		if(1 + a[v - 1] != a[v])
            ++sum;
		if(1 + a[v] != a[v + 1])
            ++sum;
		 
		if(sum <= 1)
            cout << "DA" << endl;
		else 
            cout << "NE" << endl;
	}
	return 0;
}