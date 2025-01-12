#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 2e5+5;
constexpr int INF = 1e9+7;
vector<int> G[MxN];
int pre[MxN];
int low[MxN];
bool vis[MxN];
bool cutpoint[MxN];
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
		if (vis[u]) low[v] = min(low[v], pre[u]);
		else
		{
			children++;
			dfs(u, v);
			low[v] = min(low[v], low[u]);
			if ((p != -1 && low[u] >= pre[v]) || (p == -1 && children >= 2))
				cutpoint[v] = 1;
		}
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
	
	for (int i=1; i<=n; i++)
		low[i] = INF;
		
	for (int i=1; i<=n; i++)
		if (!vis[i])
			dfs(i);

	for (int i=1; i<=n; i++)
		if (cutpoint[i])
			cout << i << " ";
	cout << "\n";

    return 0;
}
