/*
	Zadanie "Mafia" z MPSŚPZ 2021 OPEN
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 5e5+55;
vector<int> G[MxN];
int color[MxN], K;

void dfs(int v, int p)
{
	int c = 1;
	for (int u : G[v])
		if (u != p)
		{
			while (c == color[v] || c == color[p]) c++;
			color[u] = c++;
			dfs(u, v);
		}
}

void solve()
{
	int n; cin >> n;
	for (int i=0; i<n-1; i++)
	{
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	K = 0;
	for (int i=1; i<=n; i++)
		K = max(K, (int)G[i].size());
	K++;

	color[1] = 1;
	dfs(1, 1);

	cout << K << "\n";
	for (int i=1; i<=n; i++)
	{
		cout << color[i] << " ";
		G[i].clear();
		color[i] = 0;
	}
	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--)
		solve();
	
	return 0;
}