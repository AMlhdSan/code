#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	freopen("prize.in","r",stdin);
	freopen("prize.out","w",stdout);
	int t;
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		ll n,x,y,m;cin>>n>>x>>y>>m;
		if(m>(__int128)n*y) cout<<"No\n";
		else{
			ll d=n*y-m;
			if(d<y+1>>1){
				if(d%(y-x)||d/(y-x)>n) cout<<"No\n";
				else cout<<"Yes\n";
			}
			else cout<<"Yes\n";
		}
	}
	return 0;
}