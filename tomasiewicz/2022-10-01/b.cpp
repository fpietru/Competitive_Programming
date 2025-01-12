/*
	Link: https://atcoder.jp/contests/agc023/tasks/agc023_c
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

constexpr int MxN = 1e6+6;
constexpr int MOD = 1e9+7;
ll silnia[MxN];
ll odw[MxN];
ll ile[MxN];

ll fastpow(ll a, ll b) {
	ll res = 1LL;
	while (b) {
		if (b&1) res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

ll newton(int n, int k) {
	ll res = silnia[n];
	res = (res * odw[n-k]) % MOD;
	res = (res * odw[k]) % MOD;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	silnia[0] = 1LL;
	for (ll i=1; i<=n; i++)
		silnia[i] = (silnia[i-1] * i) % MOD;
	odw[n] = fastpow(silnia[n], MOD-2);
	for (ll i=n-1; i>=0; i--)
		odw[i] = (odw[i+1] * (i+1)) % MOD;	
	int li = (n + 1) / 2;
	for (int k=li; k<=n-1; k++) {
		ile[k] = newton(k-1, n-k-1);
		ile[k] = (ile[k] * silnia[k]) % MOD;
		ile[k] = (ile[k] * silnia[n-k-1]) % MOD;
	}
	ll ans = 0LL;
	for (int k=1; k<=n-1; k++)
		ans = (ans + k * ((ile[k]-ile[k-1]+MOD) % MOD)) % MOD;
	cout << ans << "\n";

	return 0;
}
