#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second
#define PB push_back
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__) // debugging 
/*
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename ...Args> void logger(string vars, Args&&... values) { cout<<"[ "<<vars<<" = "; string delim=""; (..., (cout<<delim<<values, delim=", ")); cout <<" ]\n"; }
/**/

constexpr int MxN = 5e4+4;
constexpr int L = 19;
constexpr int T = 60;
vector<int> G[MxN];
int jump[MxN][L+1];
ll koszt[MxN];
ll suma[MxN][T];
int order[MxN];
int skok[MxN];
int lvl[MxN];

void dfs(int v, int p)
{
	lvl[v] = lvl[p] + 1;
	jump[v][0] = p;
	for (auto u : G[v])
		if (u != p)
			dfs(u, v);
}

int lca(int a, int b)
{
	if (lvl[a] < lvl[b]) swap(a, b);
	for (int i=L; i>=0; i--)
		if (lvl[a] - (1<<i) >= lvl[b])
			a = jump[a][i];
	if (a == b) return a;
	for (int i=L; i>=0; i--)
		if (jump[a][i] != jump[b][i])
		{
			a = jump[a][i];
			b = jump[b][i];
		}
	return jump[a][0];
}

int kty(int v, int k)
{
	for (int i=L; i>=0; i--)
		if (k & (1<<i)) v = jump[v][i];
	return v;
}

void dfs2(int v, int p)
{
	for (int i=1; i<T; i++)
	{
		int w = kty(v, i);
		suma[v][i] = koszt[v];
		if (w == 1 && lvl[v] - lvl[w] != i) continue;
		else suma[v][i] += suma[w][i];
	}
	for (auto u : G[v])
		if (u != p) dfs2(u, v);
}

ll forbig(int v, int u, int l, int k)
{
	ll res = 0LL;
	if (l == u)
	{
		res += koszt[v];
		while (lvl[v] - k >= lvl[l])
		{
			v = kty(v, k);
			res += koszt[v];
		}
	}
	else
	{
		res += koszt[v];
		while (lvl[v] - k >= lvl[l])
		{
			v = kty(v, k);
			res += koszt[v];
		}
		res += koszt[u];
		while (lvl[u] - k >= lvl[l])
		{
			u = kty(u, k);
			res += koszt[u];
		}
		if (u == v) res -= koszt[l];
	}
	return res;	
}

ll forsmall(int v, int u, int l, int k)
{
	ll res = 0;
	int w = -1;
	for (int i=1; i<T; i++)
		if (((lvl[v] - lvl[kty(l, i)]) % k) == 0)
		{ w = kty(l, i); break; }
	if (w != -1) res += suma[v][k] - suma[w][k];
	else         res += suma[v][k];
	w = -1;
	for (int i=1; i<T; i++)
		if (((lvl[u] - lvl[kty(l, i)]) % k) == 0)
		{ w = kty(l, i); break; }
	if (w != -1) res += suma[u][k] - suma[w][k];
	else         res += suma[u][k];
	if (((lvl[v] - lvl[l]) % k) == 0 && (((lvl[u] - lvl[l]) % k) == 0))
		res -= koszt[l];
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++)
		cin >> koszt[i];
	for (int i=1; i<=n-1; i++)
	{
		int a, b; cin >> a >> b;
		G[a].PB(b); G[b].PB(a);
	}
	for (int i=1; i<=n; i++) cin >> order[i];
	for (int i=1; i<=n-1; i++) cin >> skok[i];
	dfs(1, 1);
	for (int k=1; k<=L; k++)
		for (int i=1; i<=n; i++)
			jump[i][k] = jump[jump[i][k-1]][k-1];
	for (int k=0; k<=L; k++) jump[1][k] = 0;
	dfs2(1, 1);
	for (int i=1; i<=n-1; i++)
	{
		ll ans;
		int v = order[i];
		int u = order[i+1];
		int l = lca(v, u);
		if (lvl[v] < lvl[u]) swap(v, u);
		if (skok[i] >= T) ans = forbig(v, u, l, skok[i]);
		else              ans = forsmall(v, u, l, skok[i]);
		cout << ans << "\n";
	}
	
	return 0;
}
