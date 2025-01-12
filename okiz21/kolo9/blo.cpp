/*
	Zadanie "Blokada" z XV OI, etap II, dzień próbny
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MxN = 1e5+55;
vector<int> G[MxN];
int pre[MxN], low[MxN];
bool vis[MxN];
int gtime=0, n, m;
ll ans[MxN];

int dfs(int v, int p)
{
	vis[v] = 1;
	int blocked = 0, visited = 1;
	pre[v] = low[v] = ++gtime;
	ans[v] = 2*(n-1);

	for (int u : G[v])
	{
		if (!vis[u])
		{
			// rozmiar poddrzewa o korzeniu u
			int sz = dfs(u, v);
			visited += sz;

			// v jest punktem artykulacyjnym
			if (low[u] >= pre[v])
			{
				ans[v] += (ll)(n-sz-1)*sz;
				blocked += sz;
			}
			else // dla krawędzi drzewa DFS
				low[v] = min(low[v], low[u]);
		}
		else if (u != p) // dla krawędzi powrotnej
			low[v] = min(low[v], pre[u]);
	}

	ans[v] += (ll)(n-blocked-1)*blocked;
	return visited;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i=1; i<=m; i++)
	{
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	dfs(1, -1);

	for (int i=1; i<=n; i++)
		cout << ans[i] << "\n";

	return 0;
}
