/*
	Zadanie: "Zboże", XXX OI, etap I
	Autor: Franciszek Pietrusiak
*/
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
constexpr int LOG = 18;
vector<pii> G[MxN];
int rozmiar[MxN];
bool usuniete[MxN];
pii st[2*MxN][LOG+1];
int lg[2*MxN];
int tin[MxN];
int par[MxN];
ll depth[MxN];
ll ile[MxN];
ll suma[MxN];
ll uznanie[MxN];
int licznik;

void dfs0(int v, int p, int lvl, ll d) {
	depth[v] = d;
	tin[v] = licznik;
	st[licznik++][0] = {lvl, v};
	for (auto [u, w] : G[v])
		if (u != p) {
			dfs0(u, v, lvl+1, d+w);
			st[licznik++][0] = {lvl, v};
		}
}

ll dist(int a, int b) {
	int ta = tin[a];
	int tb = tin[b];
	if (ta > tb) swap(ta, tb);
	int p = lg[tb-ta+1];
	int lca = min(st[ta][p], st[tb-(1<<p)+1][p]).SD;
	return depth[a] + depth[b] - 2*depth[lca];
}

int dfs(int v, int p=0) {
	rozmiar[v] = 1;
	for (auto [u, w] : G[v])
		if (u != p && !usuniete[u])
			rozmiar[v] += dfs(u, v);
	return rozmiar[v];
}

int find(int v, int sz, int p=0) {
	for (auto [u, w] : G[v])
		if (u != p && !usuniete[u] && 2*rozmiar[u] > sz)
			return find(u, sz, v);
	return v;
}

void centroid(int v, int prev=0) {
	int c = find(v, dfs(v));
	par[c] = prev;
	usuniete[c] = true;
	for (auto [u, w] : G[c])
		if (!usuniete[u]) centroid(u, c);
}

void update(int x) {
	int v = x;
	while (v) {
		ile[v]++;
		suma[v] += dist(v, x);
		uznanie[v] += (par[v] ? dist(par[v], x) : 0LL);
		v = par[v];
	}
}

ll query(int x) {
	int v = x;
	ll res = suma[v];
	while (v) {
		int p = par[v];
		ll A = max(0LL, suma[p] - uznanie[v]);
		ll B = max(0LL, ile[p] - ile[v]);
		res += A + B * dist(x, p);
		v = p;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, q; cin >> n >> q;
	for (int i=1; i<=n-1; i++) {
		int a, b, w; cin >> a >> b >> w;
		G[a].PB({b, w}); G[b].PB({a, w});
	}
	dfs0(1, 1, 1, 0);
	int m = 2*n-1;
	lg[1] = 0;
	for (int i=2; i<=m; i++)
		lg[i] = lg[(i>>1)] + 1;
	for (int k=1; k<=LOG; k++)
		for (int i=0; i+(1<<(k-1))<m; i++)
			st[i][k] = min(st[i][k-1], st[i+(1<<(k-1))][k-1]);
	centroid(1);
	update(1);
	ll ans = 0LL;
	while (q--) {
		int x; cin >> x;
		update(x);
		ans += 2LL*query(x);
		cout << ans << "\n";
	}

	return 0;
}
