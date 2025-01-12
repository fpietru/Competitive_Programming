/*
	Algorytm Prim'a na znajdowanie MST w O(n^2)
	Najlepiej używać do grafów gęstych
	Źródło: https://cp-algorithms.com/graph/mst_prim.html
	Sprawdzić poprawność: https://www.spoj.com/problems/MST/
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define FR first
#define SD second

constexpr int MxN = 1e4+4;
constexpr int INF = 1e9+7;
int G[MxN][MxN];
bool vis[MxN];
int n, m;

/*
	vis = odwiedzone
	mi_edge = minimalna krawędź łącząca wierzchołek należący już do MST i ten z poza niego
	mi_edge[i].FR = waga krawędzi
	mi_edge[i].SD = id wierzchołka do którego jest krawędź
*/

ll Prim()
{
	ll res = 0LL;
	// resetowanie tablic
	memset(vis, 0, sizeof(vis));
	vector<pii> mi_edge(n+1, {INF, -1});
	
	// zaczynamy z wierzchołka 1 (bo tak)
	mi_edge[1].FR = 0;
	
	for (int i=1; i<=n; i++)
	{
		int v = -1;
		for (int j=1; j<=n; j++)
			if (!vis[j] && (v == -1 || mi_edge[j].FR < mi_edge[v].FR))
				v = j;
				
		// jeśli nie ma MST
		if (mi_edge[v].FR == INF)
			return -1;

		// wypisywanie krawędzi należących do MST
		// if (mi_edge[v].SD != -1)
		//	 cout << v << " " << mi_edge[v].SD << "\n";

		vis[v] = 1;
		res += (ll)mi_edge[v].FR;
		
		for (int j=1; j<=n; j++)
			mi_edge[j] = min(mi_edge[j], {G[v][j], v});
	}
	
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;

	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			G[i][j] = INF;
			
	for (int i=1; i<=m; i++)
	{
		int a, b, w; cin >> a >> b >> w;
		G[a][b] = w;
		G[b][a] = w;
	}
	
	cout << Prim() << "\n";

    return 0;
}
