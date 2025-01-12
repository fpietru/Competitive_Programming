/*
	Zadanie "Max odległości" z OKI
*/
#include <bits/stdc++.h>
using namespace std;
#define FR first
#define SD second

const int MxN = 5e5+5, LOG = 19;
int up[MxN][LOG], mx[MxN][LOG];
int lvl[MxN];
vector<pair<int, int>> G[MxN];

void dfs(int v, int p)
{
	lvl[v] = lvl[p] + 1;
	up[v][0] = p;

	for (auto u : G[v])
		if (u.FR != p)
		{
			mx[u.FR][0] = u.SD; 
			dfs(u.FR, v);
		}
}

int lca(int a, int b)
{
	if (a == b)
		return 0;

	if (lvl[a] < lvl[b])
		swap(a, b);

	int mxedge = -1e9-9;

	for (int i=LOG-1; i>=0; i--)
		if (lvl[a] - (1<<i) >= lvl[b])
		{
			mxedge = max(mxedge, mx[a][i]);
			a = up[a][i];
		}

	while (a != b)
	{
		int l = log2(lvl[a]);

		while (l > 0 && up[a][l] == up[b][l])
			l--;

		mxedge = max({mxedge, mx[a][l], mx[b][l]});
		a = up[a][l];
		b = up[b][l];
	}

	return mxedge;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, a, b, c;

	cin >> n;
	for (int i=1; i<=n-1; i++)
	{
		cin >> a >> b >> c;
		G[a].push_back({b, c});
		G[b].push_back({a, c});
	}

	for (int i=1; i<=n; i++)
		if (up[i][0] == 0)
			dfs(i, i);

	for (int k=1; k<LOG; k++)
		for (int x=1; x<=n; x++)
		{
			up[x][k] = up[up[x][k-1]][k-1];
			mx[x][k] = max(mx[x][k-1], mx[up[x][k-1]][k-1]);
		}

	while (true)
	{
		cin >> a >> b;
		if (a == -1)
			break;

		cout << lca(a, b) << "\n";
	}
	
	return 0;
}