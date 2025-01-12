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

struct info {
	int v;
	int p;
	int d;
};
struct node { int p, s; };
constexpr int MxN = 4e5+5;
constexpr int LOG = 19;
vector<int> G[MxN];
int laczniki;
int jump[MxN][LOG+1];
int lvl[MxN];
node nodes[MxN];
int K;

void dfs(int v, int p) {
	jump[v][0] = p;
	lvl[v] = lvl[p] + 1;
	for (auto u : G[v])
		if (u != p) dfs(u, v);
}

int kty(int v, int k) {
	for (int i=LOG; i>=0; i--)
		if (k&(1<<i)) v = jump[v][i];
	return v;
}

int lca(int a, int b) {
	if (lvl[a] < lvl[b]) swap(a, b);
	for (int i=LOG; i>=0; i--)
		if (lvl[a]-(1<<i) >= lvl[b])
			a = jump[a][i];
	if (a == b) return a;
	for (int i=LOG; i>=0; i--)
		if (jump[a][i] != jump[b][i]) {
			a = jump[a][i];
			b = jump[b][i];
		}
	return jump[a][0];
}

void init(int v) {
	nodes[v].p = v;
	nodes[v].s = 1;
}

int getL(int v) {
	if (nodes[v].p == v)
		return v;
	return nodes[v].p = getL(nodes[v].p);
}

void join(int a, int b) {
	a = getL(a);
	b = getL(b);
	if (a == b) return;
	if (nodes[a].s < nodes[b].s) swap(a, b);
	nodes[a].s += nodes[b].s;
	nodes[b].p = a;
}

bool check(int a, int b) {
	if (lvl[a] < lvl[b]) swap(a, b);
	int l = lca(a, b);
	int al = lvl[a] - lvl[l];
	int bl = lvl[b] - lvl[l];
	
	// deb(a, b, l, al, bl, getL(a), getL(b));
	if (bl < K) b = kty(a, al-(K-bl));
	else b = kty(b, K);
	a = kty(a, K);
	
	return (getL(a) == getL(b) || (al + bl <= 2*K));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, p; cin >> n >> K >> p;
	for (int i=1; i<=n-1; i++) {
		int a, b; cin >> a >> b;
		laczniki++;
		G[a].PB(laczniki+n);
		G[laczniki+n].PB(a);
		G[b].PB(laczniki+n);
		G[laczniki+n].PB(b);
	}
	n += laczniki;
	
	dfs(1, 1);
	
	for (int k=1; k<=LOG; k++)
		for (int i=1; i<=n; i++)
			jump[i][k] = jump[jump[i][k-1]][k-1];
	
	for (int i=1; i<=n; i++)
		init(i);
	
	queue<info> Q;
	for (int i=1; i<=p; i++) {
		int x; cin >> x;
		Q.push({x, x, K});
	}
	while (!Q.empty()) {
		info pakiet = Q.front();
		Q.pop();
		for (auto u : G[pakiet.v])
			if (u != pakiet.p && pakiet.d > 0) {
				join(u, pakiet.v);
				Q.push({u, pakiet.v, pakiet.d-1});	
			}
	}
	
	int q; cin >> q;
	while (q--) {
		int a, b; cin >> a >> b;
		cout << (check(a, b) ? "TAK\n" : "NIE\n");
	}


	return 0;
}
