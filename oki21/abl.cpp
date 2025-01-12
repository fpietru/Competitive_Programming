/*
	Zadanie "E. A and B and Lecture Rooms" z CF Div.2
*/
#include <bits/stdc++.h>
using namespace std;

const int MxN = 1e5+5, LOG = 17;
int up[MxN][LOG], subtreeS[MxN], lvl[MxN];
vector<int> G[MxN];

void dfs(int v, int p)
{
	lvl[v] = lvl[p] + 1;
	up[v][0] = p;
	subtreeS[v] = 1;

	for (auto u : G[v])
		if (u != p)
		{
			dfs(u, v);
			subtreeS[v] += subtreeS[u];
		}
}

int lca(int a, int b)
{
	if (lvl[a] < lvl[b])
		swap(a, b);

	for (int i=0; i<LOG; i++)
		if ((lvl[a]-lvl[b]) & (1<<i))
			a = up[a][i];

	while (a != b)
	{
		int log = 32 - __builtin_clz(lvl[a]) - 1;

		while (log > 0 && up[a][log] == up[b][log])
			log--;

		a = up[a][log];
		b = up[b][log];
	}

	return a;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, q, a, b;

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

	for (int i=1; i<LOG; i++)
		for (int j=1; j<=n; j++)
			up[j][i] = up[up[j][i-1]][i-1];

	cin >> q;
	while (q--)
	{
		cin >> a >> b;

		if (a == b)
		{
			cout << n << "\n";
			continue;
		}

		if (lvl[a] < lvl[b])
			swap(a, b);

		int l = lca(a, b);
		int d1 = lvl[a] - lvl[l];
		int d2 = lvl[b] - lvl[l];

		if (d1 != d2)
		{
			if ((d1 + d2) & 1)
			{
				cout << "0\n";
				continue;
			}

			int mid = (d1 + d2) / 2;
			int k1 = a, k2 = a;

			for (int i=0; i<LOG; i++)
				if (mid & (1<<i))
					k1 = up[k1][i];

			mid--;

			for (int i=0; i<LOG; i++)
				if (mid & (1<<i))
					k2 = up[k2][i];

			cout << subtreeS[k1] - subtreeS[k2] << "\n";
		}
		else
		{
			d1--;
			for (int i=0; i<LOG; i++)
				if (d1 & (1<<i))
				{
					a = up[a][i];
					b = up[b][i];
				}
			
			cout << n - subtreeS[a] - subtreeS[b] << "\n";
		}
	} 

	return 0;
}