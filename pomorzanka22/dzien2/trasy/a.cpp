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
constexpr int LOG = 17;
vector<int> G[MxN];
int lvl[MxN];
int jump[MxN][LOG+1];
int pre[MxN];
int post[MxN];
int low[MxN];
int licznik;
bool vis[MxN];

void dfs(int v, int p) {
	lvl[v] = lvl[p] + 1;
	pre[v] = ++licznik;
	jump[v][0] = p;
	vis[v] = true;
	low[v] = pre[v];
	int dzieci = 0;
	for (auto u : G[v]) {
		if (u == p) continue;
		if (vis[u]) low[v] = min(low[v], pre[u]);
		else {
			dfs(u, v);
			dzieci++;
			low[v] = min(low[v], low[u]);
		}
	}
	post[v] = ++licznik;
}

int lca(int a, int b) {
	if (lvl[a] < lvl[b]) swap(a, b);
	for (int i=LOG; i>=0; i--)
		if (lvl[a] - (1<<i) >= lvl[b])
			a = jump[a][i];
	if (a == b) return a;
	for (int i=LOG; i>=0; i--)
		if (jump[a][i] != jump[b][i]) {
			a = jump[a][i];
			b = jump[b][i];
		}
	return jump[a][0];
}

bool wpoddrzewie(int v, int u) {
	return (pre[v] <= pre[u] && post[u] <= post[v]);
}

bool most(int v, int u) {
	if (lvl[u] < lvl[v]) swap(u, v);
	return (low[u] > pre[v]);
}

bool edge(int k1, int k2, int a, int b) {
	if (lvl[k1] < lvl[k2]) swap(k1, k2);
	if ((wpoddrzewie(k1, a) ^ (wpoddrzewie(k1, b))) && most(k1, k2))
		return false;
	else return true;
}

bool point(int v, int a, int b) {
	if (wpoddrzewie(v, a) && wpoddrzewie(v, b)) {
		int l = lca(a, b);
		int ha = a, hb = b;
		for (int i=LOG; i>=0; i--)
			if (pre[jump[ha][i]] > pre[v])
				ha = jump[ha][i];
		for (int i=LOG; i>=0; i--)
			if (pre[jump[hb][i]] > pre[v])
				hb = jump[hb][i];
		if (v == l && (low[ha] >= pre[v] && low[hb] >= pre[v]))
			return false;
		else return true;
	}
	else if (wpoddrzewie(v, a) && !wpoddrzewie(v, b)) {
		for (int i=LOG; i>=0; i--)
			if (pre[jump[a][i]] > pre[v])
				a = jump[a][i];
		return (low[a] < pre[v]);
	}
	else if (!wpoddrzewie(v, a) && wpoddrzewie(v, b)) {
		for (int i=LOG; i>=0; i--)
			if (pre[jump[b][i]] > pre[v])
				b = jump[b][i];
		return (low[b] < pre[v]);
	}
	else return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int a, b; cin >> a >> b;
		G[a].PB(b); G[b].PB(a);
	}
	
	dfs(1, 1);
	for (int k=1; k<=LOG; k++)
		for (int i=1; i<=n; i++)
			jump[i][k] = jump[jump[i][k-1]][k-1];
	
	int q; cin >> q;
	for (int i=1; i<=q; i++) {
		int op; cin >> op;
		// cout << i << ": ";
		if (op == 1) {
			int a, b, k1, k2; cin >> a >> b >> k1 >> k2;
			cout << (edge(k1, k2, a, b) ? "TAK\n" : "NIE\n");
		}
		else {
			int a, b, v; cin >> a >> b >> v;
			cout << (point(v, a, b) ? "TAK\n" : "NIE\n");
		}
	}

	return 0;
}
