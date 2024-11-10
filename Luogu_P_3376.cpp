#include <bits/stdc++.h>
using namespace std;
int n,m,s,t,u,v;
long long w,ans,dis[520010];
int tot=1,vis[520010],pre[520010],head[520010],flag[2510][2510];

struct node {
	int to,net;
	long long val;
} e[520010];

inline void add(int u,int v,long long w) {
	e[++tot].to=v;
	e[tot].val=w;
	e[tot].net=head[u];
	head[u]=tot;
	e[++tot].to=u;
	e[tot].val=0;
	e[tot].net=head[v];
	head[v]=tot;
}

inline int bfs() { 
	for(register int i=1;i<=n;i++) vis[i]=0;
	queue<int> q;
	q.push(s);
	vis[s]=1;
	dis[s]=2005020600;
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		for(register int i=head[x];i;i=e[i].net) {
			if(e[i].val==0) continue; 
			int v=e[i].to;
			if(vis[v]==1) continue; 
			dis[v]=min(dis[x],e[i].val);
			pre[v]=i;
			q.push(v);
			vis[v]=1;
			if(v==t) return 1; 
		}
	}
	return 0;
}

inline void update() { 
	int x=t;
	while(x!=s) {
		int v=pre[x];
		e[v].val-=dis[t];
		e[v^1].val+=dis[t];
		x=e[v^1].to;
	}
	ans+=dis[t];
}

int main() {
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(register int i=1;i<=m;i++) {
		scanf("%d%d%lld",&u,&v,&w);
		if(flag[u][v]==0) {
			add(u,v,w);
			flag[u][v]=tot;
		}
		else {
			e[flag[u][v]-1].val+=w;
		}
	}
	while(bfs()!=0) {
		update();
	}
	printf("%lld",ans);
	return 0;
}
