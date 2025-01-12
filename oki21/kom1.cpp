/*
	Zadanie "Telekomunikacja Bajtocka" z KI
*/
#include <bits/stdc++.h>
using namespace std;

const int MxN = 1e5+55, LOG = 17;
int lvl[MxN], up[MxN][LOG];
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
	
	int n, q, a, b, c;

	cin >> n;
	for (int i=1; i<n; i++)
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

	cin >> q;
	while (q--)
	{
		cin >> a >> b >> c;

		int AB = lca(a, b);
		int CA = lca(c, a);
		int CB = lca(c, b);

		bool f1 = (AB == c);
		bool f2 = (CA == c && CB == AB);
		bool f3 = (CB == c && CA == AB);
		bool ans = (f1 || f2 || f3);
		cout << (ans ? "TAK\n" : "NIE\n");
	}

	return 0;
}
