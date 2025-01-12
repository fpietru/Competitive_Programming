#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second
#define PB push_back
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__) // debugging /*
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename ...Args> void logger(string vars, Args&&... values) { cout<<"[ "<<vars<<" = "; string delim=""; (..., (cout<<delim<<values, delim=", ")); cout <<" ]\n"; }
/**/

constexpr int MxN = 1e5+5;
vector<int> G[MxN];
ll dp[MxN], dp2[MxN];
/*
	dp[v] = wynik dla poddrzewa v
	dp2[v] = jeśli pozbędę się całego poddrzewa v, to na ile sposobów mogę
	pokolorować drzewo, tak aby albo całe było białe, albo ojciec v należał do czarnej spójnej
	wynik = (dp[v]-1) * dp2[v],
	-1 bo v musi być czarny, więc odjąć opcje, gdzie całe poddrzewo v jest białe
*/
ll pref[MxN], suff[MxN];
ll MOD;

inline ll mult(ll a, ll b) {
	return (a * b) % MOD;
}

inline ll dodaj(ll a, ll b) {
	return (a + b) % MOD;
}

inline ll odejm(ll a, ll b) {
	return (a - b + MOD) % MOD;
}

void dfs(int v, int p) {
	ll ilo = 1;
	bool lisc = true;
	for (auto u : G[v])
		if (u != p) {
			lisc = false;
			dfs(u, v);
			ilo = mult(ilo, dp[u]);
		}
	if (lisc) dp[v] = (MOD == 2 ? 0 : 2);
	else dp[v] = dodaj(1, ilo);
}

void dfs2(int v, int p) {
	vector<int> dzieci;
	for (auto u : G[v])
		if (u != p)
			dzieci.PB(u);
			
	int m = dzieci.size();
	if (m == 0) return;
	for (int i=0; i<m; i++) {
		int u = dzieci[i];
		if (i == 0) pref[i] = dp[u];
		else pref[i] = mult(pref[i-1], dp[u]);
	}
	for (int i=m-1; i>=0; i--) {
		int u = dzieci[i];
		if (i == m-1) suff[i] = dp[u];
		else suff[i] = mult(suff[i+1], dp[u]);
	}
	
	for (int i=0; i<m; i++) {
		int u = dzieci[i];
		ll ilo = 1;
		if (i > 0) ilo = mult(ilo, pref[i-1]);
		if (i < m-1) ilo = mult(ilo, suff[i+1]);
		dp2[u] = dodaj(1, mult(dp2[v], ilo));
	}
	for (auto u : dzieci)
		dfs2(u, v);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; cin >> MOD;
	for (int i=1; i<=n-1; i++) {
		int a, b; cin >> a >> b;
		G[a].PB(b); G[b].PB(a);
	}
	
	dfs(1, 1);
	dp2[1] = 1;
	dfs2(1, 1);
	
	for (int i=1; i<=n; i++) {
		ll ans = mult(odejm(dp[i],1), dp2[i]);
		cout << ans << "\n";
	}

	return 0;
}
