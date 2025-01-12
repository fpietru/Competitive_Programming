#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 2e5+5;
vector<int> G[MxN];
bool vis[MxN];
bool flag;

void dfs(int v, int target, int forb)
{
	vis[v] = 1;
	for (auto u : G[v])
		if (!vis[u] && u != forb)
		{
			if (u == target)
				flag = 1;
			dfs(u, target, forb);
		}
}  

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i=1; i<=m; i++)
	{
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int q; cin >> q;
	while (q--)
	{
		int a, b, c; cin >> a >> b >> c;
		memset(vis, 0, sizeof(vis));
		flag = 0;
		dfs(a, b, c);
		cout << (flag ? "TAK\n" : "NIE\n");
	}

    return 0;
}
