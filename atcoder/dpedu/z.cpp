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

struct line {
	ll a = 0, b = 1e18+7;
	ll f(ll x) {
		return a*x + b;
	}
};
constexpr int base = (1<<20);
constexpr int MxN = 2e5+5;
ll h[MxN], dp[MxN];
line Tree[2*base];

// Lee Chao Tree
void update(int v, int st, int ed, line l) {
	int md = (st + ed) >> 1;
	bool left = l.f(st) < Tree[v].f(st);
	bool mid = l.f(md) < Tree[v].f(md);
	if (mid) swap(l, Tree[v]);
	if (st == ed) return;
	if (left != mid) update(2*v, st, md, l);
	else             update(2*v+1, md+1, ed, l);
}

ll query(int v, int st, int ed, int x) {
	ll res = Tree[v].f(x);
	int md = (st + ed) >> 1;
	if (st == ed) return res;
	if (x <= md) return min(res, query(2*v, st, md, x));
	else return min(res, query(2*v+1, md+1, ed, x));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	ll C; cin >> C;
	for (int i=1; i<=n; i++)
		cin >> h[i];

	dp[1] = 0LL;
	line l = {-2*h[1], h[1]*h[1]};
	update(1, 1, base-1, l);
	for (int i=2; i<=n; i++) {
		ll mi = query(1, 1, base-1, h[i]);
		dp[i] = C + h[i]*h[i] + mi;
		l = {-2*h[i], h[i]*h[i] + dp[i]};
		update(1, 1, base-1, l);
	}
	cout << dp[n] << "\n";

	return 0;
}
