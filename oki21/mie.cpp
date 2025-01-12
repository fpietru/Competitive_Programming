/*
	Zadanie "Miejskie Podchody" z KI

	Dijkstra startującą ze wszystkich wyróżnionych punktów na raz, dla
	każdego wierzchołka przechowuje długość najkrótszej ścieżki oraz jego kolor
	Wynik to min( waga krawędzi + d[początek_krawędzi] + d[koniec_krawędzi] )
	dla krawędzi o różnych kolorach początku i końca.
*/
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using tup = tuple<int, int, int>;
#define FR first
#define SD second

struct edge { int A, B, L; };
const int MxN = 1e5+5, INF = 1e9+9;
int s[MxN], d[MxN], color[MxN];
edge edges[MxN];
bool been[MxN];
vector<pii> G[MxN];
priority_queue<tup, vector<tup>, greater<tup>> qu;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int u, n, m, a, b, c, ans = INF;
	
	cin >> u >> n >> m;
	
	for (int i=1; i<=n; i++)
		d[i] = INF;
	
	for (int i=1; i<=u; i++)
	{
		cin >> s[i];
		if (been[s[i]])
		{
			cout << "0\n";
			return 0;
		}
		been[s[i]] = 1;
		d[s[i]] = 0;
		color[s[i]] = i;
		qu.push({0, s[i], i});
	}

	for (int i=1; i<=m; i++)
	{
		cin >> a >> b >> c;
		G[a].push_back({b,c});
		G[b].push_back({a,c});
		edges[i] = {a, b, c};
	}

	while (!qu.empty())
	{
		int dist, v, c;
		tie(dist, v, c) = qu.top();
		qu.pop();

		if (dist != d[v])
			continue;

		color[v] = c;

		for (auto e : G[v])
		{
			int u = e.FR;
			int w = e.SD;

			if (d[v] + w < d[u])
			{
				d[u] = d[v] + w;
				qu.push({d[u], u, c});
			}
		}
	}

	for (int i=1; i<=m; i++)
		if (color[edges[i].A] != color[edges[i].B])
			ans = min(ans, d[edges[i].A] + d[edges[i].B] + edges[i].L);

	cout << ans * 3 << "\n";

	return 0;
}