/*
	Zadanie "Komiwojażer Bajtazar" z IX OI, etap I
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 3e4+4;
constexpr int MxQ = 5e3+3;
vector<int> G[MxN];
int jump[MxN][16];
int depth[MxN];

void dfs(int v, int p)
{
	depth[v] = depth[p] + 1;
	jump[v][0] = p;
	
	for (auto u : G[v])
		if (u != p)
			dfs(u, v);
}

int LCA(int a, int b)
{
	if (depth[a] < depth[b])
		swap(a, b);
	
	int r = depth[a] - depth[b];
	for (int i=15; i>=0; i--)
		if (r&(1<<i))
			a = jump[a][i];
	
	if (a == b)
		return a;
	
	for (int i=15; i>=0; i--)
		if (jump[a][i] != jump[b][i])
		{
			a = jump[a][i];
			b = jump[b][i];
		}
	
	return jump[a][0];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n-1; i++)
	{
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	dfs(1, 1);
	
	// zapamiętać: na początku potęgi, potem kolejne wierzchołki
	for (int j=1; j<=15; j++)
		for (int i=1; i<=n; i++)
			jump[i][j] = jump[jump[i][j-1]][j-1]; 
	
	int a = 1;
	int ans = 0;
	int q; cin >> q;
	while (q--)
	{
		int b; cin >> b;
		ans += depth[a] + depth[b] - 2*depth[LCA(a, b)];
		a = b;
	}
	cout << ans << "\n";
	
	return 0;
}
