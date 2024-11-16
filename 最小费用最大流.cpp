#include "stdafx.h"
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<iostream>

#define MAXN 5050

using namespace std;

bool vis[MAXN];
int n, m, s, t;
int u, v, c, w;
int cost[MAXN], pre[MAXN], last[MAXN], flow[MAXN];
int maxFlow, minCost;
struct Edge
{
	int from, to, flow, cost;
}edge[MAXN];

int head[MAXN], num_edge;

queue <int> q;

void addedge(int from, int to, int flow, int cost)
{
	edge[++num_edge].from = head[from];
	edge[num_edge].to = to;
	edge[num_edge].flow = flow;
	edge[num_edge].cost = cost;
	head[from] = num_edge;

	edge[++num_edge].from = head[to];
	edge[num_edge].to = from;
	edge[num_edge].flow = 0;
	edge[num_edge].cost = -cost;
	head[to] = num_edge;

}

bool SPFA(int s, int t)
{
	memset(cost, 0x7f, sizeof(cost));
	memset(flow, 0x7f, sizeof(flow));
	memset(vis, 0, sizeof(vis));
	q.push(s); vis[s] = 1; cost[s] = 0; pre[t] = -1;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		vis[now] = 0;
		for (int i = head[now]; i != -1; i = edge[i].from)
		{
			if (edge[i].flow>0 && cost[edge[i].to]>cost[now] + edge[i].cost)
			{
				cost[edge[i].to] = cost[now] + edge[i].cost;
				pre[edge[i].to] = now;
				last[edge[i].to] = i;
				flow[edge[i].to] = min(flow[now], edge[i].flow);
				if (!vis[edge[i].to])
				{
					vis[edge[i].to] = 1;
					q.push(edge[i].to);
				}
			}
		}
	}
	return pre[t] != -1;
}

void MCMF()
{
	while (SPFA(s, t))
	{
		int now = t;
		maxFlow += flow[t];
		minCost += flow[t] * cost[t];
		while (now != s)
		{
			edge[last[now]].flow -= flow[t];
			edge[last[now] ^ 1].flow += flow[t];
			now = pre[now];
		}
	}
}


int _tmain(int argc, _TCHAR* argv[])
{	
	memset(head, -1, sizeof(head)); num_edge = -1;//初始化 

	
	cout << "节点数为："; cin >> n;
	cout << "边数为："; cin >> m;
	cout << "源点编号为："; cin >> s; 
	cout << "汇点编号为："; cin >> t; 

	cout << "输入 " << m << " 条边的信息：" << endl;
	while (m--)
	{
		cout << "起点："; cin >> u; 
		cout << "终点："; cin >> v; 
		cout << "容量："; cin >> c; 
		cout << "费用："; cin >> w; 
		cout << "-----------------" << endl;
		addedge(u, v, c, w);
	}

	MCMF();
	cout << "最大流为：" << maxFlow << endl;
	cout << "最小费用为：" << minCost << endl;
	cout << endl;
	
	system("pause");
	return 0;
}
