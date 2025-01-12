/*
	Hashowanie Drzew (Izomorfizm)
	Sprawdzenie poprawności: https://www.spoj.com/problems/TREEISO/
*/
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second // debugging /*
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
	cout << "[ " << vars << " = "; string delim = "";
	(..., (cout << delim << values, delim = ", "));
	cout << " ]\n";
}
/**/

constexpr int MxN = 1e5+5;
vector<int> G[2][MxN];
vector<int> centry[2];
map<vector<int>, int> mp;
int vis[MxN]; // żeby nie memsetować, to vis jest intem a gtime oznacza moment chodzenia po drzewie
int rozmiar[2][MxN];
int gtime, etykieta = 1;
int n;

// mapa służy do hashowania wektorów (wektory przechowują rozmiary poddrzew sąsiadów dla każdego wierzchołka w drzewie)
int zhaszuj(vector<int> &V)
{
	if (int hash = mp[V]; hash == 0)
		return mp[V] = ++etykieta;
	else return hash;
}
// wyznaczanie rozmiarów poddrzew
void dfs1(int v, int graf)
{
	vis[v] = gtime;
	rozmiar[graf][v] = 1;
	for (auto u : G[graf][v])
		if (vis[u] != gtime)
		{
			dfs1(u, graf);
			rozmiar[graf][v] += rozmiar[graf][u];
		}
}
// hashowanie drzewa
int dfs2(int v, int graf)
{
	vis[v] = gtime;
	vector<int> V;
	for (auto u : G[graf][v])
		if (vis[u] != gtime)
			V.push_back(dfs2(u, graf));
	sort(V.begin(), V.end());
	return zhaszuj(V);
}
// czy wierzchołek v jest centroidem
bool centroid(int v, int graf)
{
	int najw = n - rozmiar[graf][v];
	for (auto u : G[graf][v])
		if (rozmiar[graf][u] < rozmiar[graf][v])
			najw = max(najw, rozmiar[graf][u]);
	return 2*najw <= n;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i=1; i<=n-1; i++)
		{
			int a, b; cin >> a >> b;
			G[0][a].push_back(b);
			G[0][b].push_back(a);
		}
		for (int i=1; i<=n-1; i++)
		{
			int a, b; cin >> a >> b;
			G[1][a].push_back(b);
			G[1][b].push_back(a);
		}
		gtime++, dfs1(1, 0);
		gtime++, dfs1(1, 1);
		for (int i=0; i<2; i++)
			for (int v=1; v<=n; v++)
				if (centroid(v, i))
					centry[i].push_back(v);
		gtime++; int H1 = dfs2(centry[0][0], 0);
		gtime++; int H2 = dfs2(centry[1][0], 1);
		gtime++; int H3 = dfs2(centry[1].back(), 1);
		if (H1 == H2 || H1 == H3) cout << "YES\n";
		else cout << "NO\n";
	
		// czyszczenie na kolejny test_case
		gtime = 0;
		etykieta = 1;
		mp.clear();
		centry[0].clear();
		centry[1].clear();
		for (int v=1; v<=n; v++)
		{
			vis[v] = 0;
			rozmiar[0][v] = rozmiar[1][v] = 0;
			G[0][v].clear();
			G[1][v].clear();
		}
	}

	return 0;
}
