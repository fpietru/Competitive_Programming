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

// drzewo przedziałowe (+, max) lazy

constexpr int MxN = 2e5+5;
constexpr int base = (1<<18);
constexpr ll INF = 1e18+7;
ll Tree[2*base], Lazy[2*base];
vector<pii> todo[MxN];
ll dodaj[MxN];

void lazypush(int v) {
	if (Lazy[v] == 0) return;
	Tree[2*v] += Lazy[v];
	Lazy[2*v] += Lazy[v];
	Tree[2*v+1] += Lazy[v];
	Lazy[2*v+1] += Lazy[v];
	Lazy[v] = 0;
}

void update(int v, int st, int ed, int L, int R, ll x) {
	if (R < st || ed < L) return;
	else if (L <= st && ed <= R) {
		Tree[v] += x;
		Lazy[v] += x;
	}
	else {
		lazypush(v);
		int md = (st + ed) >> 1;
		update(2*v, st, md, L, R, x);
		update(2*v+1, md+1, ed, L, R, x);
		Tree[v] = max(Tree[2*v], Tree[2*v+1]);
	}
}

ll query(int v, int st, int ed, int L, int R) {
	if (R < st || ed < L) return -INF;
	else if (L <= st && ed <= R) return Tree[v];
	else {
		lazypush(v);
		int md = (st + ed) >> 1;
		ll lson = query(2*v, st, md, L, R);
		ll rson = query(2*v+1, md+1, ed, L, R);
		return max(lson, rson);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int l, r; cin >> l >> r;
		ll x; cin >> x;
		dodaj[l] += x;
		todo[r+1].PB({x, l});
	}
	for (int i=1; i<=n+1; i++) {
		update(1, 0, base-1, 0, i-1, dodaj[i]);
		for (auto p : todo[i])
			update(1, 0, base-1, 0, p.SD-1, -1LL*p.FR);
		ll wyn = query(1, 0, base-1, 0, i-1);
		update(1, 0, base-1, i, i, wyn);
	}
	cout << query(1, 0, base-1, 0, n) << "\n";

	return 0;
}
