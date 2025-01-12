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
constexpr int base = (1<<18);
int h[MxN], wart[MxN];
ll Tree[2*base];
map<int, int> mp;

void update(int v, ll x) {
	v += base;
	Tree[v] = x;
	while (v) {
		v >>= 1;
		Tree[v] = max(Tree[2*v], Tree[2*v+1]);
	}
}

ll query(int a, int b) {
	ll res = 0LL;
	a += base - 1;
	b += base + 1;
	while ((a>>1) != (b>>1)) {
		if ((a&1) == 0) res = max(res, Tree[a+1]);
		if ((b&1) == 1) res = max(res, Tree[b-1]);
		a >>= 1; b >>= 1;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> h[i];
		mp[h[i]]++;
	}
	for (int i=1; i<=n; i++)
		cin >> wart[i];
	int licznik = 1;
	for (auto &it : mp)
		it.SD = licznik++;
	for (int i=1; i<=n; i++) {
		h[i] = mp[h[i]];
		ll wynik = wart[i] + query(1, h[i]-1);
		update(h[i], wynik);
	}
	cout << query(1, n) << "\n";

	return 0;
}
