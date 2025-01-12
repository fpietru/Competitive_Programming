/*
	Znajdowanie punktów artykulacji w grafie
	Funkcja LOW
*/
#include <bits/stdc++.h>
using namespace std;

const int MxN = 1e4+44;
vector<int> G[MxN];
int pre[MxN];
int low[MxN];
bool vis[MxN], cutpoint[MxN];
int gtime;

void dfs(int v, int p = -1)
{
	vis[v] = 1;
	int children = 0;
	pre[v] = low[v] = ++gtime;

	for (int u : G[v])
	{
		if (u == p)
			continue;
		if (!vis[u])
		{
			children++;
			dfs(u, v);

			low[v] = min(low[v], low[u]);

			if ((p == -1 && children >= 2) || (p != -1 && low[u] >= pre[v]))
				cutpoint[v] = 1;
		}
		else if (u != p)
			low[v] = min(low[v], pre[u]);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, m; 
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
			break;

		for (int i=1; i<=m; i++)
		{
			int a, b; cin >> a >> b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		
		for (int i=1; i<=n; i++)
		{
			low[i] = 1e9+7;
			vis[i] = 0;
			cutpoint[i] = 0;
		}

		gtime = 0;

		dfs(1);

		int ans = 0;
		for (int i=1; i<=n; i++)
		{
			if (cutpoint[i]) ans++;
			G[i].clear();
		}

		cout << ans << "\n";
	}

	return 0;
}
