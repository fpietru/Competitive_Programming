/*
	Dijkstra z użyciem set'a
	Inspiracja: https://cp-algorithms.com/graph/dijkstra_sparse.html
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
int n, m;

void dijkstra(int st)
{
	for (int i=0; i<=n; i++)
		d[i] = INF;
	
	set<pii, greater<pii>> S;
	
	d[st] = 0;
	S.insert({0, st});
	
	while (!S.empty())
	{
		int v = S.begin()->SD;
		S.erase(S.begin());
		
		for (auto e : G[v])
			if (d[e.FR] > d[v] + e.SD)
			{
				S.erase({d[e.FR], e.FR});
				d[e.FR] = d[v] + e.SD;
				S.insert({d[e.FR], e.FR});
			}
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
