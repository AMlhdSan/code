#include<iostream>
    #include<cstdio>
    #include<cstring>
    #include<iomanip>
    #include<algorithm>
    #include<cmath>
    #include<queue>
    #define in(x) scanf("%d",&x)
    using namespace std;
    const int maxn=1e5;
    int n,all=0,num=0,nxt[maxn],to[maxn],head[maxn],d[maxn];
    int w[maxn],cnt=1,s=0,t=50003,re[maxn],xia[maxn],vis[maxn];
    queue<int>q;
    void add(int x,int y,int we)
    {
        nxt[++cnt]=head[x];head[x]=cnt;to[cnt]=y;w[cnt]=we;
        nxt[++cnt]=head[y];head[y]=cnt;to[cnt]=x;w[cnt]=0;
    }
    int bfs()
    {
        while(q.size()) q.pop();q.push(s);
        memset(d,0,sizeof(d));d[s]=1;
        while(q.size())
        {
            int x=q.front();q.pop();
            for(int i=head[x];i;i=nxt[i])
            {
                int u=to[i];
                if(d[u]||w[i]<=0) continue;
                d[u]=d[x]+1;
                q.push(u);
            }
        }
        return d[t];
    }
    int dfs(int x,int flow)
    {
        if(x==t) return flow;
        int k;
        for(int i=head[x];i;i=nxt[i])
        {
            int u=to[i];
            if(d[u]!=d[x]+1||w[i]<=0) continue;
            if(k=dfs(u,min(w[i],flow)))
            {
                w[i]-=k;w[i^1]+=k;
                if(u!=t) xia[x>>1]=u>>1;
                return k;
            }
        }
        return 0;
    }
    int dinic()
    {
        int k=0;
        while(bfs())
        {
            while(1)
            {
                int p=dfs(s,1e9);
                if(!p) break;
                k+=p;
            }
        }
        return k;
    }
    int main()
    {
        in(n);
        while(all<=n)
        {
            num++;add(s,num<<1,1);add((num<<1)|1,t,1);
            for(int i=sqrt(num)+1;i*i<2*num;++i)
            add((i*i-num)<<1,(num<<1)|1,1);
            int k=dinic();
            if(!k) re[++all]=num;
        }
        printf("%d\n",--num);
        for(int i=1;i<=n;++i)
        {
            if(vis[re[i]]) continue;
            int x=re[i];vis[x]=1;
            while(x!=0)
            {
                printf("%d ",x);
                x=xia[x];vis[x]=1;
            }
            printf("\n");
        }
        return 0;
}