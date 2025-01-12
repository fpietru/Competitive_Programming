/*
	HLD:
	1) zmień wartość w wierzchołku
	2) podaj max na ścieżce
	
	Sprawdzenie Poprawności: https://cses.fi/problemset/task/2134
	UWAGA!: LCA jest liczone dwa razy (dla max nie robi różnicy bo idempotentność)
*/
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ld = long double;
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

constexpr int MxN = 2e5+5;
constexpr int L = 18; 
constexpr int base = (1<<L);
vector<int> G[MxN];
ll Tree[2*base];
int rozmiar[MxN];
int lvl[MxN];
int jump[MxN][L+1];
int heavy_child[MxN];
int etykieta[MxN];
int antyetykieta[MxN];
int szczyt[MxN];
int wart[MxN];
int licznik = 0;

void updateTree(int v, int x)
{
	v += base;
	Tree[v] = (ll)x;
	while (v)
	{
		v /= 2;
		Tree[v] = max(Tree[2*v], Tree[2*v+1]);
	}
}

ll queryTree(int a, int b)
{
	ll res = 0LL;
	a += base - 1;
	b += base + 1;
	while (a/2 != b/2)
	{
		if (a % 2 == 0) res = max(res, Tree[a+1]);
		if (b % 2 != 0) res = max(res, Tree[b-1]);
		a /= 2, b /= 2;
	}
	return res;
}

int lca(int a, int b)
{
	if (lvl[a] < lvl[b]) swap(a, b);
	for (int i=L; i>=0; i--)
		if (lvl[a]-(1<<i) >= lvl[b])
			a = jump[a][i];
	if (a == b) return a;
	for (int i=L; i>=0; i--)
		if (jump[a][i] != jump[b][i])
			a = jump[a][i], b = jump[b][i];
	return jump[a][0];
}

void dfs(int v, int p)
{
	rozmiar[v] = 1;
	lvl[v] = lvl[p] + 1;
	jump[v][0] = p;
	for (auto u : G[v])
		if (u != p)
		{
			dfs(u, v);
			rozmiar[v] += rozmiar[u];
		}
	int mx_rozmiar = 0;
	for (auto u : G[v])
		if (u != p && rozmiar[u] > mx_rozmiar)
		{
			heavy_child[v] = u;
			mx_rozmiar = rozmiar[u];
		}
}

void dfs2(int v, int p, bool jestesheavy = 1)
{
	etykieta[v] = ++licznik;
	antyetykieta[licznik] = v;
	if (jestesheavy == 1) szczyt[v] = szczyt[p];
	else                  szczyt[v] = etykieta[v];
	if (heavy_child[v] != 0)
		dfs2(heavy_child[v], v, 1);
	for (auto u : G[v])
		if (u != p && u != heavy_child[v])
			dfs2(u, v, 0);
}

void nodeupdate(int v, int x)
{
	updateTree(etykieta[v], x);
}

ll pathquery(int v, int r)
{
	ll res = 0LL;
	while (true)
	{
		int nowe_v = v;
		int ev = etykieta[v];
		int er = etykieta[r];
		
		if (ev == szczyt[v]) // light syn
		{
			nowe_v = jump[v][0];
			res = max(res, queryTree(ev, ev));
		}
		else // heavy syn
		{
			if (szczyt[v] >= er) // można skakać całą heavy ścieżkę
				nowe_v = antyetykieta[szczyt[v]];
			else // er należy do heavy ścieżki
				for (int i=L; i>=0; i--)
					if (etykieta[jump[nowe_v][i]] >= er)
						nowe_v = jump[nowe_v][i];		
		
			res = max(res, queryTree(etykieta[nowe_v], ev));
		} 
		
		v = nowe_v;
		if (ev == er)
			break;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, q; cin >> n >> q;
	for (int i=1; i<=n; i++)
		cin >> wart[i];
	for (int i=1; i<=n-1; i++)
	{
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(1, 1);
	for (int k=1; k<=L; k++)
		for (int v=1; v<=n; v++)
			jump[v][k] = jump[jump[v][k-1]][k-1];

	szczyt[1] = 1;
	dfs2(1, 1);
	
	for (int v=1; v<=n; v++)
		updateTree(etykieta[v], wart[v]);
		
	while (q--)
	{
		int op, a, b; cin >> op >> a >> b;
		if (op == 1) nodeupdate(a, b);
		else
		{
			if (lvl[a] < lvl[b]) swap(a, b);
			int l = lca(a, b);
			ll ans = 0LL;
			if (b == l) ans = pathquery(a, b);
			else	    ans = max(pathquery(a, l), pathquery(b, l));
			cout << ans << " ";
		}
	}
	cout << "\n";
	
	return 0;
}
