#include <bits/stdc++.h>

#define N 300010

using namespace std;

int n,q,cnt;
int a[N],pos[N];
int x, y;

int main() {

	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i]
		pos[a[i]] = i;
		if(i != 1 && a[i - 1] + 1 != a[i]){
			++cnt;
		}
	}
    if(1 + a[n] != a[1])
        ++cnt;

	a[n + 1] = a[1];
    a[0] = a[n];

	while(q--) {
        
		cin >> x >> y;

		x = pos[x];
		y = pos[y];

		if(x>y)swap(x,y);
		if(1+a[(x==1?n:x-1)]!=a[x])cnt--;
		if(1+a[x]!=a[x+1]&&x!=y-1)cnt--;
		if(1+a[y-1]!=a[y])cnt--;
		if(1 + a[y] != a[y + 1])
            --cnt; 
		
		swap(a[x],a[y]);
		pos[a[x]]=x;
		pos[a[y]]=y;
		a[n+1]=a[1];
		
		if(1 + a[(x == 1 ? n : x - 1)] != a[x])
            ++cnt;
		if(1 + a[x] != a[x + 1] && x != y - 1)
            ++cnt;
		if(1 + a[y - 1] != a[y])
            ++cnt;
		if(1 + a[y] != a[y + 1])
            cnt++;
		 
		if(cnt<=1)cout<<"DA\n";
		else cout<<"NE\n";
	}
	return 0;
}