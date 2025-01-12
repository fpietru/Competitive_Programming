/*
	Link: https://www.hackerearth.com/problem/algorithm/make-n00b_land-great-again-circuits/
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
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

constexpr int MxN = 5e5+5;
constexpr int base = (1<<20);
vector<int> G[MxN];
vector<int> posiada[MxN];
vector<int> midpoint[MxN];
int pre[MxN];
int post[MxN];
int lvl[MxN];
int low[MxN];
int high[MxN];
ll potrzebuje[MxN];
struct zap {
	int v;
	ll x, d;
};
zap zapytania[MxN];
pll Tree[2*base];
int licznik;

void Tupdate(int a, int b, ll x, ll d) {
	a += base - 1;
	b += base + 1;
	while ((a>>1) != (b>>1)) {
		if ((a&1) == 0) Tree[a+1] = {Tree[a+1].FR + x, Tree[a+1].SD + d};
		if ((b&1) == 1) Tree[b-1] = {Tree[b-1].FR + x, Tree[b-1].SD + d};
		a >>= 1; b >>= 1;
	}
}

pll Tquery(int v) {
	pll res = {0LL, 0LL};
	v += base;
	while (v) {
		res.FR += Tree[v].FR;
		res.SD += Tree[v].SD;
		v >>= 1;
	}
	return res;
}

void dfs(int v, int p) {
	pre[v] = ++licznik;
	lvl[v] = lvl[p] + 1;
	for (auto u : G[v])
		if (u != p)
			dfs(u, v);
	post[v] = ++licznik;
}

inline void zastosuj(zap z) {
	Tupdate(pre[z.v], post[z.v], z.x - lvl[z.v]*z.d, z.d); 
}

ll query(int v) {
	pll res = Tquery(pre[v]);
	return res.SD * lvl[v] + res.FR;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i=2; i<=n; i++) {
		int x; cin >> x;
		G[x].PB(i); G[i].PB(x);
	}
	dfs(1, 1);
	for (int i=1; i<=n; i++) {
		int x; cin >> x;
		posiada[x].PB(i);
	}
	for (int i=1; i<=m; i++)
		cin >> potrzebuje[i];
	int q; cin >> q;
	for (int i=1; i<=q; i++)
		cin >> zapytania[i].v >> zapytania[i].x >> zapytania[i].d;
	
	for (int i=1; i<=m; i++)
		low[i] = 1, high[i] = q+1;
	
	bool flag = true;
	while (flag) {
		flag = false;
		for (int i=0; i<2*base; i++)
			Tree[i] = {0LL, 0LL};
		for (int i=1; i<=m; i++)
			if (low[i] < high[i])
				midpoint[(low[i] + high[i]) >> 1].PB(i);
		for (int i=1; i<=q; i++) {
			zastosuj(zapytania[i]);
			while (!midpoint[i].empty()) {
				flag = true;
				int kto = midpoint[i].back();
				midpoint[i].pop_back();
				ll suma = 0LL;
				for (auto v : posiada[kto]) {
					suma += query(v);
					if (suma >= potrzebuje[kto])
						break;
				}
				if (suma >= potrzebuje[kto]) high[kto] = i;
				else low[kto] = i+1;
			}
		}
	}
	for (int i=1; i<=m; i++) {
		if (low[i] > q) cout << "rekt\n";
		else cout << low[i] << "\n";
	}
	
	// double mem = (double)(sizeof(G) + sizeof(posiada) + sizeof(midpoint) + sizeof(pre) + sizeof(post) + sizeof(lvl) + sizeof(low) + sizeof(high) + sizeof(potrzebuje) + sizeof(zapytania) + sizeof(Tree)) / (double)(1<<20);
	// cout << mem << "\n";

	return 0;
}
