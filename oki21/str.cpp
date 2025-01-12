/*
	Zadanie "Strajki" z XXIV OI, etap II
*/
#include <bits/stdc++.h>
using namespace std;

const int MxN = 5e5+55;
vector<int> G[MxN]; // lista sąsiedztwa
int parent[MxN]; // lista ojców wierzchołków
int act_children[MxN]; // lista aktywnych dzieci wierzchołków
bool act[MxN]; // czy wierzchołek jest aktywyny

void dfs(int v, int p)
{
	parent[v] = p;
	for (int u : G[v])
		if (u != p)
		{
			act_children[v]++;
			dfs(u, v);
		}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// Wczywywanie drzewa
	int n; cin >> n;
	for (int i=1; i<=n-1; i++)
	{
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	// Aby zaznaczyć ojców i liczbę aktywnych dzieci dla każdego wierzchołka, może być też BFS
	dfs(1, 0);

	// Na początku wszystkie wierzchołki są aktywne = nie strajkują
	for (int i=1; i<=n; i++)
		act[i] = 1;

	int ans = 1; // odpowiedź
	int m; cin >> m;
	while (m--)
	{
		int x; cin >> x;
		int v = abs(x); // wierzchołek w drzewie

		if (x > 0) // jakieś miasto zaczyna strajkować
		{
			act[v] = 0; // ten wierzchołek nie jest już aktywny
			act_children[parent[v]]--; // zmniejsz liczbę aktywnych dzieci dla jego ojca
			ans += act_children[v] + act[parent[v]] - 1; // korzeń ma ojca 0, który zawsze jest nieaktywny więc nie zmienia wyniku
		}
		else // jakieś miasto przestaje strajkować
		{
			act[v] = 1; // zaznacz je jako aktywne na nowo
			act_children[parent[v]]++; // powiększ liczbę aktywnych dzieci dla jego ojca
			ans -= act_children[v] + act[parent[v]] - 1;
		}

		cout << ans << "\n"; // wypisz odpowiedź
	}

	return 0;
}