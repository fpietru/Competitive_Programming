/*
	Zadanie "Komiwojażer Bajtazar" z IX OI, etap I
*/
#include <bits/stdc++.h>
using namespace std;

const int MxN = 3e4+4, LOG = 15;
int up[MxN][LOG], lvl[MxN];
vector<int> G[MxN];

void dfs(int v, int p)
{
	lvl[v] = lvl[p] + 1;
	up[v][0] = p;

	for (auto u : G[v])
		if (u != p)
			dfs(u, v);
}

int lca(int a, int b)
{
	if (lvl[a] < lvl[b])
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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, q, a, b, ans = 0;

	cin >> n;
	for (int i=1; i<=n-1; i++)
	{
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	for (int i=1; i<=n; i++)
		if (up[i][0] == 0)
			dfs(i, i);

	for (int k=1; k<LOG; k++)
		for (int x=1; x<=n; x++)
			up[x][k] = up[up[x][k-1]][k-1];

	a = 1;
	cin >> q;
	while (q--)
	{
		cin >> b;
		ans += lvl[a] + lvl[b] - 2 * lvl[lca(a, b)];
		a = b;
	}

	cout << ans << "\n";

	return 0;
}