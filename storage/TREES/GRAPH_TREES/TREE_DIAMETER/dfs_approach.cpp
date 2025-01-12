/*
	Znajdowanie Średnicy Drzewa za pomocą dwóch faz DFS
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 2e5+5;
vector<int> G[MxN];
int n, mxdst = -1, furthest;
/*
	mxdst = maxymalna odległość po między wierzchołkiem startowym dfs, a jakimś wierzchołkiem w drzewie
	furthest = wierzchołek, który jest najdalej położony od wierzchołka startowego dfs
*/

void dfs(int v, int p, int d)
{
	if (mxdst <= d)
	{
		mxdst = d;
		furthest = v;
	}
	
	for (auto u : G[v])
		if (u != p)
			dfs(u, v, d+1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i=0; i<n-1; i++)
	{
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	dfs(1, -1, 0);
	int FRend = furthest;
	mxdst = -1;
	dfs(FRend, -1, 0);
	int SDend = furthest;
	
	cout << mxdst << "\n";
	
	return 0;
}
