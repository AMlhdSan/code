#include <bits/stdc++.h>

#define N 300010

using namespace std;

int n,q,sum;
int a[N],pos[N];
int u, v;

int main() {

	cin >> n >> q;

	for(int i = 1; i <= n; ++i) {
		cin >> a[i]
		pos[a[i]] = i;
		if(i != 1 && a[i - 1] + 1 != a[i]){
			++sum;
		}
	}

    if(1 + a[n] != a[1])
        ++sum;

	a[n + 1] = a[1];
    a[0] = a[n];

	while(q--) {

		cin >> u >> v;

		u = pos[u];
		v = pos[v];

		if(u > v)
            swap(u, v);
		if(1 + a[(u == 1? n : u - 1)] != a[u])
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
		
		if(1 + a[(u == 1 ? n : u - 1)] != a[u])
            ++sum;
		if(1 + a[u] != a[u + 1] && u != v - 1)
            ++sum;
		if(1 + a[v - 1] != a[v])
            ++sum;
		if(1 + a[v] != a[v + 1])
            sum++;
		 
		if(sum <= 1)
            cout << "DA" << endl;
		else 
            cout << "NE" << endl;
	}
	return 0;
}