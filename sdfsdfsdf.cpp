#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("message.in", "r", stdin);
    freopen("message.out", "w", stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	map<string, int>ma;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int m;
		cin >> m;
		bool flag = 0;
		for (int j = 1; j <= m; j++)
		{
			string x;
			cin >> x;
			for (int it = 2; it <= x.length(); it++)
			{
				if (x[it] == 'e' && x[it - 1] == 'i' && x[it - 2] == 'b' && ma.find(x) == ma.end())
				{
					ma[x] = 1;
					cout << x << endl;
					flag = 1;
				}
			}
		}
		if (!flag)
		{
			cout << "Genshin Impact, start!" << endl;
		}
	}
	return 0;
}