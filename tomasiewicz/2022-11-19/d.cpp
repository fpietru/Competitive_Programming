/*
	Link: https://codeforces.com/contest/916/problem/E
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
constexpr int base = (1<<18);
constexpr int LOG = 17;
vector<int> G[MxN];
ll wart[MxN], Tree[2*base], Lazy[2*base];
int pre[MxN], post[MxN], jump[MxN][LOG+1], lvl[MxN];
int licznik, root;

inline void lazypush(int v) {
	if (Lazy[v]) {
		Tree[2*v] += (Lazy[v] >> 1);
		Tree[2*v+1] += (Lazy[v] >> 1);
		Lazy[2*v] += (Lazy[v] >> 1);
		Lazy[2*v+1] += (Lazy[v] >> 1);
		Lazy[v] = 0LL;
	}
}

void update(int v, int st, int ed, int L, int R, ll val) {
	if (ed < L || st > R) return;
	else if (L <= st && ed <= R) {
		Tree[v] += (ed-st+1)*val;
		Lazy[v] += (ed-st+1)*val;	
	}
	else {
		lazypush(v);
		int md = (st + ed) >> 1;
		update(2*v, st, md, L, R, val);
		update(2*v+1, md+1, ed, L, R, val);
		Tree[v] = Tree[2*v] + Tree[2*v+1];
	}
}

ll query(int v, int st, int ed, int L, int R) {
	if (ed < L || st > R) return 0LL;
	else if (L <= st && ed <= R) return Tree[v];
	else {
		lazypush(v);
		int md = (st + ed) >> 1;
		ll lson = query(2*v, st, md, L, R);
		ll rson = query(2*v+1, md+1, ed, L, R);
		return lson + rson;
	}
}

void dfs(int v, int p) {
	pre[v] = ++licznik;
	lvl[v] = lvl[p] + 1;
	jump[v][0] = p;
	for (auto u : G[v])
		if (u != p) dfs(u, v);
	post[v] = ++licznik;
}

int lca(int a, int b) {
	if (lvl[a] < lvl[b]) swap(a, b);
	for (int i=LOG; i>=0; i--)
		if (lvl[a] - (1<<i) >= lvl[b])
			a = jump[a][i];
	if (a == b) return a;
	for (int i=LOG; i>=0; i--)
		if (jump[a][i] != jump[b][i])
			a = jump[a][i], b = jump[b][i];
	return jump[a][0];
}

inline bool wpoddrzewie(int a, int b) {
	return (pre[a] < pre[b] && post[b] < post[a]);
}

ll suma(int v) {
	if (v == root) 
		return (query(1, 0, base-1, pre[1], post[1]) >> 1);
	else if (wpoddrzewie(v, root) == false)
		return (query(1, 0, base-1, pre[v], post[v]) >> 1);
	else
	{
		int r = root;
		for (int i=LOG; i>=0; i--)
			if ((lvl[r] - (1<<i)) > lvl[v])
				r = jump[r][i];
		ll w1 = query(1, 0, base-1, pre[1], post[1]) >> 1;
		ll wr = query(1, 0, base-1, pre[r], post[r]) >> 1;
		return w1 - wr;
	}
}


void dodaj(int a, int b, ll val) {
	int l = lca(a, b) ^ lca(a, root) ^ lca(b, root);
	if (l == root)
		update(1, 0, base-1, pre[1], post[1], val);
	else if (wpoddrzewie(l, root) == false)
		update(1, 0, base-1, pre[l], post[l], val);
	else {
		int r = root;
		for (int i=LOG; i>=0; i--)
			if ((lvl[r] - (1<<i)) > lvl[l])
				r = jump[r][i];
		update(1, 0, base-1, pre[1], post[1], val);
		update(1, 0, base-1, pre[r], post[r], -val);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, q; cin >> n >> q;
	for (int i=1; i<=n; i++) cin >> wart[i];
	for (int i=1; i<=n-1; i++) {
		int a, b; cin >> a >> b;
		G[a].PB(b); G[b].PB(a);
	}
	dfs(1, 1);
	for (int k=1; k<=LOG; k++)
		for (int i=1; i<=n; i++)
			jump[i][k] = jump[jump[i][k-1]][k-1];

	for (int i=1; i<=n; i++) {
		update(1, 0, base-1, pre[i], pre[i], wart[i]);
		update(1, 0, base-1, post[i], post[i], wart[i]);
	}
	
	root = 1;
	while (q--) {
		int op; cin >> op;
		if (op == 1) {
			int v; cin >> v;
			root = v;
		}
		else if (op == 2) {
			int a, b; cin >> a >> b;
			ll x; cin >> x;
			dodaj(a, b, x);
		}
		else {
			int v; cin >> v;
			cout << suma(v) << "\n";
		}
	}

	return 0;
}
