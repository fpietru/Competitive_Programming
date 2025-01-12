/*
	https://www.spoj.com/problems/LCA/
*/
#include <bits/stdc++.h>
using namespace std;

const int MxN = 1e3+3, LOG = 12;
int up[MxN][LOG], lvl[MxN], dad[MxN];
vector<int> G[MxN];

void dfs(int v, int p)
{
	lvl[v] = lvl[p] + 1;
	dad[v] = p;

	for (auto u : G[v])
		if (u != p)
			dfs(u, v);
}

int lca(int a, int b)
{
	if (lvl[a] <= lvl[b])
		swap(a, b);

	for (int i=LOG-1; i>=0; i--)
		if (lvl[a] - (1<<i) >= lvl[b])
			a = up[a][i];

	if (a == b)
		return a;

	for (int i=LOG-1; i>=0; i--)
		if (up[a][i] != up[b][i])
		{
			a = up[a][i];
			b = up[b][i];
		}

	return up[a][0];
}

void solve_case(int testcase)
{
	int n; cin >> n;
	for (int a=1; a<=n; a++)
	{
		int m; cin >> m;
		for (int i=1; i<=m; i++)
		{
			int b; cin >> b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
	}

	dfs(1, 1);

	for (int i=1; i<=n; i++)
		up[i][0] = dad[i];

	for (int k=1; k<LOG; k++)
		for (int x=1; x<=n; x++)
			up[x][k] = up[up[x][k-1]][k-1];

	int q; cin >> q;
	cout << "Case " << testcase << ":\n";
	while (q--)
	{
		int a; int b;
		cin >> a >> b;
		cout << lca(a, b) << "\n";
	}

	for (int i=0; i<=n; i++)
		G[i].clear();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	for (int i=1; i<=t; i++)
		solve_case(i);
	
	return 0;
}
