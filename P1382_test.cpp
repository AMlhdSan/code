#include <bits/stdc++.h>

using namespace std;
struct Node
{
	int le,ri;
	int mx;
}t[4000005];
int a[4000005],x[4000005],y[4000005],h[4000005];
void BuildT(int id,int l,int r)
{
	t[id].le=l;
	t[id].ri=r;
	t[id].mx=0;
	if(l==r)
	{
		return;
	}
	int mid=(l+r)/2;
	BuildT(id*2,l,mid);
	BuildT(id*2+1,mid+1,r);
}
void Push(int id)
{
	t[id*2].mx=max(t[id*2].mx,t[id].mx);
	t[id*2+1].mx=max(t[id*2+1].mx,t[id].mx);		
}
void Change(int id,int l,int r,int c)
{
    if(t[id].le==l&&t[id].ri==r)
    {
        t[id].mx=max(t[id].mx,c);
        return;
    }
    Push(id);
    if(r<=t[id*2].ri)
    {
        Change(id*2,l,r,c);
    }
    else if(l>=t[id*2+1].le)
    {
        Change(id*2+1,l,r,c);
    }
    else
    {
        Change(id*2,l,t[id*2].ri,c);
        Change(id*2+1,t[id*2+1].le,r,c);
    }
}
int Query(int id,int pos)//查询
{
	if(t[id].le==t[id].ri)
	{
		return t[id].mx;
	}
	Push(id);
	if(pos<=t[id*2].ri)
	{
		return Query(id*2,pos);
	}
	else
	{
		return Query(id*2+1,pos);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d%d",&h[i],&x[i],&y[i]);
		a[i*2-1]=x[i];
		a[i*2]=y[i];
	}
	sort(a+1,a+2*n+1);
	int m=unique(a+1,a+2*n+1)-a-1;
	BuildT(1,1,m);
	for(int i=1;i<=n;++i)//离散化部分，就不解释了
	{
		x[i]=lower_bound(a+1,a+m+1,x[i])-a;
		y[i]=lower_bound(a+1,a+m+1,y[i])-a;
		Change(1,x[i],y[i]-1,h[i]);
	}
	int cnt=0;
	int last=0;
	x[++cnt]=a[1];
	y[cnt]=0;
	for(int i=1;i<m;++i)
	{
		int height=Query(1,i);
		if(height!=last)
		{
			x[++cnt]=a[i];
			y[cnt]=height;
			x[++cnt]=a[i+1];
			y[cnt]=height;
		}
		else
		{
			x[cnt]=a[i+1];
		}
		last=height;//对于每个单位，求出高度，把结果存进数组里
	}
	printf("%d\n",cnt+1);
	for(int i=1;i<=cnt;++i)
	{
		printf("%d %d\n",x[i],y[i]);
	}
	printf("%d 0",a[m]);
	return 0;
}