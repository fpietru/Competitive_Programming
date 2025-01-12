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

constexpr int MxN = 1e5+5;
vector<pii> G[MxN];
ll zmiana[MxN];
ll ory[MxN];
ll ans[MxN];
bool vis[MxN];
bool da_sie = 1;

void dfs(int v, int p)
{
	vis[v] = 1;
	for (auto e : G[v])
		if (!vis[e.FR] && e.FR != p)
			dfs(e.FR, v);

	int krawedz_do_ojca = -1;
	for (auto e : G[v])
		if (e.FR == p)
			krawedz_do_ojca = e.SD;
	
	if (krawedz_do_ojca != -1)
	{
		ans[krawedz_do_ojca] = 2*zmiana[v];
		zmiana[p] -= (ans[krawedz_do_ojca] >> 1);
// 		deb(v, zmiana[v], ans[krawedz_do_ojca]);
	}	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i=1; i<=n; i++)
	{
		cin >> zmiana[i];
		ory[i] = zmiana[i];
	}
	for (int i=1; i<=m; i++)
	{
		int a, b; cin >> a >> b;
		G[a].PB({b, i});
		G[b].PB({a, i});
	}

	dfs(1, 1);
	
	// sprawdzenie
	bool dasie = 1;
	for (int i=1; i<=n; i++)
	{
		ll suma = 0LL;
		for (auto e : G[i])
			suma += ans[e.SD];
		if (suma != 2*ory[i])
			dasie = 0;
	}
	
	if (!dasie) cout << "0\n";
	else
	{
		for (int i=1; i<=m; i++)
			cout << ans[i] << "\n";	
	}

	return 0;
}
