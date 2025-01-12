#include <bits/stdc++.h>
using namespace std;
#define FR first
#define SD second

const int MxN = 1e5+5, LOG = 17;
int up[MxN][LOG], mx[MxN][LOG], mi[MxN][LOG];
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
			mi[u.FR][0] = u.SD;
			dfs(u.FR, v); 
		}
}

pair<int, int> lca(int a, int b)
{
	if (lvl[a] < lvl[b])
		swap(a, b);

	int MAX = -1e9, MIN = 1e9;

	for (int i=LOG-1; i>=0; i--)
		if (lvl[a] - (1<<i) >= lvl[b])
		{
			MAX = max(MAX, mx[a][i]);
			MIN = min(MIN, mi[a][i]);
			a = up[a][i];
		}

	while (a != b)
	{
		int l = 32 - __builtin_clz(lvl[a]) - 1;

		while (l > 0 && up[a][l] == up[b][l])
			l--;

		MAX = max({MAX, mx[a][l], mx[b][l]});
		MIN = min({MIN, mi[a][l], mi[b][l]});
		a = up[a][l];
		b = up[b][l];
	}
		
	return {MIN, MAX};
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, q, a, b, c;

	cin >> n;
	for (int i=1; i<=n-1; i++)
	{
		cin >> a >> b >> c;
		G[a].push_back({b, c});
		G[b].push_back({a, c});
	}

	for (int i=1; i<=n; i++)
		for (int j=0; j<LOG; j++)
		{
			mx[i][j] = -1e9;
			mi[i][j] = 1e9;
		}

	for (int i=1; i<=n; i++)
		if (up[i][0] == 0)
			dfs(i, i);

	for (int k=1; k<LOG; k++)
		for (int x=1; x<=n; x++)
		{
			up[x][k] = up[up[x][k-1]][k-1];
			mx[x][k] = max(mx[x][k-1], mx[up[x][k-1]][k-1]);
			mi[x][k] = min(mi[x][k-1], mi[up[x][k-1]][k-1]);
		}

	// for (int i=1; i<=n; i++)
	// {
	// 	cout << i << ":\n";
	// 	for (int j=0; j<LOG; j++)
	// 		cout << "2^" << i << ": Ancestor = " << up[i][j] << " Max = " << mx[i][j] << " Min = " << mi[i][j] << "\n";
	// 	cout << "\n";
	// }

	cin >> q;
	while (q--)
	{
		cin >> a >> b;
		pair<int, int> ans = lca(a, b);
		cout << ans.FR << " " << ans.SD << "\n";
	}

	return 0;
}