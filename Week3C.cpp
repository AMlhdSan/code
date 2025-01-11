#include <bits/stdc++.h>
#define int long long	
using namespace std;

inline int read()
{
	int w=1,s=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)){s=s*10+(ch-'0');ch=getchar();}
	return w*s;
}

const int inf=998244353;
const int maxn=2e6+10;
const int mod=1e9+7;

inline int mul(int a,int b,int mod)
{
    int A=a*(b>>30ll)%mod*(1ll<<30)%mod;
    int B=a*(b&((1ll<<30)-1))%mod;
    return (A+B)%mod;
}
int qw(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1)
            ans = mul(ans, x, mod) % mod;
		x = mul(x, x, mod) % mod;
		y >>= 1;
	}
	return ans;
}
int fac[maxn], inv[maxn];
void get_inv() {
	fac[0] = 1;
	for(int i = 1; i < maxn; ++i) 
	    fac[i] = fac[i - 1] * i % mod;
	inv[maxn - 1] = qw(fac[maxn - 1], mod - 2);
	for(int i=maxn-2;i>=0;i--) 
	inv[i]=inv[i+1]*(i+1)%mod;
}
int C(int b,int a){return (fac[b]*(inv[a]*inv[b-a]%mod))%mod;}
char s[maxn],t[maxn];
int sa[maxn],sb[maxn],ta[maxn],tb[maxn];
signed main()
{
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	scanf("%s",s+1);
	scanf("%s",t+1);
	int n=strlen(s+1),m=strlen(t+1);
	for(int i=1;i<=n;i++)
	{
		sa[i]=sa[i-1]+(s[i]=='A');
		sb[i]=sb[i-1]+(s[i]=='B');
	}
	for(int i=1;i<=m;i++)
	{
		ta[i]=ta[i-1]+(t[i]=='A');
        tb[i]=tb[i-1]+(t[i]=='B');
	}
	int T=read();
	while(T--)
	{
		int a=read(),b=read(),x=read(),y=read();
		int l=sa[b]-sa[a-1],r=ta[y]-ta[x-1];
		// cout<<l<<' '<<r<<endl;
		l*=2;r*=2;
		l+=sb[b]-sb[a-1];r+=tb[y]-tb[x-1];
		l%=3;r%=3;
		puts(l==r?"YES":"NO");
	}
	return 0;
}