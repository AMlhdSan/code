#include <bits/stdc++.h>

#define N 500001

using namespace std;
int n, m, s, t;
int u,v;
long long w;
long long ans, dis[N];
int tot = 1;
int now[N], head[N]; 

struct node {
	int to, nxt;
	long long val;
}e[N];

inline void add(int u, int v, long long w) {
	e[++tot].to = v;
	e[tot].val = w;
	e[tot].nxt = head[u];
	head[u] = tot;
	
	e[++tot].to=u;
	e[tot].val=0;
	e[tot].nxt=head[v];
	head[v]=tot;
}

inline int bfs() {  //在惨量网络中构造分层图 
	for(register int i=1;i<=n;i++) dis[i]=inf;
	queue<int> q;
	q.push(s);
	dis[s]=0;
	now[s]=head[s];
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		for(register int i=head[x];i;i=e[i].nxt) {
			int v=e[i].to;
			if(e[i].val>0&&dis[v]==inf) {
				q.push(v);
				now[v]=head[v];
				dis[v]=dis[x]+1;
				if(v==t) return 1;
			}
		}
	}
	return 0;
}

inline int dfs(int x,long long sum) {  //sum是整条增广路对最大流的贡献
	if(x==t) return sum;
	long long k,res=0;  //k是当前最小的剩余容量 
	for(register int i=now[x];i&&sum;i=e[i].nxt) {
		now[x]=i;  //当前弧优化 
		int v=e[i].to;
		if(e[i].val>0&&(dis[v]==dis[x]+1)) {
			k=dfs(v,min(sum,e[i].val));
			if(k==0) dis[v]=inf;  //剪枝，去掉增广完毕的点 
			e[i].val-=k;
			e[i^1].val+=k;
			res+=k;  //res表示经过该点的所有流量和（相当于流出的总量） 
			sum-=k;  //sum表示经过该点的剩余流量 
		}
	}
	return res;
}

int main() {
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(register int i=1;i<=m;i++) {
		scanf("%d%d%lld",&u,&v,&w);
		add(u,v,w);
	}
	while(bfs()) {
		ans+=dfs(s,inf);  //流量守恒（流入=流出） 
	}
	printf("%lld",ans);
	return 0;
}