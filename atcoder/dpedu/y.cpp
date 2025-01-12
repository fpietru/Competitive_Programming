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

constexpr int MxW = 2e5+5;
constexpr int MxN = 3e3+3;
constexpr int MOD = 1e9+7;
int dp[MxN]; // dp[i] = na ile sposobów mogę z (1, 1) przejść do punktu i-tego, tak, że nie przechodzę przez żaden inny punkt "zablokowany"
int f[MxW], odw[MxW];
pii p[MxN];

inline int mult(int a, int b) {
	return (1LL * a * b) % MOD;
}

inline int odejm(int a, int b) {
	return (a - b + MOD) % MOD;
}

int fastpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b&1) res = mult(res, a);
		a = mult(a, a);
		b >>= 1;
	}
	return res;
}

int dwumian(int a, int b) {
	int res = f[a];
	res = mult(res, odw[b]);
	res = mult(res, odw[a-b]);
	return res;
}

inline int ilesciezek(pii a, pii b) {
	return dwumian(b.FR-a.FR + b.SD-a.SD, b.FR-a.FR);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	f[0] = 1;
	for (int i=1; i<MxW; i++)
		f[i] = mult(f[i-1], i);
	odw[MxW-1] = fastpow(f[MxW-1], MOD-2);
	for (int i=MxW-2; i>=0; i--)
		odw[i] = mult(odw[i+1], i+1);

	int h, w, n; cin >> h >> w >> n;
	for (int i=1; i<=n; i++) {
		cin >> p[i].FR >> p[i].SD;
	}
	p[n+1] = {h, w};
	sort(p+1, p+n+2, [&](pii a, pii b) { return a.FR + a.SD <= b.FR + b.SD; });

	for (int i=1; i<=n+1; i++) {
		int wyn = ilesciezek({1,1}, p[i]);
		for (int j=1; j<i; j++)
			if (p[j].FR <= p[i].FR && p[j].SD <= p[i].SD)
				wyn = odejm(wyn, mult(dp[j], ilesciezek(p[j], p[i])));
		dp[i] = wyn;
	}
	cout << dp[n+1] << "\n";

	return 0;
}
