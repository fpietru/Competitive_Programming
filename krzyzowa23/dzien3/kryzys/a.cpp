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


inline int lb(int x) {
	return (31 - __builtin_clz(x));
}

inline int sgn(int x, int p) {
	return (x&(1<<p));
}

struct G {
	int T[31] = {0};
	void push(int x) {
		while (x && T[lb(x)])
			x ^= T[lb(x)];
		if (x != 0)
			T[lb(x)] = x;
	}
	void clear() {
		memset(T, 0, sizeof(T));
	}
	void show() {
		for (int i=30; i>=0; i--)
			cout << i << " " << T[i] << "\n";
	}
	int getmax() {
		int res = 0;
		for (int i=30; i>=0; i--)
			if (sgn(res, i) == 0 && T[i])
				res ^= T[i];
		return res;
	}
	bool find(int x) {
		int res = 0;
		for (int i=30; i>=0; i--)
			if (sgn(x, i) != sgn(res, i))
				res ^= T[i];
		return (res == x);
	}
};
constexpr int base = (1<<19);
G Tree[2*base];
int Lazy[2*base];

G merge(G a, G b) {
	G res;
	for (int i=30; i>=0; i--) {
		if (a.T[i]) res.push(a.T[i]);
		if (b.T[i]) res.push(b.T[i]);
	}
	return res;
}

void lazypush(int v) {
	if (!Lazy[v]) return;
	Tree[2*v].clear();
	Tree[2*v].push(Lazy[v]);
	Lazy[2*v] = Lazy[v];
	Tree[2*v+1].clear();
	Tree[2*v+1].push(Lazy[v]);
	Lazy[2*v+1] = Lazy[v];
	Lazy[v] = 0;
}

void update(int v, int st, int ed, int L, int R, int x) {
	if (R < st || ed < L) return;
	else if (L <= st && ed <= R) {
		Tree[v].clear();
		Tree[v].push(x);
		Lazy[v] = x;
	}
	else {
		lazypush(v);
		int md = (st + ed) >> 1;
		update(2*v, st, md, L, R, x);
		update(2*v+1, md+1, ed, L, R, x);
		Tree[v] = merge(Tree[2*v], Tree[2*v+1]);
	}
}

G query(int v, int st, int ed, int L, int R) {
	G res;
	if (R < st || ed < L) return res;
	else if (L <= st && ed <= R) {
		res = Tree[v];
	}
	else {
		lazypush(v);
		int md = (st + ed) >> 1;
		G lson = query(2*v, st, md, L, R);
		G rson = query(2*v+1, md+1, ed, L, R);
		res = merge(lson, rson);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);	

	int n, q; cin >> n >> q;
	for (int i=1; i<=n; i++) {
		int x; cin >> x;
		update(1, 0, base-1, i, i, x);
	}
	
	while (q--) {
		string op; cin >> op;
		if (op == "aktualizacja") {
			int a, b, c; cin >> a >> b >> c;
			update(1, 0, base-1, a, b, c);
		}
		else if (op == "maksymalizacja") {
			int a, b; cin >> a >> b;
			cout << query(1, 0, base-1, a, b).getmax() << "\n";
		}
		else {
			int a, b, c; cin >> a >> b >> c;
			cout << (query(1, 0, base-1, a, b).find(c) ? "TAK\n" : "NIE\n");
		}
	}

	return 0;
}
