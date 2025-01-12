/*
	DFS bez tablicy odwiedzonych
	(tylko dla drzew)
*/
#include <bits/stdc++.h>
using namespace std;
constexpr int MxN = 1e6+66;
vector<int> G[MxN]; // lista sąsiedztwa

void dfs(int v, int p) // v = obecny wierzchołek, p = ojciec v
{
	cout << v << "\n"; // coś tu robić
	for (int u : G[v])
		if (u != p)
			dfs(u, v);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	dfs(1, 0); // 1 jest korzeniem

	return 0;
}