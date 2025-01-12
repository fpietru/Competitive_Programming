/*
	Time: 39:20.35
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxN = 2e3+33;
vector<int> G[MxN];
bool vis[MxN];
int range[MxN];

void dfs(int v, int o)
{
	vis[v] = 1;
	range[o]++;
	for (int u : G[v])
		if (!vis[u])
			dfs(u, o);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i=0; i<m; i++)
	{
		int a, b; cin >> a >> b;
		G[a].push_back(b);
	}

	ll ans = 0;
	for (int i=1; i<=n; i++)
	{
		dfs(i, i);
		ans += range[i];
		for (int j=1; j<=n; j++)
			vis[j] = 0;
	}

	cout << ans << "\n";
	
	return 0;
}