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
int lvl[MxN], jump[MxN][LOG+1];
vector<int> G[MxN];

void dfs(int v, int p) {
	lvl[v] = lvl[p] + 1;
	jump[v][0] = p;
	for (auto u : G[v])
		if (u != p) dfs(u, v);
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

int kty(int v, int k) {
	for (int i=LOG; i>=0; i--)
		if (k&(1<<i))
			v = jump[v][i];
	return v;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, q; cin >> n >> q;
	for (int i=1; i<=n-1; i++) {
		int a, b; cin >> a >> b;
		G[a].PB(b); G[b].PB(a);
	}
	dfs(1, 1);
	for (int k=1; k<=LOG; k++)
		for (int i=1; i<=n; i++)
			jump[i][k] = jump[jump[i][k-1]][k-1];

	while (q--) {
		int a, b; cin >> a >> b;
		if (lvl[a] < lvl[b]) swap(a, b);
		int l = lca(a, b);
		int dl = lvl[a] + lvl[b] - 2*lvl[l];
		if (dl&1) cout << "NIE\n";
		else cout << kty(a, (dl>>1)) << "\n";
	}

	return 0;
}
