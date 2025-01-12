/*
	Link: https://codeforces.com/contest/1295/problem/E
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

constexpr int MxN = 2e5+5;
constexpr int base = (1<<19);
constexpr ll INF = 1e18+7;
ll tab[MxN], pos[MxN], koszt[MxN], p[MxN];
ll Tree[2*base], Lazy[2*base];

inline void lazypush(int v) {
	if (Lazy[v]) {
		Tree[2*v] += Lazy[v];
		Tree[2*v+1] += Lazy[v];
		Lazy[2*v] += Lazy[v];
		Lazy[2*v+1] += Lazy[v];
		Lazy[v] = 0LL;
	}
}

void update(int v, int st, int ed, int L, int R, ll val) {
	if (ed < L || st > R) return;
	else if (L <= st && ed <= R) {
		Tree[v] += val;
		Lazy[v] += val;
	}
	else {
		lazypush(v);
		int md = (st + ed) >> 1;
		update(2*v, st, md, L, R, val);
		update(2*v+1, md+1, ed, L, R, val);
		Tree[v] = min(Tree[2*v], Tree[2*v+1]);
	}
}

ll query(int v, int st, int ed, int L, int R) {
	if (ed < L || st > R) return INF;
	else if (L <= st && ed <= R) return Tree[v];
	else {
		lazypush(v);
		int md = (st + ed) >> 1;
		ll lson = query(2*v, st, md, L, R);
		ll rson = query(2*v+1, md+1, ed, L, R);
		return min(lson, rson);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> tab[i];
		pos[tab[i]] = i;
	}
	for (int i=1; i<=n; i++)
		cin >> koszt[tab[i]];
			
	for (int i=0; i<2*base; i++)
		Tree[i] = INF;

	p[0] = 0LL;
	for (int i=1; i<=n; i++) {
		p[i] = p[i-1] + koszt[tab[i]];
		update(1, 0, base-1, i, i, p[i] - INF);
	}
	
	// for (int i=1; i<=n; i++) cout << query(1, 0, base-1, i, i) << (i==n ? "\n" : " ");
	ll ans = query(1, 0, base-1, 1, n);
	for (int i=1; i<=n; i++) {
		if (pos[i] > 1) update(1, 0, base-1, 1, pos[i]-1, koszt[i]);
		update(1, 0, base-1, pos[i], n, -koszt[i]);
		// for (int j=1; j<=n; j++) cout << query(1, 0, base-1, j, j) << (j==n ? "\n" : " ");
		ans = min(ans, query(1, 0, base-1, 1, n-1));
	}
	cout << ans << "\n";

	return 0;
}
