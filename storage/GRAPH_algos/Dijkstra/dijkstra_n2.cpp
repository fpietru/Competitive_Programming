/*
	Dijkstra w czasie O(n^2 + m), jest dobra tylko dla grafów gęstych
	Inspiracja: https://cp-algorithms.com/graph/dijkstra.html
	Zadanie do sprawdzenia poprawności: https://pl.spoj.com/problems/DIJKSTRA
*/
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define FR first
#define SD second

constexpr int MxN = 1e4+4;
constexpr int INF = 1e9+7;
vector<pii> G[MxN];
int d[MxN];
bool vis[MxN];
int n, m;

void dijkstra(int st)
{
	// resetowanie tablic
	for (int i=0; i<=n; i++)
	{
		d[i] = INF;
		vis[i] = 0;
	}
	
	d[st] = 0;
	for (int i=1; i<=n; i++)
	{
		// znaleźć wierzchołek z najmniejszym d
		int v = -1;
		for (int j=0; j<=n; j++)
			if (!vis[j] && (v == -1 || d[j] < d[v]))
				v = j;
		
		// skoro min d równa się INF, to nic nie uda się polepszyć, więc można przerwać
		if (d[v] == INF)
			break;
		
		// zaznaczyć v jako odwiedzony
		vis[v] = 1;
		
		// relaksacje na krawędziach od v
		for (auto e : G[v])
			d[e.FR] = min(d[e.FR], d[v] + e.SD);
	}
}

void solve()
{
	cin >> n >> m;
	for (int i=1; i<=m; i++)
	{
		int a, b, w; cin >> a >> b >> w;
		G[a].push_back({b, w});
	}
	
	int st, ed; cin >> st >> ed;
	
	dijkstra(st);
	
	if (d[ed] == INF)
		cout << "NIE\n";
	else
		cout << d[ed] << "\n";;

	for (int i=0; i<=n; i++)
		G[i].clear();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
		solve();
	
	return 0;
}

