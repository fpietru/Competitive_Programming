#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e3+13;
vector<int> G[MxN];
bool vis[MxN];

bool dfs(int v, int p)
{
	vis[v] = 1;
	for (int u : G[v])
	{
		if (!vis[u])
			dfs(u, v);
		else if (u != p)
			return 1;
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i=1; i<=m; i++)
	{
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	bool ans = 0;
	for (int i=1; i<=n; i++)
	{
		if (dfs(i, i))
		{
			ans = 1;
			break;
		}
		memset(vis, 0, sizeof(vis));
	}

	cout << (ans ? "TAK\n" : "NIE\n");
	
	return 0;
}